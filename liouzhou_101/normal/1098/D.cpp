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

const int MAXN = 500010;
const int MAXK = 30;
const int MAXP = 10000000;
const int MOD = 1000000007;
const f80 MI = f80(1)/MOD;
const ll INF = 10000000000000000LL;
const ll inf = 5000000000000LL;

ll sum[MAXK];
multiset<int> H[MAXK];

int main()
{

    int n;
    scanf("%d", &n);
    int cnt = 0;
    while (n --)
    {
        char t;
        int x;
        scanf(" %c%d", &t, &x);
        if (t == '+')
        {
            ++ cnt;
            for (int k = 0; k < MAXK; ++ k)
            {
                if (x<1<<(k+1))
                {
                    sum[k] += x;
                    H[k].insert(x);
                    break;
                }
            }
        }
        else if (t == '-')
        {
            -- cnt;
            for (int k = 0; k < MAXK; ++ k)
            {
                if (x<1<<(k+1))
                {
                    sum[k] -= x;
                    H[k].erase(H[k].lower_bound(x));
                    break;
                }
            }
        }
        ll cur = 0;
        int ans = 0;
        for (int k = 0; k < MAXK; ++ k)
        {
            if (H[k].empty()) continue;
            if (*H[k].begin() > cur*2)
                ++ ans;
            cur += sum[k];
        }
        printf("%d\n", cnt-ans);
    }

    return 0;
}