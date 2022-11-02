#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int N = 5000 + 5;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int have1 = 0;
        for (int i = 0; i < n; i += 1) {
            cin >> a[i];
            if (a[i] == 1) {
                have1 = 1;
            }
        }
        if (!have1) {
            cout << "YES\n";
        }
        else {
            sort(a.begin(), a.end());
            int ok = 1;
            for (int i = 0; i < n - 1; i += 1) {
                if (a[i] + 1 == a[i + 1]) {
                    ok = 0;
                }
            }
            if (ok) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}