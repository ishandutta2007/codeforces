#include <bits/stdc++.h>

using namespace std;

int n, t, k, d;

int main() {
    cin >> n >> t >> k >> d;
    int t1 = 1e9, t2 = 1e9;
    for (int i = 1001000; i >= 0; i--) {
        if ((i / t) * k >= n) t1 = i;
        if ((i / t) * k + (max(0, (i - d) / t) * k) >= n) t2 = i;
    }

    if (t1 > t2) {
        cout << "YES\n";
    } else cout << "NO\n";
}