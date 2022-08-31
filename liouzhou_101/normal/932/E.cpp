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

const int MAXN = 5010;
const int MOD = 1000000007;
const f80 MI = f80(1)/MOD;
const int INF = 100001;

int n, k;
ll S[MAXN][MAXN];

int main()
{

    cin >> n >> k;
    S[0][0] = 1;
    for (int i = 1; i <= k; ++ i)
        for (int j = 1; j <= i; ++ j)
            S[i][j] = (S[i-1][j-1]+S[i-1][j]*j)%MOD;
    ll ans = 0;
    for (int i = 0; i <= k; ++ i)
    {
        ll tmp = 1;
        for (int j = 0; j < i; ++ j)
            tmp = tmp*(n-j)%MOD;
        tmp = tmp*S[k][i]%MOD;
        tmp = tmp*power(2, n-i, MOD)%MOD;
        ans = (ans+tmp)%MOD;
    }
    cout << ans << endl;

    return 0;
}