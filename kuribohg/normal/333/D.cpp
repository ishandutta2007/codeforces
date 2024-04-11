#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int n,m,L,R,mid,a[2010][2010],c[2010][2010];
bool used[2010][2010];
vector<int> v;
bool check()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]>=mid) c[i][j]=1;
			else c[i][j]=0;
	for(int i=1;i<=m;i++)
		for(int j=i+1;j<=m;j++)
			used[i][j]=false;
	for(int i=1;i<=n;i++)
	{
		v.clear();
		for(int j=1;j<=m;j++)
			if(c[i][j]==1)
			{
				for(int k=0;k<v.size();k++)
				{
					if(used[v[k]][j]) return true;
					used[v[k]][j]=true;
				}
				v.push_back(j);
			}
	}
	return false;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	L=0,R=1000000000;
	while(L<R)
	{
		mid=(L+R+1)>>1;
		if(check()) L=mid;
		else R=mid-1;
	}
	printf("%d\n",L);
	return 0;
}