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

inline int rt2(const LL &x) { int tmp = sqrt(x) + 2; while ((LL)tmp * tmp > x) --tmp; return tmp; }

const int max0 = 1000000, max1 = 500000;

LL l, r;

LL val[max0 + 5];
int N, sqrtn;

LL n;

inline int get_id(const LL &x) { return x > sqrtn ? N - (n / x) : x - 1; }

int rtp[max0 + 5];
LL cnt[max0 + 5];

int cntp[max1 + 5];

bool isp[max1 + 5];
int pr[max1 + 5];
int pn = 0;

int lim0, lim1;
int lim2[max0 + 5];

inline void prepare()
{
	memset(val, 0, sizeof val);
	memset(isp, 1, sizeof isp);
	isp[1] = 0;
	pn = 0;
	for (int i = 2; i <= max1; ++i)
	{
		if (isp[i])
		{
			pr[pn++] = i;
			for (int j = i; j <= max1; j += i) isp[j] = 0;
		}
		cntp[i] = pn;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	prepare();
	scanf("%I64d", &n);
	sqrtn = rt2(n);
	N = 0;
	for (LL i = 1; i <= n; i = n / val[N++] + 1) val[N] = n / i;
	reverse(val, val + N);
	int now = 0;
	lim0 = sqrtn, lim1 = cntp[lim0];
	REP(i, 0, N) rtp[i] = cntp[rt2(val[i])], lim2[i] = cntp[min((LL)lim0, val[i])];
	REP(i, 0, N) cnt[i] = val[i];
	REP(i, 0, lim1)
	{
		while (now < N && i >= rtp[now]) ++now;
		for (int j = N - 1; j >= now; --j)
		{
			int k = get_id(val[j] / pr[i]);
			cnt[j] -= cnt[k] - max(0, i - rtp[k]);
		}
	}
	REP(i, 0, N) cnt[i] -= max(0, lim2[i] - rtp[i]);
	LL ret = 0;
	REP(i, 0, lim1) if ((LL)pr[i] * pr[i] * pr[i] <= n) ++ret; else break;
	REP(i, 0, lim1) 
	{
		ret += (cnt[get_id(n / pr[i])] - 1); 
		ret += lim1 - i - 1;
	}
	printf("%I64d\n", ret);
	return 0;
}