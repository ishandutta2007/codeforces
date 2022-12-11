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

int N, Q;
pll arr[MAXN];

struct fenwick
{
	ll fen[MAXN];
	void update(int idx, ll v, bool flag)
	{
		for (int e = idx + 1; e <= N + 1; e += e & (-e))
		{
			fen[e] += v;
			if (flag) nmod(fen[e], INF);
		}
		return;
	}
	ll query(int idx)
	{
		ll res = 0;
		for (int e = idx + 1; e; e -= e & (-e))
		{
			res += fen[e];
		}
		return res;
	}
	int kth(ll k)
	{
		//smallest x such that pull(x) >= k
		ll WAS = k;
		int res = 0;
		for (int i = 20; i >= 0; i--)
		{
			if (res + (1 << i) > N + 1)
			{
				continue;
			}
			if (fen[res + (1 << i)] <= k)
			{
				k -= fen[res + (1 << i)];
				res += (1 << i);
			}
		}
		assert(query(res) >= WAS);
		return res;
	}
};

fenwick weight, weighted;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	// cout << fixed << setprecision(10);
	// cerr << fixed << setprecision(10);
	// freopen ("file.in", "r", stdin);
	// freopen ("file.out", "w", stdout);
	cin >> N >> Q;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].fi;
		arr[i].fi -= i;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].se;
		weight.update(i, arr[i].se, 0);
		weighted.update(i, arr[i].fi * arr[i].se % INF, 1);
	}
	while(Q--)
	{
		int A, B;
		cin >> A >> B;
		if (A < 0)
		{
			A = -A;
			A--;
			B -= arr[A].se;
			weight.update(A, B, 0);
			weighted.update(A, arr[A].fi * B % INF, 1);
			arr[A].se += B;
		}
		else
		{
			ll ans = 0;
			A--; B--;
			ll hi = weight.query(B), lo = weight.query(A - 1), mid = (lo + hi) / 2;
			int idx = weight.kth(mid);
			ll numless = weight.query(idx) - weight.query(A - 1); numless %= INF;
			ll sumless = weighted.query(idx) - weighted.query(A - 1);
			sumless %= INF; sumless += INF; nmod(sumless, INF);
			ans += (numless * arr[idx].fi - sumless);
			ll nummore = weight.query(B) - weight.query(idx); nummore %= INF;
			ll summore = weighted.query(B) - weighted.query(idx);
			summore %= INF; summore += INF; nmod(summore, INF);
			ans += (summore - arr[idx].fi * nummore);
			ans %= INF; ans += INF; nmod(ans, INF);
			cout << ans << '\n';
		}
	}
	//don't yo u obviously just move
	// cerr << "time elapsed = " << (clock() / (CLOCKS_PER_SEC / 1000)) << " ms" << endl;
	return 0;
}