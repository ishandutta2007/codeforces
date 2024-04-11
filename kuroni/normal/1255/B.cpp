#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
    
const int N = 1005;
    
int t, n, m, u;
    
void solve() {
    cin >> n >> m;
    int su = 0;
    for (int i = 1; i <= n; i++) {
        cin >> u;
        su += u;
    }
    if (n == 2) {
        cout << "-1\n";
    } else if (m < n) {
        cout << "-1\n";
    } else {
        cout << su * 2 << '\n';
        for (int i = 1; i <= n; i++) {
            cout << i << " " << i % n + 1 << '\n';
        }
    }
}
    
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        solve();
    }
}