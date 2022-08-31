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

const int MAXN = 100010;
const int MAXK = 210;
const int MOD = 1000000007;
const f80 MI = f80(1)/MOD;
const int INF = 100001;

int n, k;
int S[MAXK][MAXK];
vector<int> v[MAXN];

int size[MAXN];
int f[MAXN][MAXK], g[MAXN][MAXK], tmp[MAXK];
int ans[MAXK];

void dfs(int x, int p)
{
    f[x][0] = 1;
    for (auto y : v[x])
    {
        if (y == p) continue;
        dfs(y, x);
        for (int i = 0; i <= k && i <= size[y]; ++ i)
            ans[i] = (ans[i]+MOD-g[y][i])%MOD;
        for (int i = 0; i <= k && i <= size[x]+size[y]; ++ i)
            tmp[i] = 0;
        for (int i = 0; i <= k && i <= size[x]; ++ i)
            for (int j = 0; j <= k && j <= size[y]; ++ j)
                tmp[i+j] = (tmp[i+j]+(ll)f[x][i]*g[y][j])%MOD;
        size[x] += size[y];
        for (int i = 0; i <= k && i <= size[x]; ++ i)
            f[x][i] = tmp[i];
    }
    size[x] ++;
    for (int i = 0; i <= k && i <= size[x]; ++ i)
    {
        f[x][i] = f[x][i]*2%MOD;
        g[x][i] = (f[x][i]+(i ? f[x][i-1] : 0)-(i == 1))%MOD;
        ans[i] = (ans[i]+f[x][i])%MOD;
    }
}

int main()
{

    S[0][0] = 1;
    for (int i = 1; i <= 200; ++ i)
        for (int j = 1; j <= i; ++ j)
            S[i][j] = (S[i-1][j-1]+(ll)S[i-1][j]*j)%MOD;

    n = inp();
    k = inp();
    for (int i = 1; i < n; ++ i)
    {
        int x = inp();
        int y = inp();
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1, 0);
    int ret = 0;
    for (int i = 0, fact = 1; i <= k; ++ i)
    {
        ret = (ret+(ll)S[k][i]*fact%MOD*ans[i])%MOD;
        fact = (ll)fact*(i+1)%MOD;
    }
    cout << ret << endl;

    return 0;
}