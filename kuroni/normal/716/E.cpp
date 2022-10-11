#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#define fi first
#define se second
#define mp make_pair
using namespace std;

const int N = 100005;

int n, m, u, v, w, sub[N];
bool chk[N];
long long ans = 0, inv[N], pw[N];
vector<pair<int, int>> adj[N];
map<long long, int> gbl, lcl;

long long inverse(int a, int b)
{
    return a == 0 ? 1 : (1 - inverse(b % a, a) * b) / a;
}

void init()
{
    long long ret = (inverse(10 % m, m) + m) % m;
    pw[0] = inv[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        pw[i] = pw[i - 1] * 10 % m;
        inv[i] = inv[i - 1] * ret % m;
    }
}

int DFS(int u, int p = 0)
{
    sub[u] = 1;
    for (pair<int, int> &v : adj[u])
        if (!chk[v.fi] && v.fi != p)
            sub[u] += DFS(v.fi, u);
    return sub[u];
}

void get_ans(int u, int p, long long cur, int h, map<long long, int> &hsh)
{
    ans += hsh[(m - cur) * inv[h] % m];
    for (pair<int, int> &v : adj[u])
        if (!chk[v.fi] && v.fi != p)
            get_ans(v.fi, u, (cur * 10 + v.se) % m, h + 1, hsh);
}

void save_hash(int u, int p, long long cur, int h)
{
    gbl[cur]++; lcl[cur]--;
    for (pair<int, int> &v : adj[u])
        if (!chk[v.fi] && v.fi != p)
            save_hash(v.fi, u, (cur + v.se * pw[h]) % m, h + 1);
}

void solve(int u, int sz)
{
    if (sz == 1)
        return;

    // find the centroid of the current subtree
    int pre = 0;
    DFS(u);
    bool cen = false;
    while (!cen)
    {
        cen = true;
        for (pair<int, int> &v : adj[u])
            if (!chk[v.fi] && v.fi != pre && sub[v.fi] > sz / 2)
            {
                pre = u;
                u = v.fi;
                cen = false;
                break;
            }
    }

    // solve taking the centroid as the root of the current subtree
    gbl[0] = 1;
    for (pair<int, int> &v : adj[u])
        if (!chk[v.fi])
        {
            save_hash(v.fi, u, v.se, 1);
            get_ans(v.fi, u, v.se, 1, lcl);
            lcl.clear();
        }
    for (pair<int, int> &v : adj[u])
        if (!chk[v.fi])
            get_ans(v.fi, u, v.se, 1, gbl);
    ans += gbl[0] - 1;
    gbl.clear();
    
    // mark the current centroid and break down into subtrees
    chk[u] = true;
    for (pair<int, int> &v : adj[u])
        if (!chk[v.fi])
            solve(v.fi, v.fi == pre ? sz - sub[u] : sub[v.fi]);
}

int main()
{
    scanf("%d%d", &n, &m);
    init();
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        ++u; ++v; w %= m;
        adj[u].push_back(mp(v, w));
        adj[v].push_back(mp(u, w));
    }
    solve(1, n);
    printf("%lld", ans);
}