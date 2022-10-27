#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;

int n;
char s[nax];
vector <int> g[nax];
int ans;

int dfs(int v) {
    int sum = (s[v] == 'B' ? 1 : -1);
    for (int to : g[v]) {
        sum += dfs(to);
    }
    if (sum == 0) ans += 1;
    return sum;
}

void solve() {
    cin >> n;
    for (int i = 2 ; i <= n ; ++ i) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }
    cin >> s + 1;
    ans = 0;
    dfs(1);
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
        for (int i = 1 ; i <= n ; ++ i)
            g[i].clear();
        //cout << (solve() ? "YES" : "NO") << '\n';
    }
}