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
#define MAXN 200013

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

int N;
int arr[MAXN];
vi factors[MAXN];
vpl diffs[MAXN];
vl ans;

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
	cin >> N; N /= 2;
	FOR(i, 0, N)
	{
		cin >> arr[i];
		if (arr[i] % 4 == 2)
		{
			cout << "No\n";
			return 0;
		}
	}
	for (int i = 1; i < MAXN; i++)
	{
		for (int j = i; j < MAXN; j += i)
		{
			factors[j].PB(i);
		}
	}
	FOR(i, 1, MAXN)
	{
		for (ll x : factors[i])
		{
			ll rem = i / x;
			if (x >= rem || (x + rem) % 2)
			{
				continue;
			}
			ll mid = (x + rem) / 2, diff = (x - rem) / 2;
			diffs[i].PB({diff * diff, mid * mid});
		}
		reverse(ALL(diffs[i]));
	}
	ll sum = 0;
	FOR(i, 0, N)
	{
		ll val = arr[i], res;
		//sum, sum + x, sum + x + val
		//keep it small
		int p = LB(ALL(diffs[val]), MP(sum + 1, -LLINF)) - diffs[val].begin();
		if (p >= SZ(diffs[val]))
		{
			cout << "No\n";
			return 0;
		}
		// cerr << diffs[val][p].fi << ' ' << diffs[val][p].se << endl;
		res = diffs[val][p].fi - sum;
		ans.PB(res);
		ans.PB(val);
		sum += res; sum += val;
	}
	cout << "Yes\n";
	for (ll x : ans)
	{
		cout << x << ' ';
	}
	cout << '\n';
	//can't you just factor all these guys and then
	// cerr << "time elapsed = " << (clock() / (CLOCKS_PER_SEC / 1000)) << " ms" << endl;
	return 0;
}
/* READ READ READ
* int overflow, maxn too small, special cases (n=1?, two distinct?), cin.tie() interactive
* reread the problem, try small cases
* do smth instead of nothing
*/