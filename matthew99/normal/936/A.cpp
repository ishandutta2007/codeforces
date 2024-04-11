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

LL K, d, t;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> K >> d >> t;
	LL cyc = ((K + d - 1) / d) * d;
	t <<= 1;
	LL p = K * 2 + cyc - K;
	LL need = (t / p);
	double ans = need * cyc;
	t -= need * p;
	if (t < K * 2) ans += (double)t / 2;
	else
	{
		ans += K;
		t -= K * 2;
		ans += t;
	}
	printf("%.15f\n", ans);
	return 0;
}