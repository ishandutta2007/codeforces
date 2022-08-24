#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define left  rwrwerrw
#define right gagoaosag
int n, k, m;
const int maxN = 2 * (int)1e5 + 10;
pair < int, int >  edges[maxN];
vector < pair < int, int > > g[maxN];
bool del[maxN];
int ans[maxN];
int deg[maxN];
int main() {
    srand(time(0));
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        edges[i] = make_pair(x, y);
        deg[x]++;
        deg[y]++;
        g[x].push_back(make_pair(y, i));
        g[y].push_back(make_pair(x, i));
    }
    queue < int > q;
    int sz = n;
    for (int i = 1; i <= n; i++) {
        if (deg[i] < k) {
            del[i] = true;
            q.push(i);
        }
    }
    sz -= q.size();
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        deg[v] = 0;
        for (auto t : g[v]) {
            int to = t.first;
            deg[to]--;
            if (del[to]) continue;
            if (deg[to] < k) {
                del[to] = true;
                sz--;
                q.push(to);
            }
        }
    }
    for (int i = m; i >= 1; i--) {
        ans[i] = sz;
        int x = edges[i].first;
        int y = edges[i].second;
        if (del[x] || del[y]) continue;
        deg[x]--;
        deg[y]--;
        queue < int > q;
        if (deg[x] < k) {
            del[x] = true;
            q.push(x);
        }
        if (deg[y] < k) {
            del[y] = true;
            q.push(y);
        }
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            sz--;
            for (auto t : g[v]) {
                if (t.second >= i) continue;
                int to = t.first;
                if (del[to]) continue;
                deg[to]--;
                if (deg[to] < k) {
                    del[to] = true;
                    q.push(to);
                }
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}