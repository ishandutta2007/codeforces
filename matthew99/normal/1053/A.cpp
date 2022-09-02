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

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m, K;
	scanf("%d%d%d", &n, &m, &K);
	if (K & 1)
	{
		int x, y;
		x = n / __gcd(K, n);
		K /= __gcd(K, n);
		if (m % K) puts("NO");
		else
		{
			y = m / K;
			if (x * 2 <= n) x *= 2;
			else y *= 2;
			puts("YES");
			printf("0 0\n");
			printf("%d 0\n", x);
			printf("0 %d\n", y);
		}
	}
	else
	{
		K >>= 1;
		int x, y;
		x = n / __gcd(K, n);
		K /= __gcd(K, n);
		if (m % K) puts("NO");
		else
		{
			y = m / K;
			puts("YES");
			printf("0 0\n");
			printf("%d 0\n", x);
			printf("0 %d\n", y);
		}
	}
	return 0;
}