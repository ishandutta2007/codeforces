/*
    _____
  .'     '.
 /  0   0  \
|     ^     |
|  \     /  |
 \  '---'  /
  '._____.'
*/
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
#define INF 998244353
#define BIG 1000000931
#define LARGE 1696969696967ll
#define GIANT 2564008813937411ll
#define LLINF 2696969696969696969ll
#define MAXN 513

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;

int N;
ll arr[MAXN];
ll ans = 1;
bitset<MAXN> divided;


ll square_root(ll x)
{
	ll f = sqrt(x);
	for (ll m = f - 10; m <= f + 10; m++)
	{
		if (m >= 0 && m * m == x)
		{
			return m;
		}
	}
	return 0;
}
ll cube_root(ll x)
{
	if (x < 0) return 0;
	ll f = cbrt(x);
	for (ll m = f - 10; m <= f + 10; m++)
	{
		if (m >= 0 && m * m * m == x)
		{
			return m;
		}
	}
	return 0;
}
map<ll, int> mp, mp1, mp2;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	// cout << fixed << setprecision(10);
	// cerr << fixed << setprecision(10);
	// freopen ("file.in", "r", stdin);
	// freopen ("file.out", "w", stdout);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	for (int i = 0; i < N; i++)
	{
		ll x = arr[i];
		ll r2 = square_root(x), r3 = cube_root(x), r4 = square_root(r2);
		if (r4)
		{
			mp[r4] += 4;
		}
		else if (r3)
		{
			mp[r3] += 3;
		}
		else if (r2)
		{
			mp[r2] += 2;
		}
		if (r2 || r3 || r4)
		{
			arr[i] = 1;
		}
	}
	//these are the only primes that matter!
	//look at all the primes we've seen in the map
	for (int i = 0; i < N; i++)
	{
		if (arr[i] == 1) continue;
		for (int j = i + 1; j < N; j++)
		{
			if (arr[j] == 0 || arr[j] == arr[i]) continue;
			ll g = gcd(arr[i], arr[j]);
			if (g != 1)
			{
				mp[g] += 0;
			}
		}
	}
	for (auto &p : mp)
	{
		ll x = p.fi;
		for (int i = 0; i < N; i++)
		{
			if (arr[i] == 1) continue;
			if (arr[i] % x == 0)
			{
				arr[i] /= x;
				divided[i] = true;
				p.se++;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (arr[i] == 1) continue;
		if (divided[i])
		{
			mp1[arr[i]]++;
		}
		else
		{
			mp2[arr[i]]++;
		}
	}
	for (auto &p : mp)
	{
		ans *= (p.se + 1);
		ans %= INF;
	}
	for (auto &p : mp1)
	{
		ans *= (p.se + 1);
		ans %= INF;
	}
	for (auto &p : mp2)
	{
		ans *= (p.se + 1); ans %= INF;
		ans *= (p.se + 1); ans %= INF;
	}
	cout << ans << '\n';
	//if you've been divided out you're p, otherwise you're pq
	fflush(stdout);
	// cerr << "time elapsed = " << (clock() / (CLOCKS_PER_SEC / 1000)) << " ms" << endl;
	return 0;
}