#include <bits/stdc++.h>
using namespace std;

const int N = 1E5 + 5;

int t, n, m, u;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> n >> m;
        int le = 0, ri = 0;
        while (n--) {
            cin >> u;
            le = max(le, u);
        }
        while (m--) {
            cin >> u;
            ri = max(ri, u);
        }
        cout << (le > ri ? "YES\n" : "NO\n");
    }
}