
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n, u, v;
vector<int> adj[N];
int par[N], deep[N], deepup[N], vdeep[N], vdeepup[N], deg[N];
bool vis[N];

int dfs(int x, int p) {
    par[x] = p;
    vis[x] = true;
    for(int y : adj[x]) {
        if(!vis[y]) {
            int d = dfs(y, x);
            if(1 + d > deep[x]) {
                deep[x] = 1 + d;
                vdeep[x] = vdeep[y];
            }
        }
    }
    return deep[x];
}
void dfs2(int x) {
    int z = -1;
    for(int y : adj[x]) {
        if(1 + deepup[x] > deepup[y]) {
            deepup[y] = 1 + deepup[x];
            vdeepup[y] = vdeepup[x];
        }
        if(deep[y] + 1 == deep[x]) {
            z = y;
            break;
        }
    }
    int w = -1;
    for(int y : adj[x]) {
        if(y != z) {
            if(1 + deep[x] > deepup[y]) {
                deepup[y] = 1 + deep[x];
                vdeepup[y] = vdeep[z];
            }
            if(w == -1 || deep[y] > deep[w]) w = y;
        }
    }
    if(w != -1 && 2 + deep[w] > deepup[z]) {
        deepup[z] = 2 + deep[w];
        vdeepup[z] = vdeep[w];
    }
    for(int y : adj[x]) {
        dfs2(y);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        vdeepup[i] = vdeep[i] = i;
    }
    for(int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 0; i < n; i++) {
        deg[i] = adj[i].size();
    }
    dfs(0, -1);
    for(int i = 1; i < n; i++) {
        adj[i].erase(find(adj[i].begin(), adj[i].end(), par[i]));
    }
    dfs2(0);
    vector<pair<int, int>> vec;
    int ans = -1, v[3];
    for(int i = 0; i < n; i++) {
        vec.clear();
        vec.emplace_back(deepup[i], vdeepup[i]);
        for(int y : adj[i]) {
            vec.emplace_back(1 + deep[y], vdeep[y]);
        }
        if(vec.size() < 3) continue;
        sort(vec.begin(), vec.end());
        int sum = 0;
        for(int j = 0; j < 3; j++) {
            sum += vec[(int) vec.size() - j - 1].first;
        }
        if(sum > ans) {
            ans = sum;
            for(int j = 0; j < 3; j++) {
                v[j] = vec[(int) vec.size() - j - 1].second;
            }
        }
    }
    if(ans == -1) {
        cout << n - 1 << endl;
        int a = -1, b = -1, c = -1;
        for(int i = 0; i < n; i++) {
            if(deg[i] == 1 && a == -1) {
                a = i;
            }else if(deg[i] == 1) b = i;
            else c = i;
        }
        cout << a + 1 << " " << b + 1 << " " << c + 1 << endl;
    }else {
        cout << ans << endl << v[0] + 1 << " " << v[1] + 1 << " " << v[2] + 1 << endl;
    }
}