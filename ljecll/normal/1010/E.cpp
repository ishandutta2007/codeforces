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
template<typename T> using hashtable = gp_hash_table<T, T, chash>;

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
template<class T>
T normalize(T x, T mod = 1000000007)
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
#define MAXN 100013

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef tuple<int, int, int> trip;
typedef pair<trip, trip> ptt;

int A, B, C;
int N, M, Q;
trip arr[MAXN], quer[MAXN];
vector<ptt> quers[MAXN];
vector<pii> upds[MAXN];
int ans[MAXN];
ptt bd;

vector<int> fenwick[4 * MAXN];
vector<int> vals[4 * MAXN];
int getindex(vector<int> &v, int val)
{
	return upper_bound(v.begin(), v.end(), val) - v.begin() - 1;
}
void upd(int w, int idx, int val)
{
	idx = getindex(vals[w], idx);
	for (int e = idx + 1; e < fenwick[w].size(); e += (e & (-e)))
	{
		fenwick[w][e] += val;
	}
	return;
}
int qu(int w, int idx)
{
	int sum = 0;
	idx = getindex(vals[w], idx);
	for (int e = idx + 1; e > 0; e -= (e & (-e)))
	{
		sum += fenwick[w][e];
	}
	return sum;
}
void update(int w, int a, int b, int x, int y, int val)
{
	if (x < a || x > b)
	{
		return;
	}
	upd(w, y, val);
	if (a == b)
	{
		return;
	}
	int mid = (a + b)/2;
	update(2 * w, a, mid, x, y, val);
	update(2 * w + 1, mid + 1, b, x, y, val);
	return;
}
int query(int w, int a, int b, int x1, int x2, int y)
{
	if (x2 < a || x1 > b)
	{
		return 0;
	}
	if (x1 <= a && b <= x2)
	{
		return qu(w, y);
	}
	int mid = (a + b)/2;
	return query(2 * w, a, mid, x1, x2, y) + query(2 * w + 1, mid + 1, b, x1, x2, y);
}
void build(int w, int a, int b, int x, int y)
{
	if (x < a || x > b)
	{
		return;
	}
	vals[w].PB(y);
	if (a == b)
	{
		return;
	}
	int mid = (a + b)/2;
	build(2 * w, a, mid, x, y);
	build(2 * w + 1, mid + 1, b, x, y);
	return;
}
int rect(int x1, int x2, int y1, int y2)
{
    int res = query(1, 0, B, x1, x2, y2);
    if (y1)
    {
        res -= query(1, 0, B, x1, x2, y1 - 1);
    }
    return res;
}
ptt tcomb(ptt a, trip b)
{
    ckmin(get<0>(a.fi), get<0>(b));
    ckmax(get<0>(a.se), get<0>(b));
    ckmin(get<1>(a.fi), get<1>(b));
    ckmax(get<1>(a.se), get<1>(b));
    ckmin(get<2>(a.fi), get<2>(b));
    ckmax(get<2>(a.se), get<2>(b));
    return a;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	srand(time(0));
	//	cout << fixed << setprecision(10);
	//	cerr << fixed << setprecision(10);
	if (fopen("input.in", "r"))
	{
		freopen ("input.in", "r", stdin);
		freopen ("output.out", "w", stdout);
	}
    cin >> A >> B >> C >> N >> M >> Q;
    bd = {{A - 1, B - 1, C - 1}, {0, 0, 0}};
    for (int i = 0; i < N; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--; c--;
        bd = tcomb(bd, {a, b, c});
    }
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--; c--;
        if (get<0>(bd.fi) <= a && a <= get<0>(bd.se) && get<1>(bd.fi) <= b && b <= get<1>(bd.se) && get<2>(bd.fi) <= c && c <= get<2>(bd.se))
        {
            cout << "INCORRECT\n";
            return 0;
        }
        upds[a].PB(MP(b, c));
    }
    cout << "CORRECT\n";
    for (int i = 0; i < Q; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--; c--;
        if (get<0>(bd.fi) <= a && a <= get<0>(bd.se) && get<1>(bd.fi) <= b && b <= get<1>(bd.se) && get<2>(bd.fi) <= c && c <= get<2>(bd.se))
        {
            ans[i] = -1;
            continue;
        }
        auto cur = tcomb(bd, {a, b, c});
        quers[get<0>(cur.fi)].PB({{get<1>(cur.fi), get<2>(cur.fi), -1}, {get<1>(cur.se), get<2>(cur.se), i}});
        quers[get<0>(cur.se) + 1].PB({{get<1>(cur.fi), get<2>(cur.fi), 1}, {get<1>(cur.se), get<2>(cur.se), i}});
    }
    for (int i = 0; i <= A; i++)
    {
        for (pii x : upds[i])
        {
            build(1, 0, B, x.fi, x.se);
        }
    }
    for (int i = 0; i <= 4 * B; i++)
    {
        sort(vals[i].begin(), vals[i].end());
        vals[i].erase(unique(vals[i].begin(), vals[i].end()), vals[i].end());
        fenwick[i].resize(vals[i].size() + 2);
    }
    for (int i = 0; i <= A; i++)
    {
        for (auto x : quers[i])
        {
            int x1, x2, y1, y2, net, qid;
            x1 = get<0>(x.fi); x2 = get<0>(x.se);
            y1 = get<1>(x.fi); y2 = get<1>(x.se);
            net = get<2>(x.fi); qid = get<2>(x.se);
            ans[qid] += net * rect(x1, x2, y1, y2);
        }
        for (pii x : upds[i])
        {
            update(1, 0, B, x.fi, x.se, 1);
        }
    }
    for (int i = 0; i < Q; i++)
    {
        if (ans[i] > 0)
        {
            cout << "CLOSED\n";
        }
        if (ans[i] == 0)
        {
            cout << "UNKNOWN\n";
        }
        if (ans[i] < 0)
        {
            cout << "OPEN\n";
        }
    }
	//	cerr << "time elapsed = " << (clock() / (CLOCKS_PER_SEC / 1000)) << " ms" << endl;
	return 0;
}