/*
PROG: cf822d
LANG: C++
    _____
  .'     '.
 /  0   0  \
|     ^     |
|  \     /  |
 \  '---'  /
  '._____.'
 */
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define MP make_pair
#define PB push_back

#define SINF 10001
#define INF 1000000007
#define MOD INF
#define LLINF 1000000000000000861ll
#define CO 1000861
#define EPS 0.000000000000001
#define PI 3.141592653589793
#define MAXN 5000010

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<ll> point;

ll T, L, R;
ll pw = 1;
ll ans;
ll dp[MAXN];
ll fact[MAXN];

ll f(ll a)
{
	if (fact[a] == LLINF)
	{
		return ((a * a - a)/2) % MOD;
	}
	if (dp[a] != -1)
	{
		return dp[a];
	}
	ll sf = fact[a];
	dp[a] = (f(a/sf) + a/sf * f(sf) % MOD) % MOD;
	return dp[a];
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	if (fopen("cf822d.in", "r"))
	{	
		freopen ("cf822d.in", "r", stdin);
		freopen ("cf822d.out", "w", stdout);
	}
	cin >> T >> L >> R;
	for (int i = 2; i < MAXN; i++)
	{
		fact[i] = LLINF;
	}
	for (ll i = 2; i < MAXN; i++)
	{
		if (fact[i] != LLINF)
		{
			continue;
		}
		for (ll j = i * i; j < MAXN; j += i)
		{
			fact[j] = min(fact[j], i);
		}
	}
	for (int i = 0; i < MAXN; i++)
	{
		dp[i] = -1;
	}
	for (ll i = L; i <= R; i++)
	{
		ans += f(i) * pw;
		pw *= T;
		pw %= MOD;
		ans %= MOD;
	}
	cout << ans << '\n';
	return 0;
}