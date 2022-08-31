#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")

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
const int MAXV = 100000;
const int MAXK = 17;
const int MAXP = 10000000;
const int MOD = 1000000007;
const f80 MI = f80(1)/MOD;
const ll INF = 10000000000000000LL;
const ll inf = 5000000000000LL;

// \sum_{x=0}^n floor((ax+b)/c) provided a, b, c > 0 and n >= 0
ll f(ll a, ll b, ll c, ll n)
{
    if (a == 0) return b/c*(n+1);
    if (a >= c || b >= c)
        return f(a%c, b%c, c, n)+a/c*n*(n+1)/2+b/c*(n+1);
    ll m = (a*n+b)/c;
    return m*n-f(c, c-b-1, a, m-1);
}

// \sum_{x=0}^n \max \{ floor((ax+b)/c), 0 \}
ll calc(ll a, ll b, ll c, ll n)
{
    if (c < 0) return calc(-a, -b, -c, n);
    if (a < 0) return calc(-a, b+a*n, c, n);
    if (b < 0)
    {
        ll d = (-b-1)/a+1;
        return calc(a, b+d*a, c, n-d);
    }
    if (n < 0) return 0;
    return f(a, b, c, n);
}

// \sum_{i=L}^R \min\{i, d\}
ll solve(ll L, ll R, ll d)
{
    if (L > R) return 0;
    if (R <= d) return (L+R)*(R-L+1)/2;
    if (d <= L) return (R-L+1)*d;
    return solve(L, d, d)+solve(d+1, R, d);
}

int n;
int a[MAXN][MAXK];
ll b[MAXN], c[MAXN], s[MAXN];

int getgcd(int L, int R)
{
    int k = __lg(R-L+1);
    return __gcd(a[L][k], a[R-(1<<k)+1][k]);
}

ll N;

bool check(ll x)
{
    ll ans = 0;
    for (int i = 1, j = 1; i <= MAXV; ++ i)
    {
        if (!b[i]) continue;
        if (s[i] <= x)
            ans += b[i]*c[i-1]+b[i]*(b[i]+1)/2;
        else
        {
            ll cnt = 1;
            while (j < i && cnt <= b[i])
            {
                if (s[i-1]-s[j]+cnt*i > x)
                    ++ j;
                else
                {
                    ll cntnew = min((x-s[i-1]+s[j])/i, (ll)b[i]);
                    ans += calc(-i, x-s[i-1]+s[j]-cnt*i, j, cntnew-cnt);
                    ans -= calc(-i, x-s[i-1]+s[j]-cnt*i-j*b[j], j, cntnew-cnt);
                    ans += (cntnew-cnt+1)*(c[i-1]-c[j]);
                    ans += (cnt+cntnew)*(cntnew-cnt+1)/2;
                    cnt = cntnew+1;
                }
            }
            if (j == i)
                ans += solve(cnt, b[i], x/i);
        }
    }
    return ans >= N;
}

int main()
{

    n = inp();
    for (int i = 1; i <= n; ++ i)
        a[i][0] = inp();
    for (int k = 1; k < MAXK; ++ k)
        for (int i = 1; i <= n; ++ i)
            a[i][k] = __gcd(a[i][k-1], i+(1<<(k-1)) <= n ? a[i+(1<<(k-1))][k-1] : 0);
    for (int i = 1; i <= n; ++ i)
    {
        for (int j = i; j <= n; ++ j)
        {
            int j0 = j;
            int d = getgcd(i, j0);
            int L = j0, R = n;
            while (L <= R)
            {
                int m = (L+R)/2;
                if (getgcd(i, m) == d)
                {
                    j = m;
                    L = m+1;
                }
                else
                    R = m-1;
            }
            b[d] += j-j0+1;
        }
    }
    for (int i = 1; i <= MAXV; ++ i)
    {
        c[i] = c[i-1]+b[i];
        s[i] = s[i-1]+i*b[i];
    }
    ll L = 1, R = 250000000000000LL, ans = 1;
    N = (ll)n*(n+1)/2;
    N = N*(N+1)/2;
    N = (N+1)/2;
    while (L <= R)
    {
        ll m = (L+R)/2;
        if (check(m))
        {
            ans = m;
            R = m-1;
        }
        else
            L = m+1;
    }
    cout << ans << endl;

    return 0;
}