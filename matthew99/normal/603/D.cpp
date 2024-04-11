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
 
#ifdef __WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif
 
template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
 
typedef long long LL;
 
const int Mod = 1e9 + 7;
 
const int oo = 0x3f3f3f3f;
const LL OO = 0x3f3f3f3f3f3f3f3fLL;

template<typename T> inline T &Read(T &x)
{
	static char c;
	while (1) 
	{ 
		c = getchar(); 
		if (c == '-' || (c >= '0' && c <= '9')) break; 
	}
	bool flag = c == '-';
	x = flag ? 0 : c - '0';
	while (1)
	{
		c = getchar();
		if (c < '0' || c > '9') break;
		(x *= 10) += c - '0';
	}
	if (flag) x = -x;
	return x;
}

const int maxn = 2000;

int n;
int A[maxn + 5], B[maxn + 5], C[maxn + 5];
int X[maxn + 5], Y[maxn + 5], Z[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Read(n);
	REP(i, 0, n)
	{
		Read(A[i]);
		Read(B[i]);
		Read(C[i]);
		X[i] = A[i] * C[i];
		Y[i] = B[i] * C[i];
		Z[i] = A[i] * A[i] + B[i] * B[i];
	}
	int ans = 0;
	REP(i, 0, n)
	{
		int zero = 0;
		map<pair<LL, LL>, int> cnt;
		REP(j, 0, i)
		{
			LL u = (LL)X[i] * Z[j] - (LL)X[j] * Z[i];
			LL v = (LL)Y[i] * Z[j] - (LL)Y[j] * Z[i];
			LL d = __gcd(u, v);
			if (!u && !v)
			{
				ans += j;
				++zero;
			}
			else
			{
				u /= d, v /= d;
				if (u < 0) u = -u, v = -v;
				ans += cnt[mp(u, v)] + zero;
				++cnt[mp(u, v)];
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}