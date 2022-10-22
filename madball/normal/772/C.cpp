#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <random>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int LIM = 200500;
const int INF = 1e+9 + 7;
const ld EPS = 1e-7;

#ifdef LOCAL
//#define STRESS
#endif

ll chain[LIM];
ll inverse(ll n, ll mod)
{
	ll num = mod;
	ll den = n;
	ll i = 0;
	while (den > 0)
	{
		chain[i++] = num / den;
		num %= den;
		swap(num, den);
	}
	bool neg = i % 2 == 0;
	--i;
	while (i > 0)
	{
		swap(num, den);
		num += den * chain[--i];
	}
	return (neg ? mod - num : num) % mod;
}

ll gcd(ll x, ll y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}

vector<ll> pingas[LIM];

ll jump(ll from, ll to, ll mod)
{
	ll fg = gcd(from, mod);
	ll tg = gcd(to, mod);
	ll g = gcd(fg, tg);
	if (tg % fg)
		throw;
	ll res = tg / fg;
	res = (((res * (to / tg)) % mod) * inverse(from / fg, mod / g)) % mod;
	return res;
}

vector<ll> path;
unordered_set<ll> forbidden;

void doit(vector<ll> &done, ll m)
{
	ll cur = 1;
	for (ll i = 0; i < path.size(); ++i)
	{
		ll g = path[i];
		for (int j = 0; j < pingas[g].size(); ++j)
		{
			ll to = pingas[g][j];
			ll ju = jump(cur, to, m);
			done.push_back(ju);
			if ((cur * ju) % m != to)
				throw;
			cur = to;
		}
	}
}

const ll max_size = 2e5 + 5;
ll best_low_divisor[max_size];
void recover_path(ll m) {
    while (m >= 1) {
        path.push_back(m);
        m = best_low_divisor[m];
    }
}

ll cnt[max_size];
ll dp[max_size];
bool watched[max_size];
 
ll calc_dp(ll number) {
	if (number == 4)
		number = 4;
    if (watched[number])
        return dp[number];
	watched[number] = true;
    ll result = 0;
    ll parent = -1;
    for (ll i = 1; i * i <= number; i++) {
        if (number % i != 0)
            continue;
        ll divisor = i;
        ll current_result = calc_dp(divisor);
        if (current_result > result) {
            parent = divisor;
            result = current_result;
        }
        divisor = number / i;
        if (divisor == i || divisor == number)
            continue;
        current_result = calc_dp(divisor);
        if (current_result > result) {
            parent = divisor;
            result = current_result;
        }
    }
    best_low_divisor[number] = parent;
    return dp[number] = result + cnt[number];
}

vector<ll> ans;

void solve()
{
    ll n, m;
    scanf("%lld %lld", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        ll a;
        scanf("%lld", &a);
        forbidden.insert(a);
    }
	if (forbidden.count(0) == 0)
		pingas[0].push_back(0);
    cnt[0] = cnt[m] = 1;
    for (int i = 1; i < m; i++) {
		ll g = gcd(i, m);
		if (forbidden.count(i) == 0)
		{
			pingas[g].push_back(i);
			cnt[g]++;
		}
    }
    dp[1] = cnt[1];
    watched[1] = true;
    best_low_divisor[1] = -1;
    ll answer = calc_dp(m);
    recover_path(m);
	path[0] = 0;
	reverse(path.begin(), path.end());
	doit(ans, m);
	printf("%d\n", (int)ans.size());
	for (int i = 0; i < ans.size(); ++i)
		printf("%lld ", ans[i]);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	solve();
	return 0;
}