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
#define MAXN 113

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

int TC;
int N;
ld C, T;
pair<int, ld> arr[MAXN];
int ans;
ld dp[MAXN][10 * MAXN][MAXN];
ld co = 10.0 / 9.0;

ld readd()
{
	string s;
	cin >> s;
	return stold(s);
}

bool cmp(pair<int, ld> a, pair<int, ld> b)
{
	return a.se > b.se;
}

ld f(ld m, ld t)
{
	return t + m / (1.0 + C * t);
}
ld minimize(ld m)
{
	//t + m/(1 + ct)
	ld opt = ((sqrt(C * m) - 1.0) / (C));
	ckmin(opt, T); ckmax(opt, (ld) 0.0);
	return f(m, opt);
	// ld lo = 0, hi = T;
	// FOR(i, 0, 100)
	// {
	// 	ld lt = (lo + lo + hi) / 3.0, rt = (lo + hi + hi) / 3.0;
	// 	ld fl = f(m, lt), fr = f(m, rt);
	// 	if (fl < fr) hi = rt;
	// 	else lo = lt;
	// }
	// cerr << opt << ' ' << lo << endl;
	// return lo;
	// return (lo + m / (1 + C * lo));
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);
	cerr << fixed << setprecision(10);
	// freopen ("file.in", "r", stdin);
	// freopen ("file.out", "w", stdout);
	cin >> TC;
	while(TC--)
	{
		ans = 0;
		cin >> N;
		C = readd(); T = readd();
		FOR(i, 0, N)
		{
			int x, y;
			cin >> x >> y;
			arr[i] = MP(y, x);
		}
		//first of all, you obviously want to save the ones with largest se to earlier!, otherwise, you want to solves one with larger score
		sort(arr, arr + N, cmp);
		// FOR(i, 0, N)
		// {
		// 	cerr << "score " << arr[i].fi << " cost " << arr[i].se << endl;
		// }
		//dp[i][j][k] = at position i, minimum modified needed to get j points given that you solvd k
		FOR(i, 0, MAXN)
		{
			FOR(j, 0, 10 * MAXN)
			{
				FOR(k, 0, MAXN)
				{
					dp[i][j][k] = LARGE;
				}
			}
		}
		dp[0][0][0] = 0;
		FOR(i, 0, N)
		{
			FOR(j, 0, 10 * N + 1)
			{
				ld pw = 1.0;
				FOR(k, 0, i + 1)
				{
					pw *= co;
					//solve it!
					ckmin(dp[i + 1][j + arr[i].fi][k + 1], dp[i][j][k] + pw * arr[i].se);
					//don't solve it!
					ckmin(dp[i + 1][j][k], dp[i][j][k]);
				}
			}
		}
		FOR(j, 0, 10 * N + 1)
		{
			FOR(k, 0, N + 1)
			{
				//you solved k problems taking a total of dp[N][j][k] time
				ld cc = 10.0 * k, m = dp[N][j][k];
				//if minimum of t + m / (1 + ct) is <= T we win!
				if (minimize(m) < T - cc + EPS)
				{
					ckmax(ans, j);
				}
			}
		}
		cout << ans << '\n';
	}
	// cerr << "time elapsed = " << (clock() / (CLOCKS_PER_SEC / 1000)) << " ms" << endl;
	return 0;
}