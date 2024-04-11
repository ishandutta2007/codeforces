#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define div WTF
const int maxn = 1e4 + 20;
vector<ll> d , div[maxn] , ans;
map<ll , ll> ind;
void solve(ll x , ll k)
{
	if(ans.size() > 1e5)
		return;
	if(x == 1 || !k)
	{
		ans.pb(x);
		return;
	}
	for(auto a : div[ind[x]])
	{
		solve(a , k - 1);
		if(ans.size() > 1e5)
			return;
	}
}
int main()
{
	ll x , k;
	cin >> x >> k;
	if(k > 1e5 && x != 1)
	{
		for(int i = 0; i < 1e5; i++)
			cout << "1 ";
		return 0;
	}
	for(ll i = 1; i * i <= x; i++)
	{
		if(x % i == 0)
		{
			d.pb(i);
			if(x != i * i)
				d.pb(x / i);
		}
	}
	sort(d.begin() , d.end());
	for(int i = 0; i < d.size(); i++)
	{
		ind[d[i]] = i;
		for(int j = i; j < d.size(); j++)
			if(d[j] % d[i] == 0)
				div[j].pb(d[i]);
	}
	solve(x , k);
	for(int i = 0; i < min(100000 , (int)ans.size()); i++)
		cout << ans[i] << " ";
}