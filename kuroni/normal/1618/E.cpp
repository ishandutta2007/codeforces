#include <bits/stdc++.h>
using namespace std;

const int INF = 1E9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        long long tot = accumulate(a.begin(), a.end(), 0LL);
        long long num = 1LL * n * (n + 1) / 2;
        bool ok = true;
        if (tot % num == 0) {
            long long sum = tot / num;
            for (int i = 0; i < n; i++) {
                long long cur = (a[(i + n - 1) % n] + sum - a[i]);
                if (cur <= 0 || cur % n != 0) {
                    ok = false;
                    break;
                } else {
                    b[i] = cur / n;
                }
            }
        } else {
            ok = false;
        }
        if (ok) {
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                cout << b[i] << " \n"[i == n - 1];
            }
        } else {
            cout << "NO\n";
        }
    }
}