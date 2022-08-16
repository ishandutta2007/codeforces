#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
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

const int MAXN = 300010;
const int MOD = 998244353;
const f80 MI = f80(1)/MOD;
const int INF = 1000000000;

int n, k;
vector<int> v[MAXN];
int a[MAXN], c[MAXN], to[MAXN];

int pre[MAXN];

int head, tail, Q[MAXN];
int u[MAXN];
vector<int> w[MAXN];

bool bfs()
{
    Q[head = tail = 1] = u[1] = 1;
    while (head <= tail)
    {
        int x = Q[head ++];
        for (auto y : v[x])
            if (!u[y])
            {
                u[Q[++ tail] = y] = 1;
                pre[y] = x;
            }
    }
    for (int k = n; k >= 1; -- k)
    {
        int x = Q[k];
        if (!a[x]) continue;
        if (c[a[x]] == 1)
        {
            to[a[x]] = x;
            continue;
        }
        if (!a[pre[x]])
            a[pre[x]] = a[x];
        else if (a[pre[x]] == a[x])
            c[a[x]] --;
        else
            return false;
    }
    for (int x = 2; x <= n; ++ x)
        if (!a[x] || a[x] != a[pre[x]])
        {
            int y = pre[x];
            w[a[y] ? to[a[y]] : y].push_back(x);
        }
    return true;
}

int prod[MAXN];
int f[MAXN][2];

void dfs(int x)
{
    for (auto y : w[x])
        dfs(y);
    prod[w[x].size()] = 1;
    for (int i = w[x].size()-1; i >= 0; -- i)
    {
        int y = w[x][i];
        prod[i] = (ll)prod[i+1]*(f[y][0]+f[y][1])%MOD;
    }
    if (a[x] == 0)
    {
        f[x][0] = prod[0];
        f[x][1] = 0;
        for (int i = 0, tmp = 1; i < w[x].size(); ++ i)
        {
            int y = w[x][i];
            f[x][1] = (f[x][1]+(ll)tmp*f[y][1]%MOD*prod[i+1])%MOD;
            tmp = (ll)tmp*(f[y][0]+f[y][1])%MOD;
        }
    }
    else
    {
        f[x][0] = 0;
        f[x][1] = prod[0];
    }
}

int main()
{

    n = inp();
    k = inp();
    for (int i = 1; i <= n; ++ i)
    {
        a[i] = inp();
        c[a[i]] ++;
    }
    for (int i = 1; i < n; ++ i)
    {
        int x = inp();
        int y = inp();
        v[x].push_back(y);
        v[y].push_back(x);
    }
    if (!bfs())
    {
        puts("0");
        return 0;
    }
    dfs(1);
    cout << f[1][1] << endl;

    return 0;
}