#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,k,x,y,ans,pa[333333],val[333333],sz[333333],num[333333],gan[333333];
char s[333333];
vector<int> v[333333];
int root(int x)
{
	if (pa[x]==x) return x;
	int rt=root(pa[x]);
	if (pa[x]!=rt) val[x]^=val[pa[x]];
	return pa[x]=rt;
}
int calc(int x)
{
	if (gan[x]) return num[x];
	return min(num[x],sz[x]-num[x]);
}
void upd(int x,int f)
{
	int rx=root(x);
	ans-=calc(rx);
	gan[rx]++;
	int vx=(x==rx ? val[rx] : val[x]^val[rx]);
	if (vx==f)
	{
		ans+=calc(rx);
		return;
	}
	val[rx]^=1;num[rx]=sz[rx]-num[rx];
	ans+=calc(rx);
}
void Union(int x,int y,int f)
{
	int rx=root(x),ry=root(y);
	if (rx==ry) return;
	ans-=calc(rx),ans-=calc(ry);
	if (gan[rx]) 
	{
		swap(rx,ry);
		swap(x,y);
	}
	int vx=(rx==x ? val[rx] : val[x]^val[rx]),vy=(ry==y ? val[ry] : val[y]^val[ry]);
	if (vx^vy!=f^val[ry]) 
	{
		val[rx]^=1;
		num[rx]=sz[rx]-num[rx];
	}
	if (val[ry])
	{
		num[rx]=sz[rx]-num[rx];
	}
	pa[rx]=ry;
	num[ry]+=num[rx];sz[ry]+=sz[rx];gan[ry]+=gan[rx];
	ans+=calc(ry);
}
int main()
{
	scanf("%d%d",&n,&k);
	scanf("%s",s);
	for (int i=1;i<=k;i++)
	{
		scanf("%d",&x);
		for (int j=1;j<=x;j++)
		{
			scanf("%d",&y);
			v[y].push_back(i);
		}
	}
	for (int i=1;i<=k;i++)
	{
		pa[i]=i;
		sz[i]=1;val[i]=0;
		num[i]=0;gan[i]=0;
	}
	for (int i=1;i<=n;i++)
	{
		if (v[i].empty())
		{
			printf("%d\n",ans);
			continue;
		}
		if (v[i].size()==1)
		{
			x=v[i][0];
			if (s[i-1]=='0') upd(x,1);
			else upd(x,0);
		}
		else
		{
			x=v[i][0];y=v[i][1];
			if (s[i-1]=='1')
			{
				Union(x,y,0);
			}
			else 
			{
				Union(x,y,1);
			}
		}
		printf("%d\n",ans);
	}
	return Accepted;
}