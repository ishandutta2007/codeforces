#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cassert>
#include <queue>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> pii;

const int maxn = 100100;

int n, m;
vector<pii> adj[maxn];

int dist[maxn];

void bfs() {
    queue<int> que;
    que.push(0);
    memset(dist, -1, sizeof(dist));
    for (int t=0; !que.empty(); t++) {
        int sze = que.size();
        for (int i=0; i<sze; i++) {
            int x = que.front(); que.pop();
            if (dist[x] != -1) continue;
            dist[x] = t;
            for (pii y : adj[x]) que.push(y.fi);
        }
    }
}

vector<int> v;
int dist2[maxn], par[maxn];

void bfs2() {
    queue<pii> que;
    que.push(pii(n-1, -1));
    memset(par, -1, sizeof(par));
    memset(dist2, -1, sizeof(dist2));
    for (int t=0; !que.empty(); t++) {
        int sze = que.size();
        for (int i=0; i<sze; i++) {
            int x = que.front().fi, y = que.front().se; que.pop();
            if (dist2[x] != -1) continue;
            dist2[x] = t, par[x] = y;
            v.push_back(x);
            for (pii j : adj[x])
                if (j.se == 0)
                    que.push(pii(j.fi, x));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(pii(b, c));
        adj[b].push_back(pii(a, c));
    }

    bfs();
    bfs2();

    while (1) {
        bool brk = 0;
        for (int i : v)
            if (i == 0) brk = 1;

        if (brk) break;

        int mi = 1e9;
        for (int i : v)
            for (pii j : adj[i])
                mi = min(mi, dist[j.fi]);

        int mi2 = 10;
        for (int i : v)
            for (pii j : adj[i])
                if (dist[j.fi] == mi)
                    mi2 = min(mi2, j.se);

        vector<int> v2;
        for (int i : v)
            for (pii j : adj[i])
                if (dist[j.fi] == mi && j.se == mi2) {
                    if (par[j.fi] == -1) par[j.fi] = i, v2.push_back(j.fi);
                    else if (dist2[i] < dist2[par[j.fi]]) par[j.fi] = i;
                    dist2[j.fi] = dist2[par[j.fi]] + 1;
                }

        v = v2;
    }

    vector<int> ans, ans2;
    int cur = 0;
    ans.push_back(cur);
    while (cur != n-1) {
        int x = par[cur];
        for (pii i : adj[cur])
            if (i.fi == x) ans2.push_back(i.se);
        ans.push_back(x);
        cur = x;
    }

    bool b = 0;
    for (int i=ans2.size()-1; i>=0; i--) {
        if (ans2[i]) b = 1;
        if (b) cout << ans2[i];
    }
    if (!b) cout << 0;
    cout << '\n';

    cout << ans.size() << '\n';
    for (int i : ans) cout << i << ' ';
    cout << '\n';
}