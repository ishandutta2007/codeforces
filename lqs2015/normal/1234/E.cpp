#include<bits/stdc++.h>
using namespace std;
int n,m,p[222222],gg[222222],x,y;
long long ans,res;
vector<int> v[222222];
void update(int x,int y)
{
	res-=abs(x-y);
	if (y<x) res+=y;
	else res+=(y-1);
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d",&p[i]);
		v[p[i]].push_back(i);
	}
	for (int i=1;i<m;i++)
	{
		ans+=abs(p[i]-p[i+1]);
		x=p[i];y=p[i+1];
		if (x>y) swap(x,y);
		if (x==y) continue;
		gg[x+1]++;gg[y]--;
	}
	for (int i=1;i<=n;i++) gg[i]+=gg[i-1];
	for (int i=1;i<=n;i++)
	{
		res=ans-gg[i];
		for (int j=0;j<v[i].size();j++)
		{
			int pos=v[i][j];
			if (pos>1 && p[pos-1]!=i)
			{
				update(i,p[pos-1]);
			}
			if (pos<m && p[pos+1]!=i)
			{
				update(i,p[pos+1]);
			}
		}
		printf("%lld ",res);
	}
	printf("\n");
	return 0;
}