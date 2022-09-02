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

int n, p, q, r;
int a[maxn + 5];
LL pre[maxn + 5], suf[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d%d", &n, &p, &q, &r);
	REP(i, 0, n) scanf("%d", a + i);
	pre[0] = LLONG_MIN;
	REP(i, 0, n) pre[i + 1] = max(pre[i], (LL)a[i] * p);
	suf[n] = LLONG_MIN;
	for (int i = n - 1; i >= 0; --i) suf[i] = max(suf[i + 1], (LL)a[i] * r);
	LL ans = LLONG_MIN;
	REP(i, 0, n) if (pre[i + 1] != LLONG_MIN && suf[i] != LLONG_MIN) chkmax(ans, pre[i + 1] + (LL)a[i] * q + suf[i]);
	cout << ans << endl;
	return 0;
}