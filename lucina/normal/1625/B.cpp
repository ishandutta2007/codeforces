#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int a[nax];
void solve() {
    cin >> n;
    map <int, vector <int>> p;
    for (int i = 1 ; i <= n ; ++ i) {
        int x;
        cin >> x;
        p[x].push_back(i);
    }
    int ans = -1;
    for (auto &[_, v] : p) {
        for (int i = 1 ; i < v.size() ; ++ i) {
            ans = max(ans, v[i - 1] + n - v[i]);
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}