//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

const int MAXN = 52;
const int MOD = 1000000009;
const f80 MI = f80(1)/MOD;
const int INF = 1000000000;

int n;
vector<int> v[MAXN];

int size[MAXN];
ld f[MAXN][MAXN], g[MAXN], tmp[MAXN];
ld p[MAXN];

ld C(int n, int m)
{
    return p[n]/p[m]/p[n-m];
}

void dfs(int x, int p)
{
    size[x] = 0;
    f[x][0] = 1;
    for (auto y : v[x])
    {
        if (y == p) continue;
        dfs(y, x);
        for (int i = 0; i <= size[y]; ++ i)
        {
            g[i] = (1-(ld)i/size[y])*f[y][i];
            for (int j = 0; j < i; ++ j)
                g[i] += f[y][j]/2.0/size[y];
        }
        for (int i = 0; i <= size[x]+size[y]; ++ i)
            tmp[i] = 0;
        for (int i = 0; i <= size[x]; ++ i)
            for (int j = 0; j <= size[y]; ++ j)
                tmp[i+j] += C(size[x], i)*C(size[y], j)/C(size[x]+size[y], i+j)*f[x][i]*g[j];
        for (int i = 0; i <= size[x]+size[y]; ++ i)
            f[x][i] = tmp[i];
        size[x] += size[y];
    }
    size[x] ++;
}

void solve(int x)
{
    dfs(x, 0);
    printf("%.8lf\n", f[x][n-1]);
}

int main()
{

    scanf("%d", &n);
    p[0] = 1;
    for (int i = 1; i <= n; ++ i)
        p[i] = p[i-1]*i;
    for (int i = 1; i < n; ++ i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i = 1; i <= n; ++ i)
        solve(i);

    return 0;
}