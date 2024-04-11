#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
int n;
int a[nax];
int b[nax];
 
void solve() {
    cin >> n;
    map <int, int> cnt;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        cnt[a[i]] += 1;
    }
    int r = 0, l = cnt.size();
    for (auto [u, v] : cnt) {
        if (v > 1) r += 1;
    }
    cout << (l + r + 1) / 2 << '\n';
    /**
    1  2  3 3 4  5  6  7 8  |6 5 4 3 2 1
    */
}
int main() {
    int T;
    cin.tie(0)->sync_with_stdio(false);
    for (cin >> T ; T -- ;) {
        solve();
    }
}