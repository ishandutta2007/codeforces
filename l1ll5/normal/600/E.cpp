#include <bits/stdc++.h>
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define INF 0x3f3f3f3f
using namespace std;

const int maxn = 100010;
vector<int> g[maxn];
int Max,col[maxn];
long long sum,ans[maxn];
/****************dsu on tree ************************/
int sz[maxn];
void getsz(int v, int p) {//
    sz[v] = 1;
    for (auto u : g[v])
        if (u != p) {
            getsz(u, v);
            sz[v] += sz[u];
        }
}
int cnt[maxn];
bool big[maxn];
void add(int v, int p, int x) {
    cnt[ col[v] ] += x;
    if (cnt[col[v]] > Max)
        sum = col[v], Max = cnt[col[v]];
    else if (cnt[col[v]] == Max)
        sum += col[v];
    for (auto u : g[v])
        if (u != p && !big[u])
            add(u, v, x);
}
void dfs(int v, int p, int keep) {//
    int mx = -1, bigChild = -1;
    for (auto u : g[v])
        if (u != p && sz[u] > mx)
            mx = sz[u], bigChild = u;
    for (auto u : g[v])
        if (u != p && u != bigChild)
            dfs(u, v, 0);
    if (bigChild != -1)
        dfs(bigChild, v, 1), big[bigChild] = 1;
    add(v, p, 1);
    if (bigChild != -1)
        big[bigChild] = 0;
    ans[v] = sum;
    if (keep == 0)
        add(v, p, -1), Max = sum = 0;
}
/****************dsu on tree ************************/
int main(void) {

    int n, t1, t2;
    cin >> n;
    for (int i = 1; i <=n; i++)
        cin >> col[i];
    for (int i = 1; i < n; i++)
        cin >> t1 >> t2, g[t1].push_back(t2), g[t2].push_back(t1);
    getsz(1, 0);
    dfs(1, 0, 1);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    return 0;
}