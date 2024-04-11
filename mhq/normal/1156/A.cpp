#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
int a[105];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i + 1 <= n; i++) {
        if ((a[i] == 2 && a[i + 1] == 3) || (a[i] == 3 && a[i + 1] == 2)) {
            cout << "Infinite";
            return 0;
        }
        if (a[i] == 3 || a[i + 1] == 3) ans += 4;
        else ans += 3;
    }
    for (int i = 1; i + 2 <= n; i++) {
        if (a[i] == 3 && a[i + 1] == 1 && a[i + 2] == 2) ans--;
    }
    cout << "Finite" << '\n';
    cout << ans;
    return 0;
}