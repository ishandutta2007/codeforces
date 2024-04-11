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
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second
#define DBG(x) cerr << #x << " = " << x << endl
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
#define MAXN 100013

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

int N, M, K;
int quer[MAXN];
bitset<MAXN> special;
int arr[MAXN];
vector<pair<int, pii> > edge;
int dsu[MAXN], sz[MAXN];

int get(int u)
{
	return (u == dsu[u] ? u : dsu[u] = get(dsu[u]));
}
bool merge(int u, int v)
{
	u = get(u);
	v = get(v);
	if (u == v) return false;
	if (sz[u] < sz[v]) swap(u, v);
	dsu[v] = u;
	sz[u] += sz[v];
	sz[v] = 0;
	return true;
}
bool check(int x)
{
	// cerr << "Check " << x << endl;
	FOR(i, 0, N)
	{
		dsu[i] = i;
		sz[i] = 1;
	}
	FOR(i, 0, x)
	{
		int d = edge[i].fi, u = edge[i].se.fi, v = edge[i].se.se;
		merge(u, v);
		 // cerr << "merge " << u << ' ' << v << endl;
	}
	int need = 0;
	FOR(i, 0, N)
	{
		if (special[i])
		{
			need = get(i);
		}
	}
	FOR(i, 0, N)
	{
		if (special[i] && get(i) != get(need)) return false;
	}
	// cerr << "ok\n";
	return true;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	// cout << fixed << setprecision(10);
	// cerr << fixed << setprecision(10);
	// if (fopen("file.in", "r"))
	// {
	// 	freopen ("file.in", "r", stdin);
	// 	freopen ("file.out", "w", stdout);
	// }
	cin >> N >> M >> K;
	if (K == 1)
	{
		cout << "0\n";
		return 0;
	}
	FOR(i, 0, K)
	{
		int x; cin >> x; x--;
		special[x] = true;
	}
	FOR(i, 0, M)
	{
		int u, v, d;
		cin >> u >> v >> d; u--; v--;
		edge.PB({d, {u, v}});
	}
	sort(ALL(edge));
	// FOR(i, 0, M)
	// {
	// 	int d = edge[i].fi, u = edge[i].se.fi, v = edge[i].se.se;
	//
	// }
	int lo = 0, hi = M;
	while(hi > lo)
	{
		int mid = (hi + lo) >> 1;
		if (check(mid))
		{
			hi = mid;
		}
		else
		{
			lo = mid + 1;
		}
	}
	FOR(i, 0, K)
	{
		cout << edge[lo - 1].fi << ' ';
	}
	cout << '\n';
	//minimum spanning tree for all the special vertices!
	// cerr << "time elapsed = " << (clock() / (CLOCKS_PER_SEC / 1000)) << " ms" << endl;
	return 0;
}
/* READ READ READ
* int overflow, maxn too small, special cases (n=1?, two distinct?), cin.tie() interactive
* reread the problem, try small cases
* do smth instead of nothing
*/