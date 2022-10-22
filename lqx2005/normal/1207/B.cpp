#include<bits/stdc++.h>
using namespace std;
const int N=50;
int n,m;
int a[N+5][N+5],b[N+5][N+5];
vector<int> oa,ob;
void change(int i,int j)
{
	b[i][j]=b[i][j+1]=b[i+1][j]=b[i+1][j+1]=1;
	oa.push_back(i);
	ob.push_back(j);
	return;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	for(int i=1;i<=n-1;i++)
	{
		for(int j=1;j<=m-1;j++)
		{
			if(a[i][j]&&a[i][j+1]&&a[i+1][j]&&a[i+1][j+1]) change(i,j);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]!=b[i][j])
			{
				printf("-1\n");
				return 0;
			}
		}
	}
	printf("%d\n",(int)oa.size());
	for(int i=0;i<(int)oa.size();i++) printf("%d %d\n",oa[i],ob[i]);
	return 0;
}