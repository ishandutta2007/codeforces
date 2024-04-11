#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        vector v(30, 0);
        int n;
        cin >> n;
        for (int i = 0, a; i < n; i += 1) {
            cin >> a;
            for (int j = 0; j < 30; j += 1) if ((a >> j) & 1) v[j] += 1;
        }
        for (int i = 1; i <= n; i += 1) {
            int ok = 1;
            for (int j = 0; j < 30; j += 1) if (v[j] % i) ok = 0;
            if (ok) cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}