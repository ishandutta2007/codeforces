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

const int maxn = 40;

int n, L;
LL c[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &L);
	REP(i, 0, n) cin >> c[i];
	REP(i, n, 31) c[i] = LLONG_MAX;
	REP(i, 1, 31) chkmin(c[i], c[i - 1] << 1);
	LL ans = 0;
	REP(i, 0, 31)
		if (L >> i & 1) ans += c[i];
	REP(i, 1, 31) if (!(L >> i & 1))
	{
		LL tmp = c[i];
		REP(j, i + 1, 31) if (L >> j & 1) tmp += c[j];
		chkmin(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}