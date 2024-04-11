#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

const ll INF = 0x3FFFFFFFFFFFFFFFLL;
int n, a[200010];
ll ans[200010], dp[200010], sum[200010], Ans;
vector<int> g[200010];
multiset<ll, greater<ll> > s;
multiset<ll, greater<ll> > :: iterator it;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

void dfs(int u,int fa)
{
    sum[u] = a[u];
    int m = g[u].size();
    for(int i = 0; i < m; i ++)
    {
        int v = g[u][i];
        if(v == fa) continue;
        dfs(v, u);
        sum[u] += sum[v];
    }
    dp[u] = sum[u];
    s.clear();
    for(int i = 0; i < m; i ++)
    {
        int v = g[u][i];
        if(v == fa) continue;
        s.insert(dp[v]);
        dp[u] = max(dp[v], dp[u]);
    }
    if(s.size() >= 2)
    {
        it = s.begin();
        ans[u] = *it;
        ans[u] += *(++ it);
        Ans = max(ans[u], Ans);
    }
}

int main()
{
    n = read();
    for(int i = 1; i <= n; i ++) a[i] = read();
    for(int i = 1; i < n; i ++)
    {
        int x,y;
        x = read();
        y = read();
        g[x].pb(y);
        g[y].pb(x);
    }
    Ans = -INF;
    dfs(1, 0);
    if(Ans == -INF) printf("Impossible\n");
    else printf("%I64d\n",Ans);
    return 0;
}