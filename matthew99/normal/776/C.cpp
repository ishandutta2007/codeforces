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

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 100100;

int n, K;
int a[maxn + 5];
LL sum[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &K);
	sum[0] = 0;
	REP(i, 0, n) scanf("%d", a + i), sum[i + 1] = sum[i] + a[i];
	LL now = 1;
	LL ans = 0;
	set<LL> all;
	while (abs(now) < 1e17 && !all.count(now))
	{
		all.insert(now);
		map<LL, int> cnt;
		REP(i, 0, n + 1)
		{
			++cnt[sum[i]];
			ans += cnt[sum[i] - now];
		}
		now *= K;
	}
	cout << ans << endl;
	return 0;
}