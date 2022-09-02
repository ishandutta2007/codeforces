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

#define ctz __builtin_ctzll
#define bcnt __builtin_popcountll

#ifdef __WIN32
#define LLFORMAT "I64"
#define Rand() ((rand() << 15) | rand())
#else
#define LLFORMAT "ll"
#define Rand() (rand())
#endif

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 300100;
const int max0 = 140;

int n;
int a[maxn + 5];

int val[maxn + 5];
int suma[maxn + 5];
int sum[2][maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n)
	{
		LL x;
		scanf("%" LLFORMAT "d", &x);
		a[i] = bcnt(x);
	}
	sum[0][0] = 0;
	sum[1][0] = 0;
	REP(i, 0, n)
	{
		sum[0][i + 1] = sum[0][i] + !(suma[i] & 1);
		sum[1][i + 1] = sum[1][i] + (suma[i] & 1);
		suma[i + 1] = suma[i] + a[i];
		val[i] = suma[i] & 1;
	}
	val[n] = suma[n] & 1;
	LL ans = 0;
	REP(i, 0, n)
	{
		int Max = 0;
		int lim = max(0, i - max0);
		for (int j = i; j >= lim; --j)
		{
			chkmax(Max, a[j]);
			if (val[j] == val[i + 1] && suma[i + 1] - suma[j] >= Max * 2)
			{
				++ans;
			}
		}
		ans += sum[val[i + 1]][lim];
	}
	cout << ans << endl;
	return 0;
}