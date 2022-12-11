/*
:>
*/
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
#define fi first
#define se second
#define debug(x) cerr << #x << " = " << x << endl;
#define sz(x) ((int) (x.size()))

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
#define MAXN 300013
#define MAXA 11

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;

int N;
vector<int> arr;
bitset<MAXN> in;
int g;
set<int> nums[MAXA];
int ans = MAXA - 1;
int loc[MAXN];
vector<int> primes;
int sp[MAXN];
int cap[MAXN];

int clean(int x)
{
	int ret = 1;
	vector<int> res;
	while(x != 1)
	{
		int p = sp[x];
		x /= p;
		if (!res.empty() && p == res.back())
		{
			continue;
		}
		else
		{
			res.PB(p);
		}
	}
	for (int x : res) ret *= x;
	return ret;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	// cout << fixed << setprecision(10);
	// cerr << fixed << setprecision(10);
	// freopen ("file.in", "r", stdin);
	// freopen ("file.out", "w", stdout);
	for (ll i = 2; i < MAXN; i++)
	{
		if (sp[i] == 0)
		{
			sp[i] = i;
			primes.PB(i);
		}
		for (ll p : primes)
		{
			if (p > sp[i] || i * p >= MAXN)
			{
				break;
			}
			sp[i * p] = p;
		}
	}
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		if (x == 1)
		{
			cout << "1\n";
			return 0;
		}
		x = clean(x);
		in[x] = true;
		g = gcd(g, x);
	}
	if (g != 1)
	{
		cout << "-1\n";
		return 0;
	}
	nums[0].insert(0);
	for (int i = 0; i < MAXN; i++)
	{
		cap[i] = MAXA - 1;
	}
	for (int i = 2; i < MAXN; i++)
	{
		if (!in[i]) continue;
		for (int j = ans; j >= 0; j--)
		{
			for (int x : nums[j])
			{
				g = gcd(x, i);
				if (loc[g] <= j + 1 && loc[g] != 0) continue;
				if (loc[g] > j) nums[loc[g]].erase(g);
				if (cap[g] <= j) continue;
				loc[g] = j + 1;
				cap[g] = j;
				nums[j + 1].insert(g);
				if (g == 1) ckmin(ans, j + 1);
				for (int k = 2 * g; k < MAXN; k += g)
				{
					if (loc[k] >= j + 1)
					{
						nums[loc[k]].erase(k);
					}
					ckmin(cap[k], j);
				}
			}
		}
	}
	cout << ans << '\n';
	//say, you choose a 1
	// cerr << "time elapsed = " << (clock() / (CLOCKS_PER_SEC / 1000)) << " ms" << endl;
	return 0;
}