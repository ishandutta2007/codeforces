#include <bits/stdc++.h>

using namespace std;
const int maxN = 40;
vector < int > g[maxN];
bool used[maxN];
int deg[maxN];
void dfs(int v, string& ans) {
    used[v] = true;
    ans += (char)(v + 'a');
        for (int to  : g[v]) {
            if (used[to]) continue;
            deg[to]--;
            if (deg[to] <= 1) {
                used[to] = true;
                dfs(to, ans);
            }
    }
}
int main() {
  // freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        string s;
        cin >> s;
        for (int i = 0; i < 26; i++) g[i].clear();
        memset(used, 0, sizeof used);
        for (int i = 0; i + 1 < s.size(); i++) {
            g[s[i] - 'a'].push_back(s[i + 1] - 'a');
            g[s[i + 1] - 'a'].push_back(s[i] - 'a');
        }
        bool ok = false;
        for (int i = 0; i < 26; i++) {
            sort(g[i].begin(), g[i].end());
            g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
        }
        for (int i = 0; i < 26; i++) {
            if (g[i].size() > 2) {
                ok = true;
                break;
            }
        }
        if (ok) {
            cout << "NO\n";
            continue;
        }
        string ans;
        for (int i = 0; i < 26; i++) {
            deg[i] = g[i].size();
            if (g[i].size() <= 1 && !used[i]) {
                dfs(i, ans);
            }
        }
        if (ans.size() == 26) {
            cout << "YES\n" << ans << '\n';
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}