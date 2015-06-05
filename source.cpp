#include<iostream>
using namespace std;
int main()
{
	//此处默认最多有24个节点
	const char point[26]={'A','B','C','D','E','F','G','H','I','J','k','L','M','N','O','P','Q','R',
   'S','T','U','V','W','X','Y','Z'};
	int n;
	cout<<"请输入节点数量："<<endl;
	cin>>n;
	bool flag[26];
	for(int i=0;i<n;i++)
		flag[n]=true;
	//创建一个n*n的二维数组，以记录节点之间的连接
	//0表示无连接，1表示弱连接，2表示强连接
	int node[26][26];
	for(int i=0;i<n;i++)
		node[i][i]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			cout<<"请输入节点"<<point[i]<<"和节点"<<point[j]<<"的关系，0表示无连接"
				   <<",1表示弱连接，2表示强连接"<<endl;
			cin>>node[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			node[i][j]=node[j][i];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(node[i][j]==2)
			{
				for(int k=j+1;k<n;k++)
				{
					if(node[i][k]==2)
					{
						if(node[j][k]==0)
							flag[i]=false;
					}
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(flag[i])
			cout<<"节点"<<point[i]<<"满足强三元闭包性质"<<endl;
		else
			cout<<"节点"<<point[i]<<"违反强三元闭包性质"<<endl;
	}
	system("pause");
	return 0;
}
