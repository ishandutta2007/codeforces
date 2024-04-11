#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 300100;

int n;
int a[maxn + 5];
bool ok[maxn + 5];
bool vis[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		REP(i, 0, n) ok[i] = vis[i] = 0;
		vector<int> v;
		REP(i, 0, n) scanf("%d", a + i), --a[i], v.pb(a[i]);
		sort(ALL(v));
		v.resize(unique(ALL(v)) - v.begin());
		REP(i, 0, n) a[i] = lower_bound(ALL(v), a[i]) - v.begin();
		int m = SZ(v);
		REP(i, 0, m - 1) ok[i] = 1;
		REP(i, 0, n)
		{
			if (vis[a[i] + 1]) ok[a[i]] = 0;
			vis[a[i]] = 1;
		}
		int best = 0;
		int cur = 0;
		REP(i, 0, m - 1)
			if (!ok[i]) cur = 0;
			else chkmax(best, ++cur);
		printf("%d\n", m - (best + 1));
	}
	return 0;
}