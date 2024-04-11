#include <bits/stdc++.h>
using namespace std;
const int maxN = (int)1e5 + 10;
string s, t;
map < pair < int, int >, int > p;
vector < int > g[30];
int cmp = 0;
vector < int > comp[30];
bool used[30];
void dfs(int v) {
    comp[cmp].push_back(v);
    used[v] = true;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (used[to]) continue;
        dfs(to);
    }
}
int n;
vector < pair < int, int > > ans;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    cin >> s >> t;
    for (int i = 0; i < s.size(); i++) {
        char x = s[i] - 'a';
        char y = t[i] - 'a';
        if (x == y) continue;
        if (p[minmax(x, y)]) continue;
        p[minmax(x, y)] = 1;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 0; i < 26; i++) {
        if (used[i]) continue;
        dfs(i);
        cmp++;
    }
    for (int i = 0; i < cmp; i++) {
        if (comp[i].size() == 1) continue;
        for (int j = 1; j < comp[i].size(); j++) {
            ans.push_back(make_pair(comp[i][0], comp[i][j]));
        }
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        cout << (char)(ans[i].first + 'a') << " " << (char)(ans[i].second + 'a') << '\n';
    }
    return 0;
}