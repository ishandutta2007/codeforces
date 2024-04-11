#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int64_t a[nax];

void solve() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i)
        cin >> a[i];
    if (a[n - 1] > a[n]) {
        cout << "-1\n";
        return;
    }
    int64_t min_replace = a[n - 1] - a[n];
    int x = n - 1, y = n;
    int64_t max_idx = a[n] > a[n - 1] ? n : n - 1;
    vector <tuple <int, int, int>> ans;
    for (int j = n - 2 ; j >= 1 ; -- j) {
       if (min(min_replace, a[j]) > a[j + 1]) {
            cout << "-1\n";
            return;
       }
       if (min_replace < a[j]) {
            a[j] = min_replace;
            ans.emplace_back(j, x, y);
       }
       if (a[j] - a[max_idx] < min_replace) {
            min_replace = a[j] - a[max_idx];
            x = j, y = max_idx;
       }
       if (a[j] > max_idx) max_idx = j;
    }
    cout << ans.size() << '\n';
    for (auto [x, y, z] : ans) {
        cout << x << ' ' << y << ' ' << z << '\n';
    }

}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ;) {
        solve();
    }
}
/*
    GL
*/