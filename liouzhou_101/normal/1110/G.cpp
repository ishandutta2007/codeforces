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

const int MAXN = 2000010;
const int MAXM = 310;
const int MAXK = 17;
const int MOD = 1000000007;
const f80 MI = f80(1)/MOD;
const ll INF = 10000000000000000LL;
const int inf = 1000000000;

int n;
vector<int> v[MAXN];
char s[MAXN];

void clear()
{
    for (int i = 1; i <= n*4; ++ i)
        v[i].clear();
}

void addedge(int x, int y)
{
    v[x].push_back(y);
    v[y].push_back(x);
}

int d[MAXN];

bool solve()
{
    for (int i = 1; i <= n; ++ i)
        if (v[i].size() >= 4) return 1;
    vector<int> p;
    for (int i = 1; i <= n; ++ i)
        if (v[i].size() == 3)
        {
            int a = v[i][0], b = v[i][1], c = v[i][2];
            if ((v[a].size() >= 2)+(v[b].size() >= 2)+(v[c].size() >= 2) >= 2) return 1;
            p.push_back(i);
        }
    if (p.size() >= 3) return 1;
    if (p.size() <= 1) return 0;
    int a = p[0], b = p[1];
    for (int i = 1; i <= n; ++ i)
        d[i] = inf;
    d[a] = 0;
    queue<int> Q;
    Q.push(a);
    while (!Q.empty())
    {
        int x = Q.front();
        Q.pop();
        for (auto y : v[x])
            if (d[y] > d[x]+1)
            {
                d[y] = d[x]+1;
                Q.push(y);
            }
    }
    return d[b]%2 == 0;
}

int main()
{

    int T;
    scanf("%d", &T);
    while (T --)
    {
        scanf("%d", &n);
        clear();
        for (int i = 1; i < n; ++ i)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            addedge(x, y);
        }
        scanf("%s", s+1);
        int tot = n;
        for (int i = 1; i <= n; ++ i)
            if (s[i] == 'W')
            {
                int a = ++ tot;
                int b = ++ tot;
                int c = ++ tot;
                addedge(i, a);
                addedge(a, b);
                addedge(a, c);
            }
        n = tot;
        puts(solve() ? "White" : "Draw");
    }

    return 0;
}