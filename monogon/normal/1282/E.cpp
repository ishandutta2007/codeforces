
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5;
int t, n, a[3];
vector<int> adj[N], adj2[N];
map<pair<int, int>, int> m;
bool vis[N];

void dfs(int x) {
    vis[x] = true;
    for(int y : adj[x]) {
        if(!vis[y]) {
            dfs(y);
        }
    }
    cout << x << " ";
}
void dfs2(int x) {
    vis[x] = true;
    for(int y : adj2[x]) {
        if(!vis[y]) {
            dfs2(y);
        }
    }
    cout << x << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        m.clear();
        for(int i = 1; i <= n - 2; i++) {
            adj[i].clear();
            cin >> a[0] >> a[1] >> a[2];
            sort(a, a + 3);
            if(m.count({a[0], a[1]})) {
                int j = m[{a[0], a[1]}];
                adj[i].push_back(j);
                adj[j].push_back(i);
                m.erase({a[0], a[1]});
            }else m[{a[0], a[1]}] = i;
            if(m.count({a[0], a[2]})) {
                int j = m[{a[0], a[2]}];
                adj[i].push_back(j);
                adj[j].push_back(i);
                m.erase({a[0], a[2]});
            }else m[{a[0], a[2]}] = i;
            if(m.count({a[1], a[2]})) {
                int j = m[{a[1], a[2]}];
                adj[i].push_back(j);
                adj[j].push_back(i);
                m.erase({a[1], a[2]});
            }else m[{a[1], a[2]}] = i;
        }
        for(int i = 1; i <= n; i++) {
            adj2[i].clear();
        }
        while(!m.empty()) {
            auto [x, y] = m.begin()->first;
            m.erase(m.begin());
            adj2[x].push_back(y);
            adj2[y].push_back(x);
        }
        fill(vis + 1, vis + n + 1, false);
        dfs2(1);
        cout << endl;
        fill(vis + 1, vis + n + 1, false);
        dfs(1);
        cout << endl;
    }
}