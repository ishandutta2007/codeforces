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

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int Mod = 1e9 + 7;

const int maxn = 4000000;

int n, K;
LL a[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &K);
	REP(i, 0, n) scanf("%I64d", a + i);
	vector<LL> opr;
	static pair<int, int> stk[maxn + 5];
	int tot = 0;
	for (int i = 0, j; i < n; i = j + 1)
	{
		j = i;
		while (j + 1 < n && a[j] <= a[j + 1]) ++j;
		int from = i, to = j;
		while (tot && a[stk[tot - 1].x] >= a[from]) --tot, opr.pb(a[stk[tot].y] - a[stk[tot].x]);
		while (tot && a[stk[tot - 1].y] <= a[to])
		{
			--tot;
			assert(a[stk[tot].y] >= a[from]);
			opr.pb(a[stk[tot].y] - a[from]);
			from = stk[tot].x;
		}
		stk[tot++] = mp(from, to);
	}
	while (tot) --tot, opr.pb(a[stk[tot].y] - a[stk[tot].x]);
	chkmin(K, SZ(opr));
	nth_element(opr.begin(), opr.begin() + K, opr.end(), greater<LL>());
	printf("%I64d\n", accumulate(opr.begin(), opr.begin() + K, 0LL));
	return 0;
}