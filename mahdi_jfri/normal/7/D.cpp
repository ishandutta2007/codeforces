#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 5e6 + 20;
const ll mod = 1e9 + 7;
const ll prime = 3079;
ll h[maxn] , res[maxn] , sum , hs[maxn] , t[maxn];
ll get(ll l , ll r)
{
	ll k = hs[l] - hs[r + 1] * t[r - l + 1];
	k %= mod;
	return (k + 5 * mod) % mod;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	t[0] = 1;
	for(int i = 1; i < maxn; i++)
		t[i] = (t[i - 1] * prime) % mod;
	for(int i = 0; i < n; i++)
		h[i] = (h[i - 1] * prime + (ll)s[i]) % mod;
	for(int i = n - 1; i >= 0; i--)
		hs[i] = (hs[i + 1] * prime + (ll)s[i]) % mod;
	for(int i = 0; i < n; i++)
	{
		if(h[i] == get(0 , i))
			res[i] = res[(i + 1) / 2 - 1] + 1;
		sum += res[i];
	}
	cout << sum << endl;
}