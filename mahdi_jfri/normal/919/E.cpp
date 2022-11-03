#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define int ll

const int maxn = 1e6 + 20;
int mod;


vector<int> v[maxn];

int pw(int a , int b)
{
	if(!b)
		return 1;
	int x = pw(a , b / 2);
	x = 1LL * x * x % mod;

	if(b & 1)
		x = 1LL * x * a % mod;
	return x;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll a , b , x;
	cin >> a >> b >> mod >> x;

	for(int i = 0; i < mod - 1; i++)
		v[pw(a , i)].pb(i);

	vector<ll> ans;

	for(int i = 1; i < mod; i++)
	{
		int tmp = 1LL * b * pw(i , mod - 2) % mod;

		for(auto x : v[tmp])
		{
			ll k = (1LL * -i * (mod - 1) + 1LL * (x) * mod) % (1LL * mod * (mod - 1));
			if(k < 0)
				k += 1LL * mod * (mod - 1);
			ans.pb(k);
		}
	}

	sort(ans.begin() , ans.end());
	ans.resize(unique(ans.begin() , ans.end()) - ans.begin());

	ll res = 0;
	for(auto tmp : ans)
		if(tmp <= x)
			res += (x - tmp) / (1LL * mod * (mod - 1)) + 1;

	cout << res << endl;
}