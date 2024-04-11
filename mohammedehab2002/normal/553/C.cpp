#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
pair<int,int> par[100005];
pair<int,int> find(int x)
{
	if (par[x].first!=x)
	{
		auto tmp=find(par[x].first);
		par[x]={tmp.first,(par[x].second^tmp.second)};
	}
	return par[x];
}
bool Union(int a,int b,int c)
{
	auto x=find(a),y=find(b);
	if (x.first==y.first)
	return (x.second^y.second!=c);
	par[x.first]={y.first,(x.second^y.second^c)};
	return 0;
}
int main()
{
	int n,m,ans=1;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	par[i]={i,0};
	while (m--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if (Union(a,b,!c))
		{
			printf("0");
			return 0;
		}
	}
	set<int> s;
	for (int i=1;i<=n;i++)
	s.insert(find(i).first);
	for (int i=1;i<s.size();i++)
	ans=(ans*2)%mod;
	printf("%d",ans);
}