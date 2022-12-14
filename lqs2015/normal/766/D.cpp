#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int n,m,q,pa[111111],sum[111111],tp,x,y;
string s,s1,s2;
map<string,int> mp;
int root(int x)
{
	if (pa[x]==x) return x;
	int rt=root(pa[x]);
	sum[x]^=sum[pa[x]];
	pa[x]=rt;
	return rt;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m>>q;
	for (int i=1;i<=n;i++)
	{
		cin>>s;
		mp[s]=i;
	}
	for (int i=1;i<=n;i++) pa[i]=i;
	for (int i=1;i<=m;i++)
	{
		cin>>tp>>s1>>s2;
		x=mp[s1];y=mp[s2];
		if (tp==1)
		{
			int rx=root(x),ry=root(y);
			if (rx==ry)
			{
				if (sum[x]!=sum[y]) printf("NO\n");
				else printf("YES\n");
			}
			else
			{
				printf("YES\n");
				pa[rx]=ry;
				sum[rx]=sum[x]^sum[y];
			}
		}
		else
		{
			int rx=root(x),ry=root(y);
			if (rx==ry)
			{
				if (sum[x]==sum[y]) printf("NO\n");
				else printf("YES\n");
			}
			else
			{
				printf("YES\n");
				pa[rx]=ry;
				sum[rx]=sum[x]^sum[y]^1;
			}
		}
	}
	for (int i=1;i<=q;i++)
	{
		cin>>s1>>s2;
		x=mp[s1];y=mp[s2];
		int rx=root(x),ry=root(y);
		if (rx!=ry) printf("3\n");
		else 
		{
			if (sum[x]==sum[y]) printf("1\n");
			else printf("2\n");
		}
	}
	return 0;
}