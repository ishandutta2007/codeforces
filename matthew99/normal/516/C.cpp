#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <cctype>
#include <cassert>
#include <ctime>
#include <climits>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;

const int maxn = 100000, max0 = 18;

int n, m;
LL sum[(maxn << 1) + 5], sum0[(maxn << 1) + 5]; 
int d[(maxn << 1) + 5], h[(maxn << 1) + 5];
int Max[(maxn << 1) + 5][max0], Max0[(maxn << 1) + 5][max0];
int Log[(maxn << 1) + 5];

inline bool cmp(const int &x, const int &y)
{
	return sum[x] < sum[y];
}

inline bool cmp0(const int &x, const int &y)
{
	return sum0[x] < sum0[y];
}

int query(const int &u, const int &v)
{
	if (v - u <= 0) return n;
	int tmp = Log[v - u];
	return max(Max[u][tmp], Max[v - (1 << tmp)][tmp], cmp);
}

int query0(const int &u, const int &v)
{
	if (v - u <= 0) return n;
	int tmp = Log[v - u];
	return max(Max0[u][tmp], Max0[v - (1 << tmp)][tmp], cmp0);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, n) scanf("%d", d + i), d[i + n] = d[i];
	REP(i, 0, n) scanf("%d", h + i), h[i + n] = h[i] <<= 1;
	n <<= 1;
	sum[0] = sum0[0] = 0;
	REP(i, 0, n) sum[i + 1] = sum[i] + d[i];
	REP(i, 0, n) sum0[i] = h[i] - sum[i], sum[i] += h[i];
	REP(i, 0, n) Max[i][0] = i, Max0[i][0] = i;
	sum[n] = sum0[n] = LLONG_MIN;
	REP(j, 1, max0)
	{
		REP(i, 0, n)
			if (i + (1 << (j - 1)) < n) Max[i][j] = max(Max[i][j - 1], Max[i + (1 << (j - 1))][j - 1], cmp), Max0[i][j] = max(Max0[i][j - 1], Max0[i + (1 << (j - 1))][j - 1], cmp0);
			else Max[i][j] = Max[i][j - 1], Max0[i][j] = Max0[i][j - 1];
	}
	REP(i, 1, n + 1)
	{
		int cnt = 0, x = i;
		while (x) ++cnt, x >>= 1;
		Log[i] = cnt - 1;
	}
	REP(i, 0, m)
	{
		static int u, v;
		scanf("%d%d", &v, &u), --u, --v;
		if (v <= u) v += n >> 1;
		++u;
		int a = query(u, v), b = query0(u, v);
		if (a != b) printf("%I64d\n", sum[a] + sum0[b]);
		else
		{
			LL ans = 0;
			int c = max(query(u, a), query(a + 1, v), cmp);
			int d = max(query0(u, b), query0(b + 1, v), cmp0);
			ans = max(ans, sum[c] + sum0[b]);
			ans = max(ans, sum[a] + sum0[d]);
			printf("%I64d\n", ans);
		}
	}
	return 0;
}