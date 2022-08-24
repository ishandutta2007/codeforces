#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 105;
int a[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int total = 0;
    int al = 0;
    int sz = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        total += a[i];
        if (i == 1 || a[1] >= 2 * a[i]) {
            al += a[i];
            sz++;
        }
    }
    if (al > total - al) {
        cout << sz << '\n';
        for (int i = 1; i <= n; i++) {
            if (i == 1 || a[1] >= 2 * a[i]) cout << i << " ";
        }
    }
    else cout << 0;
    return 0;
}