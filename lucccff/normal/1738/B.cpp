#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int a[N], n, m, b[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for(int i = 0; i < m; i++) {
            cin >> a[i];
        }
        if (m == 1) {
            cout << "Yes" << endl;
            continue;
        }
        for(int i = 1; i < m; i++) {
            b[n - m + i] = a[i] - a[i - 1];
        }
        if (a[0] > 1ll * b[n - m + 1] * (n - m + 1)) {
            cout << "No" << endl;;
            continue;
        }
        int flag = 1;
        for(int i = n - m + 1; i < n - 1; i++) {
            if (b[i] > b[i + 1]) flag = 0;
        }
        if (flag) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    return 0;
}