#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define fi first
#define se second

const int MAXN = 100100;

int n;

typedef pair<int, bool> pib;
vector<pib> adj[MAXN];

bool sub[MAXN];
int num[MAXN], cnt;

void dfs(int cur, int p) {
    for (int i=0; i<adj[cur].size(); i++) {
        if (adj[cur][i].fi == p) continue;
        dfs(adj[cur][i].fi, cur);
        if (adj[cur][i].se) {
            sub[cur] = 1;
            if (!sub[adj[cur][i].fi]) num[cnt++] = adj[cur][i].fi;
        }
        if (sub[adj[cur][i].fi]) sub[cur] = 1;
    }
}

int main() {
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        x--; y--; t--;
        adj[x].push_back(pib(y, t));
        adj[y].push_back(pib(x, t));
    }
    dfs(0, 0);
    cout << cnt << endl;
    for (int i=0; i<cnt; i++) cout << num[i] + 1 << ' ';
    cout << endl;
    return 0;
}