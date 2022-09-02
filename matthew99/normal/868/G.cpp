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

const int inv2 = (Mod + 1) >> 1;

inline int fpm(LL b, int e, int m)
{
	b %= m;
	LL t = 1;
	for ( ; e; e >>= 1, (b *= b) %= m)
		if (e & 1) (t *= b) %= m;
	return t;
}

struct data
{
	int x, y;
	int sumx, sumy;

	data() { }
	data(int _x, int _y, int _sumx, int _sumy): x(_x), y(_y), sumx(_sumx), sumy(_sumy) { }

};

inline data combine(const data &x, const data &y)
{
	return data((LL)y.x * x.x % Mod, ((LL)y.x * x.y + y.y) % Mod, (x.sumx + (LL)y.sumx * x.x) % Mod, (x.sumy + (LL)y.sumx * x.y + y.sumy) % Mod);
}

inline data &subtract(data &x, const data &y)
{
	(x.y -= y.y) %= Mod;
	x.x = (LL)x.x * fpm(y.x, Mod - 2, Mod) % Mod;
	x.y = (LL)x.y * fpm(y.x, Mod - 2, Mod) % Mod;
	x.sumx = (x.sumx - (LL)y.sumx * x.x) % Mod;
	x.sumy = (x.sumy - (LL)y.sumx * x.y - y.sumy) % Mod;
	return x;
}

inline data get_pw(data b, int e)
{
	data t = data(1, 0, 0, 0);
	for ( ; e; e >>= 1, b = combine(b, b))
	{
		if (e & 1) t = combine(t, b);
	}
	return t;
}

inline data work(int n, int K, const data &a, const data &b, bool rev = 0)
{
	if (!(n % K))
	{
		if (rev) return combine(b, get_pw(a, n / K - 1));
		return combine(get_pw(a, n / K - 1), b);
	}
	if (!rev)
	{
		return work(K, n % K, combine(get_pw(a, n / K - 1), b), combine(get_pw(a, n / K), b), 1);
	}
	data tmp = combine(b, work(K, n % K, combine(get_pw(a, n / K - 1), b), combine(get_pw(a, n / K), b), 0));
	return subtract(tmp, b);
}

int n, K;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &K);
		int d = __gcd(n, K);
		n /= d, K /= d;
		data ret = work(n, K, data(1, 1, 1, 0), data(inv2, 1, 1, 0));
		int tmp = (LL)ret.y * fpm(1 - ret.x, Mod - 2, Mod) % Mod;
		int ans = ((LL)ret.sumx * tmp + ret.sumy) % Mod;
		(ans += Mod) %= Mod;
		ans = (LL)ans * fpm(n, Mod - 2, Mod) % Mod;
		printf("%d\n", ans);
	}
	return 0;
}