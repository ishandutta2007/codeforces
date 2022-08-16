#pragma GCC optimize("Ofast")

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
const int MAXP = 9;
const int MOD = 1000000009;
const f80 MI = f80(1)/MOD;
const int INF = 1000000000;

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

int mod;
int rev[MAXN];
int primes;
vector<int> prime;

struct node
{
    int mul, sum, mul2;
}tree[MAXN*4];

int tot[MAXP][MAXN];

int get(int *v, int x)
{
    int p = 0;
    for (; x; x -= x&-x)
        p += v[x];
    return p;
}

void add(int *v, int x, int p)
{
    for (; x < MAXN; x += x&-x)
        v[x] += p;
}

void add(int *v, int x, int y, int p)
{
    add(v, x, p);
    add(v, y+1, -p);
}

int n;
int a[MAXN];

void clear(int k)
{
    if (tree[k].mul != 1)
    {
        tree[k<<1].mul = (ll)tree[k<<1].mul*tree[k].mul%mod;
        tree[k<<1].sum = (ll)tree[k<<1].sum*tree[k].mul%mod;
        tree[k<<1|1].mul = (ll)tree[k<<1|1].mul*tree[k].mul%mod;
        tree[k<<1|1].sum = (ll)tree[k<<1|1].sum*tree[k].mul%mod;
        tree[k].mul = 1;
    }
    if (tree[k].mul2 != 1)
    {
        tree[k<<1].mul2 = (ll)tree[k<<1].mul2*tree[k].mul2%mod;
        tree[k<<1|1].mul2 = (ll)tree[k<<1|1].mul2*tree[k].mul2%mod;
        tree[k].mul2 = 1;
    }
}

void update(int k)
{
    tree[k].sum = (tree[k<<1].sum+tree[k<<1|1].sum)%mod;
}

void build(int k, int L, int R)
{
    tree[k].mul = tree[k].mul2 = 1;
    if (L == R)
    {
        int tmp = a[L];
        for (int i = 0; i < primes; ++ i)
        {
            int cnt = get(tot[i], L);
            tmp = (ll)tmp*power(prime[i], cnt, mod)%mod;
        }
        tree[k].sum = tmp;
        return;
    }
    int m = (L+R)/2;
    build(k<<1, L, m);
    build(k<<1|1, m+1, R);
    update(k);
}

void mul(int k, int L, int R, int x, int y, int p, int p2)
{
    if (L == x && R == y)
    {
        tree[k].mul = (ll)tree[k].mul*p%mod;
        tree[k].mul2 = (ll)tree[k].mul2*p2%mod;
        tree[k].sum = (ll)tree[k].sum*p%mod;
        return;
    }
    clear(k);
    int m = (L+R)/2;
    if (y <= m)
        mul(k<<1, L, m, x, y, p, p2);
    else if (x > m)
        mul(k<<1|1, m+1, R, x, y, p, p2);
    else
    {
        mul(k<<1, L, m, x, m, p, p2);
        mul(k<<1|1, m+1, R, m+1, y, p, p2);
    }
    update(k);
}

void modify(int k, int L, int R, int x)
{
    if (L == R)
    {
        int tmp = (ll)a[L]*tree[k].mul2%mod;
        for (int i = 0; i < primes; ++ i)
        {
            int cnt = get(tot[i], x);
            tmp = (ll)tmp*power(prime[i], cnt, mod)%mod;
        }
        tree[k].mul = 1;
        tree[k].sum = tmp;
        return;
    }
    clear(k);
    int m = (L+R)/2;
    if (x <= m)
        modify(k<<1, L, m, x);
    else
        modify(k<<1|1, m+1, R, x);
    update(k);
}

int getsum(int k, int L, int R, int x, int y)
{
    if (L == x && R == y)
        return tree[k].sum;
    clear(k);
    int m = (L+R)/2;
    if (y <= m)
        return getsum(k<<1, L, m, x, y);
    if (x > m)
        return getsum(k<<1|1, m+1, R, x, y);
    return (getsum(k<<1, L, m, x, m)+getsum(k<<1|1, m+1, R, m+1, y))%mod;
}

int main()
{

    n = inp();
    mod = inp();
    for (int i = 1; i <= 100000; ++ i)
    {
        if (__gcd(i, mod) == 1)
        {
            ll x, y;
            exgcd(i, mod, x, y);
            rev[i] = (x%mod+mod)%mod;
        }
    }
    int tmp = mod;
    for (int i = 2; i*i <= tmp; ++ i)
    {
        if (tmp%i == 0)
        {
            prime.push_back(i);
            while (tmp%i == 0)
                tmp /= i;
        }
    }
    if (tmp > 1) prime.push_back(tmp);
    primes = prime.size();

    for (int k = 1; k <= n; ++ k)
    {
        a[k] = inp();
        for (int i = 0; i < primes; ++ i)
        {
            if (a[k]%prime[i] == 0)
            {
                int cnt = 0;
                while (a[k]%prime[i] == 0)
                {
                    cnt ++;
                    a[k] /= prime[i];
                }
                add(tot[i], k, k, cnt);
            }
        }
    }
    build(1, 1, n);

    int q = inp();
    while (q --)
    {
        int t = inp();
        if (t == 1)
        {
            int x = inp();
            int y = inp();
            int p = inp();
            int tmp = p;
            for (int i = 0; i < primes; ++ i)
                if (p%prime[i] == 0)
                {
                    int cnt = 0;
                    while (p%prime[i] == 0)
                    {
                        cnt ++;
                        p /= prime[i];
                    }
                    add(tot[i], x, y, cnt);
                }
            mul(1, 1, n, x, y, tmp, p);
        }
        else if (t == 2)
        {
            int x = inp();
            int p = inp();
            for (int i = 0; i < primes; ++ i)
                if (p%prime[i] == 0)
                {
                    int cnt = 0;
                    while (p%prime[i] == 0)
                    {
                        cnt ++;
                        p /= prime[i];
                    }
                    add(tot[i], x, x, -cnt);
                }
            a[x] = (ll)a[x]*rev[p]%mod;
            modify(1, 1, n, x);
        }
        else if (t == 3)
        {
            int x = inp();
            int y = inp();
            printf("%d\n", getsum(1, 1, n, x, y));
        }
    }

    return 0;
}