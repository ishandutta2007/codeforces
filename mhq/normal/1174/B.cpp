#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = (int)1e5 + 100;
int a[maxN];
int n;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    bool ok = false;
    for (int i = 1; i + 1 <= n; i++) {
        if (a[i] % 2 != a[(i + 1)] % 2) {
            ok = true;
        }
    }
    if (!ok) {
        for (int i = 1; i <= n; i++) cout << a[i] << " ";
        return 0;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    return 0;
}