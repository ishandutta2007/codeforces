#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
vector <int> b[nax];
int a[nax];
int n;
int ans[nax];
const int INF = 1e8;

void solve() {
    cin >> n;

    for (int i = 1 ; i <= n;  ++ i) {
        cin >> a[i];
        b[a[i]].push_back(i);
        ans[i] = INF;
    }



    for (int i = 1 ; i <= n ; ++ i) {
        b[i].insert(b[i].begin(), 0);
        b[i].push_back(n + 1);

        int mx = 0;

        for (int j = 1 ; j < b[i].size() ; ++ j) {
            mx = max(mx, b[i][j] - b[i][j - 1]);
        }

        ans[mx] = min(ans[mx], i);
    }

    int last = INF;

    for (int j = 1 ; j <= n ; ++ j) {
        last = min(ans[j], last);
        if (last == INF) cout << -1 << ' ';
        else cout << last << ' ';
    }
    cout << '\n';
}


int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
        for (int i = 1 ; i <= n ; ++ i)
            b[i].clear();
    }
}
/*
    Good Luck
        -Lucina
*/