#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int a[nax];
int ans[nax];

void solve() {
    cin >> n;
    map <int, vector <int>> s;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        s[a[i]].push_back(i);
    }

    fill(ans, ans + 1+  n,  0);

    for (auto [x, y] : s) {
        vector <int> &u = y;
        int mx = 0;
        int dp[2]{};
        for (int k : u) {
            int v = k % 2;
            dp[v] = max(dp[v], dp[v ^ 1] + 1);
        }
        ans[x] = max(dp[0], dp[1]);
    }

    for (int i = 1 ; i <= n ; ++ i)
        cout << ans[i] << ' ';
    cout << '\n';




}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}
/*
    rated div.2, quite a while though
*/