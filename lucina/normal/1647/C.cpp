#include<bits/stdc++.h>
using namespace std;
int const nax = 256;
char s[nax][nax];
int n, m;

void solve() {
    cin >> n >> m;
    for (int i = 1 ; i <= n ; ++ i)
        cin >> s[i] + 1;
    vector <tuple <int, int, int, int>> ans;
    if (s[1][1] == '1') {
        cout << "-1\n";
        return;
    }
    for (int i = 2 ; i <= n ; ++ i) {
        if (s[i][1] == '1') {
            ans.emplace_back(i - 1, 1, i, 1);
        }
    }
    for (int i = 1 ; i <= n ; ++ i)
    for (int j = 2 ; j <= m ; ++ j) {
        if (s[i][j] == '1') {
            ans.emplace_back(i, j - 1, i, j);
        }
    }
    cout << ans.size() << '\n';
    reverse(ans.begin(), ans.end());
    for (auto [x, y, z, w] : ans)
        cout << x << ' ' << y << ' ' << z << ' ' << w << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ;) {
        solve();
    }
}