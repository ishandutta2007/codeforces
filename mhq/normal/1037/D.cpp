#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 2 * (int)1e5 + 10;
vector < int > dist[maxN];
vector < int > g[maxN];
bool used[maxN];
int n;
int h[maxN];
int prv[maxN];
void dfs(int v, int p = -1) {
    dist[h[v]].push_back(v);
    for (int to : g[v]) {
        if (to == p) continue;
        h[to] = h[v] + 1;
        prv[to] = v;
        dfs(to, v);
    }
}
int a[maxN];
vector < int > need_dist[maxN];
void no() {
    cout << "No";
    exit(0);
}
int pos[maxN];
bool cmp(int x, int y) {
    return pos[x] < pos[y];
}
int main() {
    srand(time(0));
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for (int i = 1; i + 1 <= n; i++) {
        if (h[a[i]] > h[a[i + 1]]) no();
    }
    for (int i = 1; i <= n; i++) {
        if (dist[i].empty()) break;
        sort(dist[i].begin(), dist[i].end(), cmp);
        for (int j = 0; j + 1 < dist[i].size(); j++) {
            if (pos[prv[dist[i][j]]] > pos[prv[dist[i][j + 1]]]) no();
        }
    }
    cout << "Yes";
    return 0;
}