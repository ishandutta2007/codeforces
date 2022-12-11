/*
PROG: cf821b
LANG: C++
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

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

ll M, B;
ll ans = 0ll;

ll f(ll x)
{
	ll res = x/M;
	res *= -1;
	if (x % M)
	{
		res--;
	}
	res += B;
	return res;
}
ll sum(ll x)
{
	return x * (x + 1)/2;
}
ll test(ll x)
{
	ll y = f(x);
	if (y < 0)
	{
		return -1;
	}
	return sum(x) * (y + 1) +  sum(y) * (x + 1);
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	if (fopen("cf821b.in", "r"))
	{	
		freopen ("cf821b.in", "r", stdin);
		freopen ("cf821b.out", "w", stdout);
	}
	//intersects at (0, B) and (BM, 0)
	cin >> M >> B;
	for (int i = 0; i <= 10000000; i++)
	{
		ans = max(ans, test(i));
	}
	cout << ans << '\n';
	return 0;
}