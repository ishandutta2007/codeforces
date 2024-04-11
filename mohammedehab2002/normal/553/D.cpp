#include <bits/stdc++.h>
using namespace std;
bool nok[100005];
int nom[100005],deg[100005],delt[100005];
vector<int> v[100005];
struct frac
{
	int a,b;
	frac(int a,int b):a(a),b(b){}
	bool operator<(const frac &f) const
	{
		return 1LL*a*f.b<1LL*b*f.a;
	}
};
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	while (k--)
	{
		int a;
		scanf("%d",&a);
		nok[a]=1;
	}
	while (m--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		deg[a]++;
		deg[b]++;
		if (nok[a] || nok[b])
		continue;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	set<pair<frac,int> > s;
	for (int i=1;i<=n;i++)
	{
		if (!nok[i])
		{
			nom[i]=v[i].size();
			s.insert({frac(nom[i],deg[i]),i});
		}
	}
	pair<frac,int> ans(frac(0,1),0);
	int ct=1;
	while (!s.empty())
	{
		auto p=*s.begin();
		s.erase(s.begin());
		nom[p.second]=-1;
		ans=max(ans,make_pair(p.first,ct));
		delt[p.second]=ct++;
		for (int u:v[p.second])
		{
			if (nom[u]!=-1)
			{
				s.erase({frac(nom[u],deg[u]),u});
				nom[u]--;
				s.insert({frac(nom[u],deg[u]),u});
			}
		}
	}
	printf("%d\n",ct-ans.second);
	for (int i=1;i<=n;i++)
	{
		if (delt[i]>=ans.second)
		printf("%d ",i);
	}
}