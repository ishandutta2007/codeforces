#include <bits/stdc++.h>
using namespace std;
const int maxN = 2 * (int)1e5 + 10;
map < pair < int, int >, int > edges;
set < int > s;
int n, m;
bool used[maxN];
int comp;
vector < int > ans;
void dfs(int v) {
    s.erase(v);
    comp++;
    used[v] = true;
    int prv = 0;
    while (s.size() > 0) {
        auto it = s.upper_bound(prv);
        if (it == s.end()) break;
        int to = *it;
        if (edges[minmax(v, to)] == 1) {
            prv = to;
            continue;
        }
        else dfs(to);
        prv = to;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        edges[minmax(x, y)] = 1;
    }
    for (int i = 1; i <= n; i++) s.insert(i);
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            if (comp != 0) ans.push_back(comp);
            comp = 0;
            dfs(i);
        }
    }
    ans.push_back(comp);
    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    return 0;
}