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

const int Mod = 1e9 + 7;

const int maxn = 1000100;

int fac[maxn + 5];

inline void prepare()
{
	fac[0] = 1;
	REP(i, 0, maxn) fac[i + 1] = (LL)fac[i] * (i + 1) % Mod;
}

int n;
int a[maxn + 5];

bool notpr[maxn + 5];
int res[maxn + 5];

int ker[maxn + 5];
int bel[maxn + 5], cnt[maxn + 5], val[maxn + 5];
bool vis[maxn + 5];

inline int calc()
{
	REP(i, 1, n + 1) res[i] = i, ker[i] = 1;
	memset(notpr, 0, sizeof notpr);
	int ret = 1;
	for (int i = 2; i * i <= n; ++i) if (!notpr[i]) 
		for (int j = i; j <= n; j += i) 
		{
			ker[j] *= i;
			notpr[j] = 1;
			while (!(res[j] % i)) res[j] /= i;
		}
	REP(i, 1, n + 1) if (a[i] && ker[i] != ker[a[i]]) return 0;
	REP(i, 1, n + 1) ker[i] *= res[i];
	memset(cnt, 0, sizeof cnt);
	REP(i, 1, n + 1) ++cnt[ker[i]];
	REP(i, 1, n + 1) if (a[i]) --cnt[ker[i]];
	REP(i, 2, n + 1) ret = (LL)ret * fac[cnt[i]] % Mod;
	memset(bel, -1, sizeof bel);
	memset(cnt, 0, sizeof cnt);
	memset(vis, 0, sizeof vis);
	bel[1] = 1;
	REP(i, 2, n + 1) if (!notpr[i]) bel[i] = n / i;
	REP(i, 1, n + 1) if (~bel[i]) ++cnt[bel[i]];
	memset(val, -1, sizeof val);
	REP(i, 1, n + 1) if (a[i])
	{
		if (bel[res[i]] != bel[res[a[i]]]) return 0;
		if (i == 1 || res[i] > 1)
		{
			if (~val[res[i]]) 
			{
				if (val[res[i]] != res[a[i]]) return 0;
			}
			else
			{
				if (vis[res[a[i]]]) return 0;
				val[res[i]] = res[a[i]];
				vis[res[a[i]]] = 1;
				--cnt[bel[res[a[i]]]];
			}
		}
	}
	REP(i, 1, n + 1) ret = (LL)ret * fac[cnt[i]] % Mod;
	return ret;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	prepare();
	scanf("%d", &n);
	REP(i, 1, n + 1) scanf("%d", a + i);
	printf("%d\n", calc());
	return 0;
}