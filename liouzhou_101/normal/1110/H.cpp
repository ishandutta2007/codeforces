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

const int MAXN = 2010;
const int MAXM = 10;
const int MAXT = 18010;
const int MOD = 1000000007;
const f80 MI = f80(1)/MOD;
const int INF = 1000000000;

int tot;

struct node
{
    node *pre, *next[MAXM];
    int count[MAXN], dp[MAXN], ok[MAXN];
}nodes[MAXT];

node *new_node()
{
    return &nodes[++ tot];
}

node *root;

node *trans(node *x, int a)
{
    if (!x->next[a]) x->next[a] = new_node();
    return x->next[a];
}

int n, m, len;
char s[MAXN], t[MAXN];

void build()
{
    root = new_node();
    if (n == m)
    {
        node *x = root, *y = root;
        for (int i = 1; i <= n; ++ i)
        {
            if (x == y)
            {
                for (int j = s[i]+1; j < t[i]; ++ j)
                    trans(x, j)->count[n-i] ++;
            }
            else
            {
                for (int j = s[i]+1; j < MAXM; ++ j)
                    trans(x, j)->count[n-i] ++;
                for (int j = 0; j < t[i]; ++ j)
                    trans(y, j)->count[n-i] ++;
            }
            x = trans(x, s[i]);
            y = trans(y, t[i]);
        }
        x->count[0] ++;
        if (x != y) y->count[0] ++;
    }
    else
    {
        node *x = root, *y = root;
        for (int i = 1; i <= n; ++ i)
        {
            for (int j = s[i]+1; j < MAXM; ++ j)
                trans(x, j)->count[n-i] ++;
            x = trans(x, s[i]);
        }
        x->count[0] ++;
        for (int i = 1; i <= m; ++ i)
        {
            for (int j = 0; j < t[i]; ++ j)
            {
                if (y == root && j == 0)
                {
                    for (int k = 1; k < MAXM; ++ k)
                        trans(y, k)->count[m-i-1];
                }
                else
                    trans(y, j)->count[m-i] ++;
            }
            y = trans(y, t[i]);
        }
        y->count[0] ++;
        for (int i = n+1; i < m; ++ i)
            for (int j = 1; j < MAXM; ++ j)
                trans(root, j)->count[i-1] ++;
    }
    queue<node*> Q;
    root->pre = root;
    for (int j = 0; j < MAXM; ++ j)
        if (root->next[j])
        {
            root->next[j]->pre = root;
            Q.push(root->next[j]);
        }
        else
            root->next[j] = root;
    while (!Q.empty())
    {
        node *x = Q.front();
        Q.pop();
        for (int j = 0; j < MAXM; ++ j)
        {
            if (!x->next[j])
                x->next[j] = x->pre->next[j];
            else
            {
                x->next[j]->pre = x->pre->next[j];
                Q.push(x->next[j]);
            }
        }
        for (int j = 0; j <= len; ++ j)
            x->count[j] += x->pre->count[j];
    }
    for (int i = 1; i <= tot; ++ i)
    {
        node *x = nodes+i;
        for (int j = 1; j <= len; ++ j)
            x->count[j] += x->count[j-1];
    }
}

void solve()
{
    for (int k = 1; k <= tot; ++ k)
    {
        node *x = nodes+k;
        for (int i = 0; i <= len; ++ i)
            x->dp[i] = -INF;
    }
    root->dp[0] = 0;
    for (int i = 0; i <= len; ++ i)
    {
        for (int k = 1; k <= tot; ++ k)
        {
            node *x = nodes+k;
            x->dp[i] += x->count[len-i];
            for (int j = 0; j < MAXM; ++ j)
                freshmax(x->next[j]->dp[i+1], x->dp[i]);
        }
    }
    int ans = 0;
    for (int k = 1; k <= tot; ++ k)
    {
        node *x = nodes+k;
        freshmax(ans, x->dp[len]);
    }
    printf("%d\n", ans);
    for (int k = 1; k <= tot; ++ k)
    {
        node *x = nodes+k;
        if (x->dp[len] == ans) x->ok[len] = 1;
    }
    for (int i = len-1; i >= 0; -- i)
        for (int k = 1; k <= tot; ++ k)
        {
            node *x = nodes+k;
            for (int j = 0; j < MAXM; ++ j)
            {
                if (x->next[j]->ok[i+1] && x->dp[i]+x->next[j]->count[len-i-1] == x->next[j]->dp[i+1])
                    x->ok[i] = 1;
            }
        }
    node *x = root;
    for (int i = 1; i <= len; ++ i)
    {
        for (int j = 0; j < MAXM; ++ j)
            if (x->next[j]->ok[i] && x->dp[i-1]+x->next[j]->count[len-i] == x->next[j]->dp[i])
            {
                printf("%d", j);
                x = x->next[j];
                break;
            }
    }
}

int main()
{

    scanf("%s%s%d", s+1, t+1, &len);
    n = strlen(s+1);
    m = strlen(t+1);
    for (int i = 1; i <= n; ++ i) s[i] -= '0';
    for (int i = 1; i <= m; ++ i) t[i] -= '0';
    build();
    solve();

    return 0;
}