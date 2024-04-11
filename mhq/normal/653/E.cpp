#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
set < int > hz;
int n, m, k;
const int maxN = 3 * (int)1e5 + 10;
vector < int > bad[maxN];
bool has(int v, int u) {
    int ind = lower_bound(bad[v].begin(), bad[v].end(), u) - bad[v].begin();
    return (ind == bad[v].size() || bad[v][ind] != u);
}
int num[maxN];
int cmp = 0;
void dfs(int v) {
    num[v] = cmp;
    if (!hz.empty()) {
        int lst = *hz.begin();
        while (true) {
            if (has(v, lst)) {
                hz.erase(lst);
                dfs(lst);
            }
            auto it = hz.upper_bound(lst);
            if (it == hz.end()) break;
            lst = *it;
        }
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        bad[a].push_back(b);
        bad[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) sort(bad[i].begin(), bad[i].end());
    for (int i = 2; i <= n; i++) {
        hz.insert(i);
    }
    for (int i = 2; i <= n; i++) {
        if (num[i] != 0) continue;
        cmp++;
        hz.erase(i);
        dfs(i);
    }
    set < int > dif_cmp;
    set < int > dif_all;
    for (int i = 2; i <= n; i++) {
        if (has(1, i)) dif_cmp.insert(num[i]), dif_all.insert(i);
    }
    if (dif_all.size() < k) {
        cout << "impossible";
    }
    else if (dif_cmp.size() != cmp) {
        cout << "impossible";
    }
    else if (k < cmp) {
        cout << "impossible";
    }
    else {
        cout << "possible";
    }
    return 0;
}