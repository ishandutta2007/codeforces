/*
PROG: source
LANG: C++11
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
        int operator()(long long x) const
        {
                return x ^ (x >> 32);
        }
};

template<typename T> using orderedset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename U> using hashtable = gp_hash_table<T, U, chash>;

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
T normalize(T x, U mod = 1000000007)
{
	return (((x % mod) + mod) % mod);
}
long long randomizell(long long mod)
{
	return ((1ll << 45) * rand() + (1ll << 30) * rand() + (1ll << 15) * rand() + rand()) % mod;
}
int randomize(int mod)
{
        return ((1ll << 15) * rand() + rand()) % mod;
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
#define MAXN 2000013

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;

int N, M;
pii arr[MAXN];
vector<int> compress;
bool ok[MAXN];
int dsu[MAXN], sz[MAXN], ed[MAXN];
int dp[MAXN];

int find_parent(int u)
{
        return (u == dsu[u] ? u : dsu[u] = find_parent(dsu[u]));
}
bool merge(int u, int v)
{
        u = find_parent(u);
        v = find_parent(v);
        if (u == v)
        {
                return false;
        }
        if (sz[u] > sz[v])
        {
                swap(u, v);
        }
        dsu[u] = v;
        sz[v] += sz[u];
        sz[u] = 0;
        return true;
}
bool check(int x)
{
        //so basically for this subset, if # of guys it can reach is too small then sad!
        //dp[i] = (# of guys you can reach) - (# of guys available)
        for (int i = 0; i < M; i++)
        {
                ed[i] = 0;
                dsu[i] = i;
                sz[i] = 1;
        }
        for (int i = 0; i < N; i++)
        {
                if (arr[i].fi > x)
                {
                        return false;
                }
                if (arr[i].se > x)
                {
                        ok[arr[i].fi] = false;
                }
                else
                {
                        merge(arr[i].fi, arr[i].se);
                }
        }
        for (int i = 0; i < N; i++)
        {
                if (arr[i].se > x)
                {
                        sz[find_parent(arr[i].fi)]--;
                }
                else
                {
                        ed[find_parent(arr[i].fi)]++;
                }
        }
        for (int i = 0; i < M; i++)
        {
                if (find_parent(i) != i)
                {
                        continue;
                }
                if (sz[i] < ed[i])
                {
                        return false;
                }
        }
        return true;
        //now make things work!
        //dp[people]
        //dp[people]
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	srand(time(0));
	//     cout << fixed << setprecision(10);
	//     cerr << fixed << setprecision(10);
	//     if (fopen("input.in", "r"))
	//     {
	//             freopen ("input.in", "r", stdin);
	//             freopen ("output.out", "w", stdout);
	//     }
        readi(N);
        for (int i = 0; i < N; i++)
        {
                readi(arr[i].fi); readi(arr[i].se);
                if (arr[i].fi > arr[i].se)
                {
                        swap(arr[i].fi, arr[i].se);
                }
                compress.PB(arr[i].fi);
                compress.PB(arr[i].se);
        }
        sort(compress.begin(), compress.end());
        compress.erase(unique(compress.begin(), compress.end()), compress.end());
        M = compress.size();
        for (int i = 0; i < N; i++)
        {
                arr[i].fi = LB(compress.begin(), compress.end(), arr[i].fi) - compress.begin();
                arr[i].se = LB(compress.begin(), compress.end(), arr[i].se) - compress.begin();
        }
        sort(arr, arr + N);
        int lo = 0, hi = M;
        while(hi > lo)
        {
                int mid = (hi + lo) / 2;
                // cerr << mid << ' ' << check(mid) << endl;
                if (check(mid))
                {
                        hi = mid;
                }
                else
                {
                        lo = mid + 1;
                }
        }
        if (lo == M)
        {
                puts("-1");
                return 0;
        }
        printi(compress[lo]); putchar('\n');
	//     cerr << "time elapsed = " << (clock() / (CLOCKS_PER_SEC / 1000)) << " ms" << endl;
	return 0;
}