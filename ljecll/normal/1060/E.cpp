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
#define MAXN 200013

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;

int N;
vector<int> edge[MAXN];
int parent[MAXN], depth[MAXN], subtree[MAXN];
int odds;
ll ans;

void dfs(int u)
{
	subtree[u] = 1;
	for (int v : edge[u])
	{
		if (v == parent[u]) continue;
		parent[v] = u;
		depth[v] = depth[u] + 1;
		dfs(v);
		subtree[u] += subtree[v];
	}
	if (u != 0)
	{
		ans += 1ll * subtree[u] * (N - subtree[u]);
	}
	return;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	// cout << fixed << setprecision(10);
	// cerr << fixed << setprecision(10);
	// freopen ("file.in", "r", stdin);
	// freopen ("file.out", "w", stdout);
	cin >> N;
	for (int i = 1; i < N; i++)
	{
		int u, v;
		cin >> u >> v;
		u--; v--;
		edge[u].PB(v);
		edge[v].PB(u);
	}
	parent[0] = N;
	dfs(0);
	for (int i = 0; i < N; i++)
	{
		if (depth[i] % 2)
		{
			odds++;
		}
	}
	ans += 1ll * odds * (N - odds);
	//sum of ceil(d / 2)
	//it's 1/2 of (d + 1) for odds + d for evens
	//so it's 1/2 of (total + #odds)
	ans /= 2;
	cout << ans << '\n';
	// cerr << "time elapsed = " << (clock() / (CLOCKS_PER_SEC / 1000)) << " ms" << endl;
	return 0;
}