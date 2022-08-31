// #pragma GCC optimize("Ofast")

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

namespace io{
    const int L = (1 << 20) + 1;

    char buf[L], *S , *T, c;

    char getchar() {
        if(__builtin_expect(S == T, 0)) {
            T = (S = buf) + fread(buf, 1, L, stdin);
            return (S == T ? EOF : *S++);
        }
        return *S++;
    }

    int inp() {
        int x = 0, f = 1; char ch;
        for(ch = getchar(); !isdigit(ch); ch = getchar())
            if(ch == '-') f = -1;
        for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
        return x * f;
    }

    unsigned inpu()
    {
        unsigned x = 0; char ch;
        for(ch = getchar(); !isdigit(ch); ch = getchar());
        for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
        return x;
    }

    ll inp_ll() {
        ll x = 0; int f = 1; char ch;
        for(ch = getchar(); !isdigit(ch); ch = getchar())
            if(ch == '-') f = -1;
        for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
        return x * f;
    }

    char B[25], *outs=B+20, *outr=B+20;
    template<class T>
    inline void print(register T a,register char x=0){
        if(x) *--outs = x, x = 0;

        if(!a)*--outs = '0';
        else
            while(a)
                *--outs = (a % 10) + 48, a /= 10;

        if(x)
            *--outs = x;

        fwrite(outs, outr - outs , 1, stdout);
        outs = outr;
    }
};

using io :: print;
using io :: inp;
using io :: inpu;
using io :: inp_ll;

using i32 = int;
using i64 = long long;
using u8 = unsigned char;
using u32 = unsigned;
using u64 = unsigned long long;
using f64 = double;
using f80 = long double;

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

const int MAXN = 200010;
const int MOD = 1000000009;
const f80 MI = f80(1)/MOD;
const int INF = 1000000000;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

struct node
{
    node *pre, *son[2];
    int rev;
}nodes[MAXN];

node *nil = nodes;

struct LinkCutTree
{
    void init(int n)
    {
        nil->pre = nil->son[0] = nil->son[1] = nil;
        nil->rev = 0;
        for (int i = 1; i <= n; ++ i)
        {
            nodes[i].pre = nodes[i].son[0] = nodes[i].son[1] = nil;
            nodes[i].rev = 0;
        }
    }

    bool is_root(node *x)
    {
        return x->pre->son[0] != x && x->pre->son[1] != x;
    }

    void reverse(node *x)
    {
        if (x != nil)
        {
            x->rev ^= 1;
            swap(x->son[0], x->son[1]);
        }
    }

    void clear(node *x)
    {
        if (x->rev)
        {
            reverse(x->son[0]);
            reverse(x->son[1]);
            x->rev = 0;
        }
    }

    void update(node *x)
    {

    }

    void rotate(node *x)
    {
        node *y = x->pre, *z = y->pre;
        int p = y->son[1] == x, q = p^1;
        if (!is_root(y))
            z->son[z->son[1] == y] = x;
        x->pre = z;
        y->pre = x;
        if (x->son[q])
            x->son[q]->pre = y;
        y->son[p] = x->son[q];
        x->son[q] = y;
        update(y);
        update(x);
    }

    void clear_all(node *x)
    {
        if (!is_root(x)) clear_all(x->pre);
        clear(x);
    }

    void splay(node *x)
    {
        clear_all(x);
        while (!is_root(x))
        {
            node *y = x->pre, *z = y->pre;
            if (!is_root(y))
                rotate((y->son[0] == x) ^ (z->son[0] == y) ? x : y);
            rotate(x);
        }
    }

    void access(node *x0)
    {
        for (node *x = x0, *y = nil; x != nil; x = x->pre)
        {
            splay(x);
            x->son[1] = y;
            y = x;
        }
        splay(x0);
    }

    node *belong(node *x)
    {
        access(x);
        for (; x->son[0] != nil; x = x->son[0]);
        splay(x);
        return x;
    }

    bool check(node *x, node *y)
    {
        node *fx = belong(x);
        node *fy = belong(y);
        return fx == fy;
    }

    void link(node *x, node *y)
    {
        access(x);
        reverse(x);
        x->pre = y;
    }

    void cut(node *x, node *y)
    {
        access(y);
        splay(x);
        if (x->pre == y)
            x->pre = nil;
        else
        {
            access(x);
            splay(y);
            if (y->pre == x) y->pre = nil;
        }
    }

    bool check(int x, int y) // check whether x and y are connected
    {
        return check(nodes+x, nodes+y);
    }
    void link(int x, int y)
    {
        link(nodes+x, nodes+y);
    }
    bool try_link(int x, int y)
    {
        if (check(x, y)) return 1;
        link(x, y);
        return 0;
    }

    void cut(int x, int y)
    {
        cut(nodes+x, nodes+y);
    }
}T;

int n, m;
int a[MAXN];
vector<int> v[MAXN];

int place(int i, int j)
{
    return (i-1)*m+j;
}

struct segtree
{
    int add, min, cnt;
}tree[MAXN*4];

void clear(int k)
{
    if (tree[k].add)
    {
        tree[k<<1].add += tree[k].add;
        tree[k<<1].min += tree[k].add;
        tree[k<<1|1].add += tree[k].add;
        tree[k<<1|1].min += tree[k].add;
        tree[k].add = 0;
    }
}

void update(int k)
{
    tree[k].min = min(tree[k<<1].min, tree[k<<1|1].min);
    tree[k].cnt = (tree[k<<1].min == tree[k].min)*tree[k<<1].cnt + (tree[k<<1|1].min == tree[k].min)*tree[k<<1|1].cnt;
}

void build(int k, int L, int R)
{
    if (L == R)
    {
        tree[k].add = 0;
        tree[k].min = 0;
        tree[k].cnt = 1;
        return;
    }
    int m = (L+R)/2;
    build(k<<1, L, m);
    build(k<<1|1, m+1, R);
    update(k);
}

void add(int k, int L, int R, int x, int y, int p)
{
    if (L == x && R == y)
    {
        tree[k].add += p;
        tree[k].min += p;
        return;
    }
    clear(k);
    int m = (L+R)/2;
    if (y <= m)
        add(k<<1, L, m, x, y, p);
    else if (x > m)
        add(k<<1|1, m+1, R, x, y, p);
    else
    {
        add(k<<1, L, m, x, m, p);
        add(k<<1|1, m+1, R, m+1, y, p);
    }
    update(k);
}

pii query(int k, int L, int R, int x, int y)
{
    if (L == x && R == y)
        return pii(tree[k].min, tree[k].cnt);
    clear(k);
    int m = (L+R)/2;
    if (y <= m)
        return query(k<<1, L, m, x, y);
    if (x > m)
        return query(k<<1|1, m+1, R, x, y);
    auto lans = query(k<<1, L, m, x, m);
    auto rans = query(k<<1|1, m+1, R, m+1, y);
    return pii(min(lans.first, rans.first), (lans.first <= rans.first)*lans.second+(lans.first >= rans.first)*rans.second);
}

int main()
{

    n = inp();
    m = inp();
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j)
            a[place(i, j)] = inp();
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j)
            for (int d = 0; d < 4; ++ d)
            {
                int x = i+dx[d], y = j+dy[d];
                if (1 <= x && x <= n && 1 <= y && y <= m)
                    v[a[place(i, j)]].push_back(a[place(x, y)]);
            }
    ll ans = 0;
    T.init(n*m);
    build(1, 1, n*m);
    for (int i = 1, j = 1; i <= n*m; ++ i)
    {
        while (1)
        {
            int flag = 0;
            for (auto x : v[i])
                if (j <= x && x < i)
                    flag |= T.try_link(x, i);
            if (!flag) break;
            for (auto x : v[i])
                if (j <= x && x < i)
                    T.cut(x, i);
            for (auto x : v[j])
                T.cut(x, j);
            j ++;
        }
        add(1, 1, n*m, j, i, 1);
        for (auto x : v[i])
            if (j <= x && x < i)
                add(1, 1, n*m, j, x, -1);
        auto ret = query(1, 1, n*m, j, i);
        if (ret.first == 1) ans += ret.second;
    }
    cout << ans << endl;

    return 0;
}