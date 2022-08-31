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

const int MAXN = 1000010;
const int MAXP = 10000000;
const int MOD = 1000000007;
const f80 MI = f80(1)/MOD;
const ll INF = 10000000000000000LL;
const ll inf = 5000000000000LL;

int n;
ll k;

struct node
{
    ll a;
    int e;
    bool operator < (const node &A) const
    {
        return e < A.e;
    }
}a[MAXN];

int m;
vector<ll> p;
map<ll, int> H;
int h[1<<11], pcnt[1<<11];

ll v[1<<11];
ll F[12][1<<11], G[12][1<<11];

int main()
{

    n = inp();
    k = inp_ll();
    for (int i = 1; i <= n; ++ i)
        a[i].a = inp_ll();
    for (int i = 1; i <= n; ++ i)
        a[i].e = inp();
    sort(a+1, a+n+1);

    ll d = a[1].a;
    for (int i = 1; i <= n; ++ i)
        d = gcd(d, a[i].a);
    if (d == 1)
    {
        puts("0");
        return 0;
    }
    for (ll i = 2; i*i <= d; ++ i)
        if (d%i == 0)
        {
            p.push_back(i);
            while (d%i == 0) d /= i;
        }
    if (d > 1) p.push_back(d);
    m = p.size();

    for (int i = 0; i <= m; ++ i)
        for (int s = 1; s < 1<<m; ++ s)
            F[i][s] = INF;

    for (int i = 1; i <= n; ++ i)
    {
        ll cur = 1;
        for (int j = 0; j < m; ++ j)
        {
            ll d = 1;
            while (a[i].a%p[j] == 0)
            {
                d *= p[j];
                a[i].a /= p[j];
            }
            cur *= d;
            v[1<<j] = d;
        }
        if (++ H[cur] > m) continue;
        memcpy(G, F, sizeof(F));
        v[0] = 1;
        for (int s = 1; s < 1<<m; ++ s)
        {
            int low = s&-s;
            v[s] = v[s^low]*v[low];
            if (v[s] > k) continue;
            if (++ h[s] > m) continue;
            int c = ((1<<m)-1)^s;
            for (int x = 0; x < m; ++ x)
            {
                for (int t = c; t; t = (t-1)&c)
                    freshmin(F[x+1][t|s], G[x][t]+a[i].e);
                freshmin(F[x+1][s], (ll)a[i].e);
            }
        }
    }
    ll ans = INF;
    for (int i = 1; i <= m; ++ i)
        ans = min(ans, F[i][(1<<m)-1]*i);
    if (ans == INF) ans = -1;
    cout << ans << endl;

    return 0;
}