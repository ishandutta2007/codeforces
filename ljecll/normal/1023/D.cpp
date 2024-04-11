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
#define MAXN 200013

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;

int N, Q;
int arr[MAXN];
int lt[MAXN], rt[MAXN];
int ans[MAXN];

struct segtree
{
	ll seg[4 * MAXN];
	ll lazy[4 * MAXN]; bool lazyflag[4 * MAXN];
	bool typ;
	ll DNE = LLINF; //MODIFY AS APPROPRIATE
	ll comb(ll a, ll b)
	{
		//MODIFY AS APPROPRIATE
                return min(a, b);
	}
        void build(int w, int L, int R)
        {
                if (L == R)
                {
                        seg[w] = arr[L];
                        lazyflag[w] = false;
                        return;
                }
                int mid = (L + R) / 2;
                build(2 * w, L, mid);
                build(2 * w + 1, mid + 1, R);
                seg[w] = comb(seg[2 * w], seg[2 * w + 1]);
        }
	void push(int w, int L, int R)
	{
                if (!lazyflag[w])
                {
                        return;
                }
		seg[w] = lazy[w];
		if (L != R)
		{
                        lazyflag[2 * w] = true;
			lazy[2 * w] = lazy[w];
                        lazyflag[2 * w + 1] = true;
			lazy[2 * w + 1] = lazy[w];
		}
		lazyflag[w] = false;
		return;
	}
	void update(int w, int L, int R, int a, int b, ll val)
	{
		push(w, L, R);
		if (b < L || R < a)
		{
			return;
		}
		if (R <= b && a <= L)
		{
                        lazyflag[w] = true;
                        lazy[w] = val;
			push(w, L, R);
			return;
		}
		int mid = (L + R)/2;
		update(2 * w, L, mid, a, b, val);
		update(2 * w + 1, mid + 1, R, a, b, val);
		seg[w] = comb(seg[2 * w] + lazy[2 * w], seg[2 * w + 1] + lazy[2 * w + 1]);
		return;
	}
	ll query(int w, int L, int R, int a, int b)
	{
		push(w, L, R);
		if (b < L || R < a)
		{
			return DNE;
		}
		if (a <= L && R <= b)
		{
			return seg[w];
		}
		int mid = (L + R)/2;
		return comb(query(2 * w, L, mid, a, b), query(2 * w + 1, mid + 1, R, a, b));
	}
};

segtree seg;

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
        cin >> N >> Q;
        for (int i = 0; i <= Q; i++)
        {
                lt[i] = N;
                rt[i] = -1;
        }
        bool hellohello = true;
        for (int i = 0; i < N; i++)
        {
                cin >> arr[i];
                if (arr[i] == 0)
                {
                        arr[i] = Q;
                }
                else
                {
                        arr[i]--;
                        hellohello = false;
                }
                ckmax(rt[arr[i]], i);
                ckmin(lt[arr[i]], i);
                // cerr << arr[i] << ' ';
        }
        // cerr << endl
        if (hellohello)
        {
                cout << "YES\n";
                for (int i = 0; i < N; i++)
                {
                        cout << Q << ' ';
                }
                cout << '\n';
                return 0;
        }
        seg.build(1, 0, N - 1);
        for (int i = 0; i < Q; i++)
        {
                if (lt[i] == N && rt[i] == -1)
                {
                        continue;
                }
                //query min!
                int cap = seg.query(1, 0, N - 1, lt[i], rt[i]);
                // cerr << lt[i] << ' ' << rt[i] << ' ' << cap << endl;
                if (cap < i)
                {
                        cout << "NO\n";
                        return 0;
                }
        }
        for (int i = 0; i < Q; i++)
        {
                seg.update(1, 0, N - 1, lt[i], rt[i], i);
        }
        //cover any zeroes with a Q
        if (lt[Q - 1] == N && rt[Q - 1] == -1)
        {
                if (lt[Q] == N && rt[Q] == -1)
                {
                        cout << "NO\n";
                        return 0;
                }
                for (int i = 0; i < N; i++)
                {
                        if (arr[i] == Q)
                        {
                                seg.update(1, 0, N - 1, i, i, Q - 1);
                                break;
                        }
                }
        }
        cout << "YES\n";
        for (int i = 0; i < N; i++)
        {
                ans[i] = seg.query(1, 0, N - 1, i, i);
                if (ans[i] == Q)
                {
                        cout << 1 << ' ';
                }
                else
                {
                        cout << ans[i] + 1 << ' ';
                }
        }
        cout << '\n';
        //first you overlay a one, then a two, then a three, then a whatever
	//     cerr << "time elapsed = " << (clock() / (CLOCKS_PER_SEC / 1000)) << " ms" << endl;
	return 0;
}