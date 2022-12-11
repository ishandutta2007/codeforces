#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

random_device(rd);
mt19937 rng(rd());
const long long FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();

struct custom_hash
{
	template<class T>
	unsigned long long operator()(T v) const
	{
		unsigned long long x = v;
		x += FIXED_RANDOM; x += 11400714819323198485ull;
		x = (x ^ (x >> 30)) * 13787848793156543929ull;
		x = (x ^ (x >> 27)) * 10723151780598845931ull;
		return x ^ (x >> 31);
	}
};

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T, class U> using hash_table = gp_hash_table<T, U, custom_hash>;

template<class T>
void readi(T &x)
{
	x = 0;
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
		x = x * 10 + (c - '0');
		c = getchar();
	}
	if (negative)
	{
		x = -x;
	}
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
	int buf[20], n = 0;
	while(output)
	{
		buf[n] = ((output % 10));
		output /= 10;
		n++;
	}
	for (n--; n >= 0; n--)
	{
		putchar(buf[n] + '0');
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
void nmod(T &x, U mod)
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
#define PB push_back
#define fi first
#define se second
#define DBG(x) cerr << #x << " = " << x << endl;
#define SZ(x) ((int) (x.size()))
#define FOR(i, a, b) for (auto i = (a); i < (b); i++)
#define FORD(i, a, b) for (auto i = (a) - 1; i >= (b); i--)
#define ALL(x) x.begin(), x.end()

const long double PI = 4.0 * atan(1.0);
const long double EPS = 1e-9;

#define MAGIC 347
#define SINF 10007
#define CO 1000007
#define INF 1000000007
#define BIG 1000000931
#define LARGE 1696969696967ll
#define GIANT 2564008813937411ll
#define LLINF 2696969696969696969ll
#define MAXN 3000013

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef vector<pdd> vpd;

int N, M;
vector<int> S, T;
int ans;
int zero, one;
pll shash[MAXN], pw[MAXN];

pll srange(int L, int R)
{
	pll res;
	res.fi = (shash[R + 1].fi - shash[L].fi * pw[R - L + 1].fi); res.fi %= INF; res.fi += INF; res.fi %= INF;
	res.se = (shash[R + 1].se - shash[L].se * pw[R - L + 1].se); res.se %= BIG; res.se += BIG; res.se %= BIG;
	return res;
}
bool match(int a, int b, int c, int d)
{
	if (b - a != d - c) return false;
	return srange(a, b) == srange(c, d);
}
bool lol()
{
	if (M % N)
	{
		return false;
	}
	int len = M / N;
	// DBG(len);
	FOR(i, 0, N)
	{
		if (!match(i * len, ((i + 1) * len) - 1, 0, len - 1))
		{
			return false;
		}
	}
	// cerr << "loled\n";
	return true;
}
bool check(int x)
{
	//can 0...x be ok?
	ll rem = 1ll * M - 1ll * zero * x;
	if (rem % one || rem <= 0)
	{
		return false;
	}
	ll len = rem / one;
	pii range = MP(-1, -1);
	int ptr = 0;
	FOR(i, 0, N)
	{
		if (S[i] == 0)
		{
			if (!match(0, x - 1, ptr, ptr + x - 1))
			{
				return false;
			}
			ptr += x;
		}
		else
		{
			if (range == MP(-1, -1))
			{
				range = MP(ptr, ptr + len - 1);
				ptr += len;
				continue;
			}
			if (!match(range.fi, range.se, ptr, ptr + len - 1))
			{
				return false;
			}
			ptr += len;
		}
	}
	if (ptr != M) return false;
	return true;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	// cout << fixed << setprecision(10);
	// cerr << fixed << setprecision(10);
	// freopen ("file.in", "r", stdin);
	// freopen ("file.out", "w", stdout);
	string temps;
	cin >> temps;
	N = SZ(temps);
	FOR(i, 0, N)
	{
		S.PB(temps[i] - '0');
		if (S[i] == 0) zero++;
		else one++;
	}
	if (S[0] == 1)
	{
		FOR(i, 0, N)
		{
			S[i] ^= 1;
		}
		swap(zero, one);
	}
	cin >> temps;
	M = SZ(temps);
	FOR(i, 0, M)
	{
		T.PB(temps[i] - 'a' + 1);
	}
	if (zero == 0 || one == 0 || M < N)
	{
		cout << "0\n";
		return 0;
	}
	for (int i = 0; i < M; i++)
	{
		shash[i + 1].fi = shash[i].fi * CO + T[i]; shash[i + 1].fi %= INF;
		shash[i + 1].se = shash[i].se * CO + T[i]; shash[i + 1].se %= BIG;
	}
	pw[0] = MP(1, 1);
	for (int i = 0; i <= M + 2; i++)
	{
		pw[i + 1].fi = pw[i].fi * CO; pw[i + 1].fi %= INF;
		pw[i + 1].se = pw[i].se * CO; pw[i + 1].se %= BIG;
	}
	FOR(i, 1, M + 1)
	{
		if (check(i))
		{
			ans++;
		}
	}
	if (lol())
	{
		ans--;
	}
	cout << ans << '\n';
	// cerr << "time elapsed = " << (clock() / (CLOCKS_PER_SEC / 1000)) << " ms" << endl;
	return 0;
}