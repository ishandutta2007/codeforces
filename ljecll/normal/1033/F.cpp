/*
_____
.'     '.
/  0   0  \
|     ^     |
|  \     /  |
\  '---'  /
'._____.'
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

struct chash
{
	int operator()(int x) const
	{
		x ^= (x >> 20) ^ (x >> 12);
		return x ^ (x >> 7) ^ (x >> 4);
	}
};

template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename U> using hashtable = gp_hash_table<T, U, chash>;
random_device(rd);
mt19937 rng(rd());

template<class T>
void readi(T &x)
{
	T input = 0;
	bool negative = false;
	char c = ' ';
	while (c < '-')
	{
		c = getchar();
	}
	if (c == '-')
	{
		negative = true;
		c = getchar();
	}
	while (c >= '0')
	{
		input = input * 10 + (c - '0');
		c = getchar();
	}
	if (negative)
	{
		input = -input;
	}
	x = input;
}
template<class T>
void printi(T output)
{
	if (output == 0)
	{
		putchar('0');
		return;
	}
	if (output < 0)
	{
		putchar('-');
		output = -output;
	}
	int aout[20];
	int ilen = 0;
	while(output)
	{
		aout[ilen] = ((output % 10));
		output /= 10;
		ilen++;
	}
	for (int i = ilen - 1; i >= 0; i--)
	{
		putchar(aout[i] + '0');
	}
	return;
}
template<class T>
void ckmin(T &a, T b)
{
	a = min(a, b);
}
template<class T>
void ckmax(T &a, T b)
{
	a = max(a, b);
}
long long expo(long long a, long long e, long long mod)
{
	return ((e == 0) ? 1 : ((expo(a * a % mod, e >> 1, mod)) * ((e & 1) ? a : 1) % mod));
}
template<class T, class U>
T nmod(T &x, U mod)
{
	if (x >= mod) x -= mod;
}
template<class T>
T gcd(T a, T b)
{
	return (b ? gcd(b, a % b) : a);
}
template<class T>
T randomize(T mod)
{
	return (uniform_int_distribution<T>(0, mod - 1))(rng);
}

#define y0 ___y0
#define y1 ___y1
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second
#define debug(x) cerr << #x << " = " << x << endl;
#define sz(x) ((int) (x.size()))

const long double PI = 4.0 * atan(1.0);
const long double EPS = 1e-10;

#define MAGIC 347
#define SINF 10007
#define CO 1000007
#define INF 1000000007
#define BIG 1000000931
#define LARGE 1696969696967ll
#define GIANT 2564008813937411ll
#define LLINF 2696969696969696969ll
#define MAXN 50013
#define MAXW 13

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef vector<ll> poly;

int W, N, Q;
int freq[(1 << MAXW)], conv[(1 << MAXW)];
int pw3[MAXW];
int ans;

namespace NTT
{
	poly roots;
	const ll MOD = (119 << 23) + 1, root = 3;
	void poly_debug(poly f, int d)
	{
		for (int i = d; i >= 0; i--)
		{
			cerr << "(" << f[i] << ")x^" << i;
			if (i)
			{
				cerr << '+';
			}
			else
			{
				cerr << endl;
			}
		}
		return;
	}
	void init(int deg)
	{
		roots.resize(deg);
		roots[0] = 1;
		roots[1] = expo(root, (MOD - 1) / deg, MOD);
		for (int i = 2; i < deg; i++)
		{
			roots[i] = (roots[i - 1] * roots[1]) % MOD;
		}
	}
	poly ntt(poly f)
	{
		int deg = sz(f);
		poly g(deg);
		for (int i = deg / 2; i > 0; i /= 2)
		{
			for (int j = 0; j < i; j++)
			{
				for (int k = 0; k < deg; k += i)
				{
					int t = ((2 * k >= deg) ? (2 * k - deg) : (2 * k)) + j;
					g[k + j] = (f[t] + roots[k] * f[t + i]) % MOD;
				}
			}
			swap(f, g);
		}
		return f;
	}
	poly ntt_rev(poly f)
	{
		int deg = sz(f);
		f = ntt(f);
		ll isz = expo(deg, MOD - 2, MOD);
		for (int i = 0; i < deg; i++)
		{
			f[i] *= isz; f[i] %= MOD;
		}
		reverse(f.begin() + 1, f.end());
		return f;
	}
	poly poly_mult(poly f, poly g)
	{
		int deg = (sz(f) + sz(g) - 1), deg1 = (1 << (32 - __builtin_clz(deg)));
		poly res(deg1);
		if (deg <= 100)
		{
			for (int i = 0; i < sz(f); i++)
			{
				for (int j = 0; j < sz(g); j++)
				{
					res[i + j] += f[i] * g[j];
					res[i + j] %= MOD;
				}
			}
		}
		else
		{
			init(deg1);
			f.resize(deg1); g.resize(deg1);
			f = ntt(f);
			g = ntt(g);
			for (int i = 0; i < deg1; i++)
			{
				res[i] = f[i] * g[i] % MOD;
			}
			res = ntt_rev(res);
		}
		res.resize(deg);
		return res;
	}
	poly getpow(poly f, int e)
	{
		int deg = (e * sz(f) - e + 1), deg1 = (1 << (32 - __builtin_clz(deg)));
		poly res(deg1);
		init(deg1);
		f.resize(deg1);
		f = ntt(f);
		for (int i = 0; i < deg1; i++)
		{
			res[i] = expo(f[i], e, MOD);
		}
		res = ntt_rev(res);
		res.resize(deg);
		return res;
	}
}

using namespace NTT;

int ha(char c)
{
	if (c == 'A') return 0;
	if (c == 'O') return 1;
	if (c == 'X') return 2;
	if (c == 'a') return 3;
	if (c == 'o') return 4;
	if (c == 'x') return 5;
}
int qid[MAXW];
poly P;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	// cout << fixed << setprecision(10);
	// cerr << fixed << setprecision(10);
	// freopen ("file.in", "r", stdin);
	// freopen ("file.out", "w", stdout);
	cin >> W >> N >> Q;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		freq[x]++;
	}
	pw3[0] = 1;
	for (int i = 1; i <= W; i++)
	{
		pw3[i] = pw3[i - 1] * 3;
	}
	P.resize(pw3[W]);
	for (int i = 0; i < (1 << W); i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (!(i & (1 << j)))
			{
				continue;
			}
			conv[i] += pw3[j];
		}
		// if (freq[i]) cerr << i << ' ' << freq[i] << ' ' << conv[i] << endl;
		P[conv[i]] = freq[i];
		// cerr << "yep " << conv[i] << ' ' << freq[i] << ' ' << P[conv[i]] << endl;
	}
	// poly_(P, 81);
	P = getpow(P, 2);
	// P = poly_mult(P, P);
	while(Q--)
	{
		ans = 0;
		string temps;
		cin >> temps;
		for (int i = 0; i < W; i++)
		{
			qid[i] = ha(temps[i]);
		}
		vector<int> v, res;
		v.PB(0);
		for (int i = 0; i < W; i++)
		{
			int op = qid[i];
			for (int x : v)
			{
				if (op == 0)
				{
					res.PB(3 * x + 0);
					res.PB(3 * x + 1);
				}
				if (op == 1)
				{
					res.PB(3 * x + 0);
				}
				if (op == 2)
				{
					res.PB(3 * x + 0);
					res.PB(3 * x + 2);
				}
				if (op == 3)
				{
					res.PB(3 * x + 2);
				}
				if (op == 4)
				{
					res.PB(3 * x + 1);
					res.PB(3 * x + 2);
				}
				if (op == 5)
				{
					res.PB(3 * x + 1);
				}
			}
			v = res;
			res.clear();
		}
		for (int x : v)
		{
			ans += P[x];
		}
		// cerr << endl;
		cout << ans << '\n';
	}
	// cerr << "time elapsed = " << (clock() / (CLOCKS_PER_SEC / 1000)) << " ms" << endl;
	return 0;
}