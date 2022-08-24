#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2 * (int)1e5 + 100;
int a[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int x = (int)1e9 + 1000;
        for (int i = 1; i + k <= n; i++) {
            x = min(x, (a[i + k] - a[i] + 1) / 2);
        }
        for (int i = 1; i <= n; i++) {
            if (a[i] + x >= a[i + k] - x) {
                cout << a[i] + x << '\n';
                break;
            }
        }
    }
    return 0;
}