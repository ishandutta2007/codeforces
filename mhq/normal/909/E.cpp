#include <bits/stdc++.h>
using namespace std;
int n, m;
const int maxN = (int)1e5 + 10;
int type[maxN];
int deg[maxN];
vector < int > g[maxN];
queue < int > p1;
queue < int > p2;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> type[i];
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        deg[y]++;
    }
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0 && type[i] == 0) p1.push(i);
        if (deg[i] == 0 && type[i] == 1) p2.push(i);
    }
    int ans = 0;
    while (!p1.empty() || !p2.empty()) {
        while (!p1.empty()) {
            int x = p1.front();
            p1.pop();
            for (int i = 0; i < g[x].size(); i++) {
                int to = g[x][i];
                deg[to]--;
                if (deg[to] == 0) {
                    if (type[to] == 0) p1.push(to);
                    else p2.push(to);
                }
            }
        }
        if (!p2.empty()) {
            ans++;
            while (!p2.empty()) {
                int x = p2.front();
                p2.pop();
                for (int i = 0; i < g[x].size(); i++) {
                    int to = g[x][i];
                    deg[to]--;
                    if (deg[to] == 0) {
                        if (type[to] == 0) p1.push(to);
                        else p2.push(to);
                    }
                }
            }
        }
    }
    cout << ans;
}