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
const int MOD = 998244353;
const f80 MI = f80(1)/MOD;
const int INF = 100001;

int block[MAXN];

int n, a[MAXN], u[MAXN];
int len, dp[MAXN], pre[MAXN], link[MAXN];
vector< vector<int> > ans;

void solve()
{
    len = 0;
    dp[1] = INF;
    for (int i = 1; i <= n; ++ i)
    {
        int x = lower_bound(dp+1, dp+len+1, a[i])-dp;
        pre[a[i]] = dp[x-1];
        link[a[i]] = dp[x];
        dp[x] = a[i];
        if (x > len)
        {
            ++ len;
            dp[len+1] = INF;
        }
    }
    if (len > block[n])
    {
        vector<int> v;
        for (int x = dp[len]; x; x = pre[x])
        {
            u[x] = 1;
            v.push_back(x);
        }
        reverse(v.begin(), v.end());
        ans.push_back(v);
        int m = 0;
        for (int i = 1; i <= n; ++ i)
            if (!u[a[i]]) a[++ m] = a[i];
        n = m;
    }
    else
    {
        for (int i = 1; i <= len; ++ i)
        {
            vector<int> v;
            for (int x = dp[i]; x != INF; x = link[x])
                v.push_back(x);
            reverse(v.begin(), v.end());
            ans.push_back(v);
        }
        n = 0;
    }
}

int main()
{

    for (int i = 1; i <= 100000; ++ i)
    {
        block[i] = block[i-1];
        if ((block[i]+1)*(block[i]+2)/2 <= i) block[i] ++;
    }

    for (int T = inp(); T --; )
    {
        n = inp();
        for (int i = 1; i <= n; ++ i)
        {
            a[i] = inp();
            u[i] = 0;
        }
        ans.clear();
        for (; n; solve());
        printf("%d\n", ans.size());
        for (auto v : ans)
        {
            printf("%d", v.size());
            for (auto x : v)
                printf(" %d", x);
            puts("");
        }
    }

    return 0;
}