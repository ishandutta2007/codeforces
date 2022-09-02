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

const int Mod = 1e6 + 3;

inline int fpm(LL b, LL e, int m)
{
	b %= m;
	LL t = 1;
	for ( ; e; e >>= 1, (b *= b) %= m)
		if (e & 1) (t *= b) %= m;
	return t;
}

LL n, K;

int val[(Mod << 1) + 5];

inline int calc(int from, const LL &x)
{
	val[0] = 1;
	REP(i, 0, Mod << 1)
	{
		val[i + 1] = val[i];
		if (i & 1) val[i + 1] = (LL)val[i + 1] * (from - i) % Mod;
	}
	return (LL)fpm(val[Mod << 1], x / (Mod << 1), Mod) * val[x % (Mod << 1)] % Mod;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n >> K;
	if (n <= 60 && K > 1LL << n)
	{
		puts("1 1");
		return 0;
	}
	int tmp = (n % (Mod - 1)) * ((K - 1) % (Mod - 1)) % (Mod - 1);
	int num = 1;
	while (K > 1)
	{
		(tmp -= ((K - 1) >> 1) % (Mod - 1)) %= Mod - 1;
		num = (LL)num * calc(fpm(2, n, Mod), K) % Mod;
		--n;
		K = (K + 1) >> 1;
	}
	(tmp += Mod - 1) %= Mod - 1;
	int dom = fpm(2, tmp, Mod);
	num = (dom - num) % Mod; 
	(num += Mod) %= Mod;
	printf("%d %d\n", num, dom);
	return 0;
}