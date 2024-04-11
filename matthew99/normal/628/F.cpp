#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define EXIT(...) printf(__VA_ARGS__), exit(0)

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxq = 10000;

int n, b, qn;
pair<int, int> q[maxq + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &b, &qn);
	REP(i, 0, qn) scanf("%d%d", &q[i].x, &q[i].y);
	q[qn++] = mp(b, n);
	sort(q, q + qn);
	REP(j, 0, qn - 1) if (q[j].y > q[j + 1].y) { puts("unfair"); return 0; }
	int per = n / 5;
	REP(i, 1, 1 << 5)
	{
		int res = __builtin_popcount(i) * per;
		int lst = 0;
		REP(j, 0, qn)
		{
			int now = 0;
			REP(k, 0, 5) if (i >> k & 1) now += (q[j].x - k + 5) / 5 - (k == 0);
			res -= min(now - lst, q[j].y - (j ? q[j - 1].y : 0));
			if (res <= 0) break;
			lst = now;
		}
		if (res > 0) { puts("unfair"); return 0; }
	}
	puts("fair");
	return 0;
}