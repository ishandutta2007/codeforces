#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n / 3; i++) {
        if (n % i == 0) {
            for (int j = 0; j < i; j++) {
                bool ok = true;
                int st = j;
                do {
                    ok &= a[st];
                    (st += i) %= n;
                } while (st != j);
                if (ok) {
                    return cout << "YES\n", 0;
                }
            }
        }
    }
    cout << "NO\n";
}