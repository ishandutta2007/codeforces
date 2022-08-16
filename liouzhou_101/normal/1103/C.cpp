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

const int MAXN = 250010;
const int MAXP = 10000000;
const int MOD = 1000000007;
const f80 MI = f80(1)/MOD;
const ll INF = 10000000000000000LL;
const ll inf = 5000000000000LL;

int n, m, k;
vector<int> v[MAXN], son[MAXN];
int u[MAXN], pre[MAXN], dis[MAXN];

void dfs(int x)
{
    u[x] = 1;
    for (auto y : v[x])
    {
        if (u[y]) continue;
        son[x].push_back(y);
        pre[y] = x;
        dis[y] = dis[x]+1;
        dfs(y);
    }
}

int main()
{

    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; ++ i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);
    int limit = (n-1)/k+1;
    for (int i = 1; i <= n; ++ i)
        if (dis[i]+1 >= limit)
        {
            puts("PATH");
            printf("%d\n", dis[i]+1);
            for (; i; i = pre[i])
                printf("%d ", i);
            return 0;
        }
    puts("CYCLES");
    for (int i = 1; i <= n; ++ i)
        if (son[i].empty())
        {
            vector<int> a;
            for (auto j : v[i])
                if (j != pre[i]) a.push_back(j);
            int x = a[0], y = a[1];
            if (dis[x] < dis[y]) swap(x, y);
            if ((dis[i]-dis[x]+1)%3 != 0)
            {
                printf("%d\n", dis[i]-dis[x]+1);
                for (int p = i; p != x; p = pre[p])
                    printf("%d ", p);
                printf("%d\n", x);
            }
            else if ((dis[i]-dis[y]+1)%3 != 0)
            {
                printf("%d\n", dis[i]-dis[y]+1);
                for (int p = i; p != y; p = pre[p])
                    printf("%d ", p);
                printf("%d\n", y);
            }
            else if ((dis[x]-dis[y]+2)%3 != 0)
            {
                printf("%d\n", dis[x]-dis[y]+2);
                printf("%d ", i);
                for (int p = x; p != y; p = pre[p])
                    printf("%d ", p);
                printf("%d\n", y);
            }
            -- k;
            if (k == 0) break;
        }

    return 0;
}