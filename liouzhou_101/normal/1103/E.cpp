#pragma GCC optimize("Ofast")

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

const int MAXN = 100000;
const int DEG = 5;
const int BASE = 10;
const int MAXP = 10000000;
const int MOD = 1000000007;
const f80 MI = f80(1)/MOD;
const ll INF = 10000000000000000LL;
const ll inf = 5000000000000LL;

int n;

template<class T>
struct node
{
    T v[DEG];
    node (T c = 0, int k = 0)
    {
        for (int i = 0; i < DEG; ++ i)
            v[i] = 0;
        v[k] = c;
    }
    node &operator += (const node &A)
    {
        for (int i = 0; i < DEG; ++ i)
            v[i] += A.v[i];
        return *this;
    }
    friend node operator * (const node &A, const node &B)
    {
        node ret;
        for (int i = 0; i < DEG; ++ i)
            for (int j = 0; j < DEG; ++ j)
                ret.v[(i+j)%DEG] += A.v[i]*B.v[j];
        return ret;
    }
    node &operator *= (const node &A)
    {
        return *this = *this*A;
    }
};

template<class T, class V>
T power(T a, V n)
{
    if (n == 0) return 1;
    T t = power(a, n/2);
    t = t*t;
    if (n&1) t = t*a;
    return t;
}

node<u64> a[MAXN];
node<u64> w[BASE];

void fft(bool inv = 0)
{
    int shift = inv ? BASE-1 : 1;
    for (int step = 1; step < MAXN; step *= BASE)
    {
        for (int offset = 0; offset < MAXN; ++ offset)
        {
            if (offset/step%BASE != 0) continue;
            node<u64> to[BASE];
            for (int i = 0; i < BASE; ++ i)
                for (int j = 0; j < BASE; ++ j)
                    to[i] += w[i*j*shift%BASE]*a[offset+j*step];
            for (int i = 0; i < BASE; ++ i)
                a[offset+i*step] = to[i];
        }
    }
}

int main()
{

    n = inp();
    for (int i = 1; i <= n; ++ i)
        a[inp()] += 1;
    w[0] = 1;
    w[1] = node<u64>(-1, 1);
    for (int i = 2; i < BASE; ++ i)
        w[i] = w[i-1]*w[1];
    fft();
    for (int i = 0; i < MAXN; ++ i)
        a[i] = power(a[i], n);
    fft(1);
    for (int i = 0; i < n; ++ i)
    {
        u64 ans = a[i].v[0]-a[i].v[4];
        ans *= 6723469279985657373ULL;
        ans >>= 5;
        printf("%llu\n", ans%(1ULL<<58));
    }

    return 0;
}