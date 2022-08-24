#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 105;
int x[maxN], y[maxN];
int n, a, b;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int p = 0; p < 2; p++) {
                for (int r = 0; r < 2; r++) {
                    for (int k = 0; k < 2; k++) {
                        if (x[i] <= a && x[j] <= a && y[i] + y[j] <= b) {
                            mx = max(mx, x[i] * y[i] + x[j] * y[j]);
                        }
                        swap(a, b);
                    }
                    swap(x[j], y[j]);
                }
                swap(x[i], y[i]);
            }
        }
    }
    cout << mx;
    return 0;
}