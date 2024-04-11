#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, n;
    long long k;
    cin >> t;
    while (t--) {
        cin >> n >> k; --k;
        if (n <= 60 && (1LL << (n - 1)) <= k) {
            cout << "-1\n";
        } else {
            vector<bool> chk(n, false);
            vector<int> p;
            for (int i = 0; i < n - 1 && i <= 60; i++) {
                chk[n - 2 - i] = (k >> i & 1);
            }
            for (int i = 0; i < n; i++) {
                if (!chk[i]) {
                    p.push_back(i);
                    for (int j = i - 1; j >= 0 && chk[j]; j--) {
                        p.push_back(j);
                    }
                }
            }
            for (int v : p) {
                cout << v + 1 << " ";
            }
            cout << '\n';
        }
    }
}