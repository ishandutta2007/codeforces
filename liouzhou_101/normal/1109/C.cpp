// #pragma GCC optimize("Ofast")

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
const int MOD = 1000000007;
const f80 MI = f80(1)/MOD;
const int INF = 1000000000;

int tot;

struct node
{
    node *Lc, *Rc;
    int flag, set;
    ll sum, Lsum;
}nodes[MAXN*70];

node *new_node()
{
    return &nodes[++ tot];
}

void clear(node *p, int L, int R)
{
    if (p->flag)
    {
        int m = (L+R)/2;
        p->flag = 0;
        if (!p->Lc) p->Lc = new_node();
        if (!p->Rc) p->Rc = new_node();
        p->Lc->flag = p->Rc->flag = 1;
        p->Lc->set = p->Rc->set = p->set;
        p->Lc->sum = (ll)(m-L+1)*p->set;
        p->Lc->Lsum = p->set >= 0 ? 0 : p->Lc->sum;
        p->Rc->sum = (ll)(R-m)*p->set;
        p->Rc->Lsum = p->set >= 0 ? 0 : p->Rc->sum;
    }
}

void update(node *p)
{
    if (!p->Lc) p->Lc = new_node();
    if (!p->Rc) p->Rc = new_node();
    p->sum = p->Lc->sum+p->Rc->sum;
    p->Lsum = min(p->Lc->Lsum, p->Lc->sum+p->Rc->Lsum);
}

void modify(node *p, int L, int R, int x, int y, int v)
{
    if (L == x && R == y)
    {
        p->flag = 1;
        p->set = v;
        p->sum = (ll)(R-L+1)*v;
        p->Lsum = v >= 0 ? 0 : p->sum;
        return;
    }
    clear(p, L, R);
    int m = (L+R)/2;
    if (y <= m)
    {
        if (!p->Lc) p->Lc = new_node();
        modify(p->Lc, L, m, x, y, v);
    }
    else if (x > m)
    {
        if (!p->Rc) p->Rc = new_node();
        modify(p->Rc, m+1, R, x, y, v);
    }
    else
    {
        if (!p->Lc) p->Lc = new_node();
        if (!p->Rc) p->Rc = new_node();
        modify(p->Lc, L, m, x, m, v);
        modify(p->Rc, m+1, R, m+1, y, v);
    }
    update(p);
}

pair<ld, ll> query(node *p, int L, int R, int x, int y, ll v)
{
    if (L == x && R == y)
    {
        if (p->Lsum+v > 0)
            return pair<ld, ll>(-1, p->sum);
        if (L == R)
            return pair<ld, ll>(L-(ld)v/p->sum, p->sum);
        if (p->flag)
            return pair<ld, ll>(L-(ld)v/(p->sum/(R-L+1)), p->sum);
        int m = (L+R)/2;
        if (!p->Lc) p->Lc = new_node();
        if (!p->Rc) p->Rc = new_node();
        auto Lans = query(p->Lc, L, m, x, m, v);
        if (Lans.first > 0)
            return Lans;
        else
        {
            auto Rans = query(p->Rc, m+1, R, m+1, y, Lans.second+v);
            return pair<ld, ll>(Rans.first, Lans.second+Rans.second);
        }
    }
    clear(p, L, R);
    int m = (L+R)/2;
    if (y <= m)
    {
        if (!p->Lc) p->Lc = new_node();
        return query(p->Lc, L, m, x, y, v);
    }
    else if (x > m)
    {
        if (!p->Rc) p->Rc = new_node();
        return query(p->Rc, m+1, R, x, y, v);
    }
    else
    {
        if (!p->Lc) p->Lc = new_node();
        if (!p->Rc) p->Rc = new_node();
        auto Lans = query(p->Lc, L, m, x, m, v);
        if (Lans.first > 0)
            return Lans;
        else
        {
            auto Rans = query(p->Rc, m+1, R, m+1, y, Lans.second+v);
            return pair<ld, ll>(Rans.first, Lans.second+Rans.second);
        }
    }
}

int main()
{

    int q = inp();
    map<int, int> H;
    int L = 1, R = 1000000010;
    H[L-1] = H[R+1] = 0;
    node *root = new_node();
    while (q --)
    {
        int t = inp();
        if (t == 1)
        {
            int x = inp();
            int y = inp();
            H[x] = y;
            auto it = H.find(x);
            ++ it;
            modify(root, L, R-1, x, min(it->X, R)-1, y);
        }
        else if (t == 2)
        {
            int x = inp();
            auto it = H.find(x);
            auto ity = it;
            ++ ity;
            auto itx = it;
            -- itx;
            modify(root, L, R-1, x, min(ity->X, R)-1, itx->Y);
            H.erase(x);
        }
        else if (t == 3)
        {
            int x = inp();
            int y = inp();
            int v = inp();
            if (v == 0)
                printf("%d\n", x);
            else
            {
                auto it = H.lower_bound(x);
                x = it->X;
                if (x >= y)
                    puts("-1");
                else
                {
                    auto ans = query(root, L, R-1, x, y-1, v);
                    if (ans.first < 0)
                        puts("-1");
                    else
                       printf("%.8f\n", ans.first);
                }
            }
        }
    }

    return 0;
}