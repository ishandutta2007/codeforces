#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int x[nax], y[nax];
int n;

bool solve() {
    cin >> n;
    vector < vector <int>> g(n + 1);
    vector < vector <int>> where(n + 1);
    vector < bool> used(n + 1);
    vector <int> cnt(n + 1);
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> x[i] >> y[i];
        cnt[x[i]] += 1;
        cnt[y[i]] += 1;
        where[x[i]].push_back(i);
        where[y[i]].push_back(i);
    }
    for (int i = 1 ; i <= n ; ++ i) {
        if (cnt[i] != 2 || x[i] == y[i]) return false;
        assert(where[i].size() == 2);
        g[where[i][0]].push_back(where[i][1]);
        g[where[i][1]].push_back(where[i][0]);
    }

    vector <int> side(n + 1, -1);

    bool ok = true;

    function<void(int, int)> dfs = [&](int v, int s) -> void {
        for (int to : g[v]) {
            if (side[to] == -1) {
                side[to] = s ^ 1;
                dfs(to, side[to]);
            } else if (side[to] == side[v]) {
                ok = false;
            }
        }
    };

    for (int i = 1 ; i <= n ; ++ i) {
        if (side[i] == -1) side[i] = 0, dfs(i, 0);
    }
    return ok;


}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }

}