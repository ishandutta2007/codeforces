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

const int maxn = 100100;

int n;
int a[maxn + 5], b[maxn + 5];

LL sum[maxn + 5];
LL sumx[maxn + 5], sumy[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i);
	REP(i, 0, n) scanf("%d", b + i);
	sum[0] = 0;
	REP(i, 0, n) sum[i + 1] = sum[i] + b[i];
	REP(i, 0, n)
	{
		++sumx[i];
		int l = i, r = n;
		while (l < r)
		{
			int mid = (l + r + 1) >> 1;
			if (sum[mid] - sum[i] <= a[i]) l = mid;
			else r = mid - 1;
		}
		--sumx[l];
		sumy[l] += a[i] - (sum[l] - sum[i]);
	}
	REP(i, 0, n)
	{
		sumx[i + 1] += sumx[i];
	}
	REP(i, 0, n)
	{
		printf("%" LLFORMAT "d ", sumx[i] * b[i] + sumy[i]);
	}
	return 0;
}