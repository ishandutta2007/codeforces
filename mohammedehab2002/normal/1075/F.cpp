#include <iostream>
#include <map>
using namespace std;
map<int,int> m;
pair<int,int> par[400005];
pair<int,int> find(pair<int,int> x)
{
	if (par[x.first].first!=x.first)
	{
		auto tmp=find(par[x.first]);
		tmp.second^=par[x.first].second;
		par[x.first]=tmp;
	}
	return par[x.first];
}
void Union(int a,int b,int x)
{
	pair<int,int> aa=find({a,0}),bb=find({b,0});
	if (aa.first!=bb.first)
	par[aa.first]={bb.first,(x^aa.second^bb.second)};
}
int main()
{
	int q,cn=0;
	scanf("%d",&q);
	int ans=0;
	while (q--)
	{
		int t,l,r;
		scanf("%d%d%d",&t,&l,&r);
		l^=ans;
		r^=ans;
		if (l>r)
		swap(l,r);
		l--;
		if (!m[l])
		{
			m[l]=++cn;
			l=m[l];
			par[l]={l,0};
		}
		else
		l=m[l];
		if (!m[r])
		{
			m[r]=++cn;
			r=m[r];
			par[r]={r,0};
		}
		else
		r=m[r];
		if (t==1)
		{
			int x;
			scanf("%d",&x);
			x^=ans;
			Union(l,r,x);
		}
		else
		{
			auto p1=find({l,0}),p2=find({r,0});
			if (p1.first!=p2.first)
			{
				printf("-1\n");
				ans=1;
			}
			else
			{
				ans=(p1.second^p2.second);
				printf("%d\n",ans);
			}
		}
	}
}