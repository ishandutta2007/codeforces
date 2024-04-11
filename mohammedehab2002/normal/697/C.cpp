#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
map <pair<ll,ll>,ll> m;
int log2(ll n)
{
	int cnt=0;
	while (n)
	n>>=1,cnt++;
	return cnt;
}
ll lca(ll u,ll v)
{
	while (u!=v)
	{
		if (log2(u)<log2(v))
		swap(u,v);
		u/=2;
	}
	return u;
}
int main()
{
	int q;
	cin >> q;
	for (int i=0;i<q;i++)
	{
		int type;
		ll u,v,w;
		cin >> type;
		if (type==1)
		{
			cin >> u >> v >> w;
			ll a=lca(u,v);
			while (u!=a)
			{
				m[make_pair(u,u/2)]+=w;
				u/=2;
			}
			while (v!=a)
			{
				m[make_pair(v,v/2)]+=w;
				v/=2;
			}
		}
		else
		{
			ll ans=0;
			cin >> u >> v;
			ll a=lca(u,v);
			while (u!=a)
			{
				ans+=m[make_pair(u,u/2)];
				u/=2;
			}
			while (v!=a)
			{
				ans+=m[make_pair(v,v/2)];
				v/=2;
			}
			cout << ans << endl;
		}
	}
}