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

const int maxn = 100;

const int maxabs = 1e9;

int n;
LL K;

int a[maxn + 5];

LL ans = 0;

inline bool check(int x)
{
	LL tmp = 0;
	REP(i, 0, n) tmp += (x - a[i] % x) % x;
	return tmp <= K;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n >> K;
	REP(i, 0, n) cin >> a[i];
	for (int i = 1; i < oo; )
	{
		LL tmp0 = 0, tmp1 = 0;
		REP(j, 0, n)
		{
			tmp0 += 1;
			tmp0 += a[j] / i;
			tmp1 += a[j];
		}

		LL lim = (K + tmp1) / tmp0;
		if (lim >= i) chkmax(ans, lim);

		int nxt = oo;
		REP(j, 0, n) if (i <= a[j])
		{
			chkmin(nxt, a[j] / (a[j] / i));
		}
		if (check(nxt)) chkmax(ans, (LL)nxt);
		i = nxt + 1;
	}
	cout << ans << endl;
	return 0;
}