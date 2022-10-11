#include <bits/stdc++.h>
using namespace std;
int ans[200005];
map<pair<int,int>,pair<int,int> > m;
pair<int,int> query(int l,int r)
{
	if (m.count({l,r}))
	return m[{l,r}];
	printf("? %d %d\n",l,r);
	fflush(stdout);
	int x,f;
	scanf("%d%d",&x,&f);
	return m[{l,r}]={x,f};
}
void solve(int l,int r)
{
	auto p=query(l,r);
	int ll,rr;
	for (int i=l;i<=r;i+=p.second)
	{
		int ri=min(i+p.second-1,r);
		auto tmp=query(i,ri);
		if (tmp.first==p.first)
		{
			ll=ri-tmp.second+1;
			rr=ll+p.second-1;
			if (rr>r || query(ll,rr)!=p)
			{
				rr=i+tmp.second-1;
				ll=rr-p.second+1;
			}
			break;
		}
	}
	for (int i=ll;i<=rr;i++)
	ans[i]=p.first;
	if (l==ll)
	l=rr+1;
	for (int i=l;i<=r;)
	{
		int ri=min(i+p.second-1,r);
		if (i<ll)
		ri=min(ri,ll-1);
		solve(i,ri);
		if (ri==ll-1)
		i=rr+1;
		else
		i+=p.second;
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	solve(1,n);
	printf("! ");
	for (int i=1;i<=n;i++)
	printf("%d%c",ans[i]," \n"[i==n]);
	fflush(stdout);
}