// #pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
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

ll gcd(ll a, ll b)
{
    return b ? gcd(b, a%b) : a;
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

const int MAXN = 100010;
const int MAXM = 310;
const int MAXK = 17;
const int MOD = 1000000007;
const f80 MI = f80(1)/MOD;
const ll INF = 10000000000000000LL;
const ll inf = 5000000000000LL;

int n, q;
vector<int> v[MAXN];

int times;
int X[MAXN], Y[MAXN];

int dis[MAXN], pre[MAXN][MAXK];

void dfs(int x)
{
    X[x] = ++ times;
    for (auto y : v[x])
    {
        if (pre[x][0] == y) continue;
        pre[y][0] = x;
        dis[y] = dis[x]+1;
        dfs(y);
    }
    Y[x] = times;
}

int LCA(int x, int y)
{
    if (dis[x] < dis[y]) swap(x, y);
    for (int k = MAXK-1; k >= 0; -- k)
        if (dis[x]-dis[y] >= 1<<k)
            x = pre[x][k];
    if (x == y) return x;
    for (int k = MAXK-1; k >= 0; -- k)
        if (pre[x][k] != pre[y][k])
        {
            x = pre[x][k];
            y = pre[y][k];
        }
    return pre[x][0];
}

int a[MAXN];

void add(int x, int p)
{
    for (; x <= n; x += x&-x)
        a[x] += p;
}

void add(int x, int y, int p)
{
    add(x, p);
    add(y+1, -p);
}

int get(int x)
{
    int p = 0;
    for (; x; x -= x&-x)
        p += a[x];
    return p;
}

int h[MAXN], newh[MAXN];
ll F[MAXN][MAXM];

int main()
{

    scanf("%d%d", &n, &q);
    for (int i = 1; i < n; ++ i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);
    for (int k = 1; k < MAXK; ++ k)
        for (int i = 1; i <= n; ++ i)
            pre[i][k] = pre[pre[i][k-1]][k-1];
    while (q --)
    {
        set<int> H;
        vector<int> a;
        int k, m, r;
        scanf("%d%d%d", &k, &m, &r);
        for (int i = 1; i <= k; ++ i)
        {
            int x;
            scanf("%d", &x);
            a.push_back(x);
            H.insert(x);
            add(X[x], Y[x], 1);
        }
        h[r] = get(X[r]);
        for (auto x : a)
        {
            h[x] = get(X[x]);
            int u = LCA(x, r);
            h[u] = get(X[u]);
            newh[x] = h[x]+h[r]-2*h[u]+H.count(u)-1;
        }
        sort(a.begin(), a.end(), [&](int i, int j)
        {
            return newh[i] < newh[j];
        });
        F[0][0] = 1;
        for (int i = 1; i <= k; ++ i)
            for (int j = 1; j <= m; ++ j)
                F[i][j] = (F[i-1][j]*(j-newh[a[i-1]])+F[i-1][j-1])%MOD;
        int ans = 0;
        for (int j = 1; j <= m; ++ j)
            ans = (ans+F[k][j])%MOD;
        printf("%d\n", ans);
        for (auto x : a)
            add(X[x], Y[x], -1);
    }

    return 0;
}