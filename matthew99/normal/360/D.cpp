#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <cctype>
#include <cassert>
#include <ctime>
#include <vector>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 1e4, max_num = 1e5;

int fpm(LL b, int e, const int &m)
{
	LL t = 1;
	for ( ; e; e >>= 1, (b *= b) %= m) if (e & 1) (t *= b) %= m;
	return t;
}

int gcd(int x, int y)
{
	while (y) y ^= x ^= y ^= x %= y;
	return x;
}

int n, m, p;
int a[maxn + 5];

int ans = 0;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &p);
	vector<int> all;
	for (int i = 1; i * i <= p - 1; ++i)
		if (!((p - 1) % i))
		{
			all.pb(i);
			if (i * i != p - 1) all.pb((p - 1) / i);
		}
	sort(ALL(all));
	REP(i, 0, n)
		scanf("%d", a + i);
	int yyt = p - 1;
	REP(i, 0, m)
	{
		static int x;
		scanf("%d", &x);
		yyt = gcd(yyt, x);
	}
	REP(i, 0, n) 
		REP(j, 0, SZ(all))
			if (fpm(a[i], (LL)all[j] * yyt % (p - 1), p) == 1)
			{
				a[i] = (p - 1) / all[j];
				break;
			}
	static int dp[max_num + 5];
	reverse(ALL(all));
	REP(i, 0, SZ(all))
	{
		bool flag = 0;
		REP(j, 0, n) if (!(all[i] % a[j])) { flag = 1; break; }
		if (!flag) continue;
		dp[i] = (p - 1) / all[i];
		REP(j, 0, i)
			if (!(all[j] % all[i])) dp[i] -= dp[j];
		ans += dp[i];
	}
	printf("%d\n", ans);
	return 0;
}