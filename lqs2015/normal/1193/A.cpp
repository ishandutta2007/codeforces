#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,x,y,deg[22],msk,c;
map<int,int> mp[333333];
map<int,int>::iterator it;
void add(int &x,int y)
{
	x+=y;
	if (x>=mod) x-=mod;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		x--;y--;
		deg[x]|=(1<<y);
		deg[y]|=(1<<x);
	}
	mp[0][(1<<n)-1]=1;
	for (int i=0;i<(1<<n)-1;i++)
	{
		msk=(1<<n)-1-i;
		for (it=mp[i].begin();it!=mp[i].end();it++)
		{
			c=it->first;
			for (int j=0;j<n;j++)
			{
				if (c&(1<<j)) 
				{
					c^=(1<<j);
					add(mp[i|(1<<j)][(c|deg[j])&msk],it->second);
				}
			}
		}
	}
	printf("%d\n",1ll*mp[(1<<n)-1][0]*m%mod*(mod+1)/2%mod);
	return 0;
}