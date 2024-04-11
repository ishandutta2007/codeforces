#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
using namespace std;
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
inline ll read1()
{
    ll x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
const int N = 2e5 + 10;

int n, m, k, deg[N];
vi e[N];
bool vis[N];

bool check(vi s)
 {
    if (s.size() * (s.size() - 1) / 2 > m) { return false; }
    for (auto u : s)
        for (auto v : s) 
        {
            if (u <= v) continue;
            auto it = lower_bound(ALL(e[u]), v);
            if (it == e[u].end() || *it != v) return false;
        }
    return true;
}

bool solve() 
{
    priority_queue<pii> que;
    rep(u, 1, n)
    {
        if (vis[u]) continue;
        que.push({-deg[u], u});
    }
    while (!que.empty()) 
    {
        int d = -que.top().X;
        int u = que.top().Y;
        que.pop();
        if (d != deg[u]) continue;
        if (d >= k) break;
        vis[u] = true;
        vi s;
        for (auto v : e[u]) 
            if (!vis[v]) 
            {
                deg[v] --;
                que.push({-deg[v], v});
                s.pb(v);
            }
        
        s.pb(u);
        if (s.size() == k && check(s)) 
        {
            printf("2\n");
            for (auto u : s) printf("%d ", u);
            printf("\n");
            return 1;
        }
    }
    bool flag = 1;
    int cnt = 0;
    rep(u, 1, n) if (!vis[u]) flag = 0, cnt ++;
    if (flag) return false; 
    printf("1 %d\n", cnt);
    rep(u, 1, n) if (!vis[u]) printf("%d ", u); 
    printf("\n");
    return true;
}

int main() 
{
	int T = read();
	while(T --)
	{
        n = read(); 
        m = read(); 
        k = read();
        rep(u, 1, n) e[u].clear(), deg[u] = 0;
        rep0(i, m)
        {
            int u = read();
            int v = read();
            e[u].pb(v); 
            e[v].pb(u);
            deg[u] ++; 
            deg[v] ++;
        }
        priority_queue<pii> que;
        rep(u, 1, n)
        {
            sort(e[u].begin(), e[u].end());
            que.push({-deg[u], u});
            vis[u] = false;
        }
        while (!que.empty()) 
        {
            int d = -que.top().X;
            int u = que.top().Y;
            que.pop();
            if (d != deg[u]) continue;
            if (d >= k - 1) break;
            vis[u] = true;
            for (auto v : e[u]) 
                if (!vis[v]) 
                {
                    deg[v] --;
                    que.push({-deg[v], v});
                }
            
        }
        bool flag = true;
        rep(u, 1, n) if (!vis[u]) { flag = false; break; }
        if (flag) { printf("-1\n"); continue; }
        if (!solve()) printf("-1\n"); 
    }
    return 0;
}