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
#define MAXN 300013

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;

int N;
int arr[MAXN];
bitset<MAXN> flag;
int pref[2][MAXN];
ll ans;

ll choose2(int x)
{
	return 1ll * x * (x - 1) / 2;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	// cout << fixed << setprecision(10);
	// cerr << fixed << setprecision(10);
	// freopen ("file.in", "r", stdin);
	// freopen ("file.out", "w", stdout);
	cin >> N;
	flag[0] = 0;
	pref[0][1] = 1;
	for (int i = 1; i <= N; i++)
	{
		ll x;
		cin >> x;
		arr[i] = __builtin_popcountll(x);
		flag[i] = flag[i - 1] ^ (arr[i] % 2);
		pref[0][i + 1] = pref[0][i];
		pref[1][i + 1] = pref[1][i];
		pref[flag[i]][i + 1]++;
	}
	ans = choose2(pref[0][N + 1]) + choose2(pref[1][N + 1]);
	//S[i]....j = pref[j + 1] - pref[0]
	for (int i = 1; i <= N; i++)
	{
		int big = 0, tot = 0;
		for (int j = i + 1; j <= N + 1 && j < i + 64; j++)
		{
			tot += arr[j - 1]; ckmax(big, arr[j - 1]);
			if (tot < 2 * big && flag[j - 1] == flag[i - 1])
			{
				ans--;
			}
		}
	}
	cout << ans << '\n';
	// cerr << "time elapsed = " << (clock() / (CLOCKS_PER_SEC / 1000)) << " ms" << endl;
	return 0;
}