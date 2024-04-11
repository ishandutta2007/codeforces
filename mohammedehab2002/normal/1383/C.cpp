#include <bits/stdc++.h>
using namespace std;
char aa[100005],bb[100005];
int out[20],par[20],comp;
bool dag[(1<<20)];
int find(int x)
{
	if (par[x]!=x)
	par[x]=find(par[x]);
	return par[x];
}
void Union(int x,int y)
{
	x=find(x);
	y=find(y);
	if (x!=y)
	{
		par[x]=y;
		comp++;
	}
}
void add(int a,int b)
{
	out[a]|=(1<<b);
	Union(a,b);
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n,ans=0;
		scanf("%d %s %s",&n,aa,bb);
		memset(out,0,sizeof(out));
		comp=0;
		for (int i=0;i<20;i++)
		par[i]=i;
		for (int i=0;i<n;i++)
		{
			if (aa[i]!=bb[i])
			add(aa[i]-'a',bb[i]-'a');
		}
		for (int i=0;i<(1<<20);i++)
		{
			dag[i]=!i;
			for (int j=0;j<20;j++)
			{
				if ((i&(1<<j)) && (out[j]&i)==0)
				dag[i]|=dag[i^(1<<j)];
			}
			if (dag[i])
			ans=max(ans,__builtin_popcount(i));
		}
		printf("%d\n",20-ans+comp);
	}
}