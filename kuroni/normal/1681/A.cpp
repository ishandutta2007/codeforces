#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int mx_a = 0;
        while (n--) {
            int u; cin >> u;
            mx_a = max(mx_a, u);
        }
        int m; cin >> m;
        int mx_b = 0;
        while (m--) {
            int u; cin >> u;
            mx_b = max(mx_b, u);
        }
        cout << (mx_a >= mx_b ? "Alice\n" : "Bob\n");
        cout << (mx_b >= mx_a ? "Bob\n" : "Alice\n");
    }
}