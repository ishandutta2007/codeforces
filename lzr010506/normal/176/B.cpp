#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9 + 7;
string s, t;
int k, L;
ll p, q, n;
int main()
{
	cin >> s >> t >> k;
	if (k == 0)
	{
		if (s == t) puts("1");
		else puts("0");
		return 0;
	}
	L = s.size();
	s = s + s;
	for(int i = 0; i < L; i ++)
		if (s.substr(i, L) == t) n ++;
	ll p = 1, q = 0;
	for(int i = 1; i < k; i ++)
	{
		ll w = p * (L - 2) + q;
		w %= mod;
		q = p * (L - 1) % mod;
		p = w;
	}
	ll ans = 0;
	if (s.substr(0, L) == t) 
		ans = q + (n - 1) * p;
	else 
		ans = n * p % mod;
	ans %= mod;
	printf("%I64d\n",ans);
	return 0;
}