/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2019-11-01
File: D.cpp
*****************************************/
  
#include<bits/stdc++.h>
  
using namespace std;
  
const double eps = 1e-10;
const double pi = 3.1415926535897932384626433832795;
const double eln = 2.718281828459045235360287471352;

#ifdef __LOCAL_DEBUG__
# define _debug(fmt, ...) fprintf(stderr, "[%s] " fmt "\n", \
    __func__, ##__VA_ARGS__)
#else
# define _debug(...) ((void) 0)
#endif

#define IN freopen("D.in", "r", stdin)
#define OUT freopen("D.out", "w", stdout)
#define scd(x) scanf("%d", &x)
#define scld(x) scanf("%lld", &x)
#define scs(x) scanf("%s", x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define prcas printf("Case #%d: ", cas)
#define pncas printf("Case #%d:\n", cas)
#define lowbit(x) ((x) & (-(x)))
#define fi first
#define se second
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef vector<int> vi;

const int maxn = 2005;
LL ans = 0, val[maxn];
LL c[maxn], k[maxn], x[maxn], y[maxn];
int n, fa[maxn];

struct edge
{
    int x, y; LL c;
    bool operator < (const struct edge &p) const {return c < p.c;}
};
vector<edge> cost;

inline LL aabs(LL x) {return x < 0 ? -x : x;}

int find(int t) {return fa[t] == t ? t : fa[t] = find(fa[t]);}

vector<pii> re;

int main()
{	
    scd(n);
    for(int i = 1; i <= n; ++ i) scanf("%lld%lld", &x[i], &y[i]);
    for(int i = 1; i <= n; ++ i) scld(c[i]), ans += c[i];
    for(int i = 1; i <= n; ++ i) scld(k[i]), fa[i] = i, val[i] = c[i];
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= n; ++ j)
        {
            LL d = aabs(x[i] - x[j]) + aabs(y[i] - y[j]);
            cost.pb({i, j, d * (k[i] + k[j])});
        }
    sort(cost.begin(), cost.end());
    for(edge p : cost)
    {
        int x = find(p.x), y = find(p.y);
        if(x == y) continue;
        LL tmp = max(val[x], val[y]);
        if(p.c >= tmp) continue;
        ans -= tmp; ans += p.c;
        if(val[x] > val[y]) fa[x] = fa[y]; else fa[y] = fa[x];
        re.pb(mp(p.x, p.y));
    }
    printf("%lld\n", ans);
    vi ret; ret.clear(); for(int i = 1; i <= n; ++ i) if(find(i) == i) ret.pb(i);
    printf("%d\n", (int)ret.size()); for(int i = 0; i < ret.size(); ++ i) {if(i > 0) putchar(' '); printf("%d", ret[i]);}
    printf("\n%d\n", (int)re.size()); for(pii p : re) printf("%d %d\n", p.fi, p.se);
    return 0;
}