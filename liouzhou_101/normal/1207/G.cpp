#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
 
#define X first
#define Y second
 
//#include <boost/unordered_map.hpp>
//using namespace boost;
 
/*
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> rbtree;
rbtree T;
*/
 
using i32 = int;
using i64 = long long;
using u8 = unsigned char;
using u32 = unsigned;
using u64 = unsigned long long;
using f64 = double;
using f80 = long double;
//using i128 = __int128_t;
//using u128 = __uint128_t;
//using i128 = i64;
//using u128 = u64;
 
ll power(ll a, ll b, ll p)
{
	if (!b) return 1;
	ll t = power(a, b/2, p);
	t = t*t%p;
	if (b&1) t = t*a%p;
	return t;
}
 
ll exgcd(ll a, ll b, ll &x, ll &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	ll px, py;
	ll d = exgcd(b, a%b, px, py);
	x = py;
	y = px-a/b*py;
	return d;
}
 
template<class T>
inline void freshmin(T &a, const T &b)
{
	if (a > b) a = b;
}
 
template<class T>
inline void freshmax(T &a, const T &b)
{
	if (a < b) a = b;
}

template<class T>
void print(const T &a)
{
	for (auto x : a) printf("%d ", x); puts("");
}

const int MAXN = 888888;
const int MAXM = 26;
//const i64 INF = 1000000000000000000LL;
const int INF = 1000000000;
//const int MOD = 998244353;
const int MOD = 998244853;
const int INV2 = (MOD+1)/2;
const ld pi = 3.1415926535897932384626433;

int tot;

struct node
{
    node *next[MAXM];
    node *fail;
    int dis;
};

node tree[MAXN];
node *root;

node* new_node()
{
    node *it = &tree[++ tot];
    for (int i = 0; i < MAXM; ++ i) it->next[i] = 0;
    it->fail = 0;
    it->dis = 0;
    return it;
}

void init()
{
    tot = 0;
    root = new_node();
}

node *add(node *it, char c)
{
	int x = c-'a';
    if (!it->next[x])
	{
		it->next[x] = new_node();
		it->next[x]->dis = it->dis+1;
	}
    it = it->next[x];
    return it;
}

void build()
{
    root->fail = root;
    queue<node*> Q;
    for (int i = 0; i < MAXM; ++ i)
        if (root->next[i])
        {
            root->next[i]->fail = root;
            Q.push(root->next[i]);
        }
        else
            root->next[i] = root;
    while (!Q.empty())
    {
        node *it = Q.front();
        Q.pop();
        for (int i = 0; i < MAXM; ++ i)
        {
            if (!it->next[i])
                it->next[i] = it->fail->next[i];
            else
            {
                it->next[i]->fail = it->fail->next[i];
                Q.push(it->next[i]);
            }
        }
    }
}

int n;
node *v[MAXN];
vector<pii> q[MAXN];

vector<int> son[MAXN];

int times, X[MAXN], Y[MAXN];

void dfs(int x)
{
	X[x] = ++ times;
	for (auto y : son[x])
		dfs(y);
	Y[x] = times;
}

int a[MAXN];

void add(int x, int p)
{
	for (; x <= tot; x += x&-x) a[x] += p;
}

int get(int x)
{
	int p = 0;
	for (; x; x ^= x&-x) p += a[x];
	return p;
}

int m;
int ans[MAXN];

void travel(node *x)
{
	add(X[x-tree], 1);
	for (auto e : q[x-tree])
	{
		int z = e.X, id = e.Y;
		ans[id] = get(Y[z])-get(X[z]-1);
	}
	for (int k = 0; k < 26; ++ k)
		if (x->next[k] && x->next[k]->dis == x->dis+1)
			travel(x->next[k]);
	add(X[x-tree], -1);
}

int main()
{
	
	scanf("%d", &n);
	init();
	for (int i = 1; i <= n; ++ i)
	{
		int t;
		scanf("%d", &t);
		if (t == 1)
		{
			char c;
			scanf(" %c", &c);
			v[i] = add(root, c);
		}
		else
		{
			int x;
			char c;
			scanf("%d %c", &x, &c);
			v[i] = add(v[x], c);
		}
	}
	
	scanf("%d", &m);
	for (int i = 1; i <= m; ++ i)
	{
		static char s[MAXN];
		int x;
		scanf("%d%s", &x, s);
		int len = strlen(s);
		node *cur = root;
		for (int j = 0; j < len; ++ j)
			cur = add(cur, s[j]);
		q[v[x]-tree].push_back({cur-tree, i});
	}
	
	build();
	for (int i = 2; i <= tot; ++ i)
	{
		son[tree[i].fail-tree].push_back(i);
	}
	dfs(1);
	
	travel(root);
	
	for (int i = 1; i <= m; ++ i)
		printf("%d\n", ans[i]);
	
	return 0;
}