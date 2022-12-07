/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2019-09-18
File: F.cpp
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

#define IN freopen("sample.in", "r", stdin)
#define OUT freopen("sample.out", "w", stdout)
#define scd(x) scanf("%d", &x)
#define scld(x) scanf("%lld", &x)
#define scs(x) scanf("%s", x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define prcas printf("Case #%d: ", cas)
#define pncas printf("Case #%d:\n", cas)
#define lowbit(x) ((x) & (-x))
#define fi first
#define se second
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef vector<int> vi;

bool vis[100005];
pii pre[100005];
int n, dis[100005], m;
vi g;
priority_queue< pii > q;

int main()
{	
    scd(n);
    for(int i = 2; i * i <= n; ++ i)
    {
        if(n % i > 0) continue;
        g.pb(i); if(i * i < n) g.pb(n / i);
    }
    m = g.size(); if(m == 0) {puts("NO"); return 0;}
    sort(g.begin(), g.end()); 
    for(int i = 0; i < g[0]; ++ i) vis[i] = false, dis[i] = 1e9 + 7, pre[i] = mp(-1, -1);
    dis[0] = 0; pre[0] = mp(0, 0);
    while(!q.empty()) q.pop(); q.push(mp(0, 0));
    while(!q.empty())
    {
        pii t = q.top(); q.pop();
        int d = -t.fi, id = t.se;
        vis[id] = true;
        for(int i = 1; i < m; ++ i)
        {
            int r = (id + g[i]) % g[0];
            if(dis[r] > d + g[i])
            {
                dis[r] = d + g[i];
                pre[r] = mp(id, g[i]);
                q.push(mp(-dis[r], r));
            }
        }
        while(!q.empty() && vis[q.top().se]) q.pop();
    }
    if(dis[(n - 1) % g[0]] > n - 1) {puts("NO"); return 0;}
    vi ans; ans.clear();
    int now = (n - 1) % g[0], sum = 0;
    while(now > 0)
    {
        sum += pre[now].se;
        ans.pb(pre[now].se);
        now = pre[now].fi;
    }
    int bb = 1, bg = 0, cnt = 0;
    if(sum < n - 1)
    {
        bb = 0;
        bg = g[0];
        cnt = (n - 1 - sum) / g[0];
    }else {bg = ans[0]; cnt = 1;}
    sort(ans.begin(), ans.end());
    puts("YES");
    vector< pii > ret; ret.clear();
    for(int i = bb; i < ans.size(); ++ i)
        if(ans[i] != bg)
        {
            cnt *= bg;
            int tt = __gcd(n, cnt);
            ret.pb(mp(cnt / tt, n / tt));
            bg = ans[i]; cnt = 1;
        }else cnt ++;
    cnt *= bg;
    ret.pb(mp(cnt / __gcd(cnt, n), n / __gcd(cnt, n)));
    printf("%d\n", (int)ret.size());
    for(pii p : ret) printf("%d %d\n", p.fi, p.se);
    return 0;
}