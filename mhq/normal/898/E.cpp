#include <bits/stdc++.h>
using namespace std;
int n;
int a[2 * (int)1e5 + 10];
int x, y, z;
int b[2 * (int)1e5 + 10];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int t = sqrt(a[i]);
        if (a[i] == 0) z++;
        else if (t * t == a[i] || (t + 1) * (t + 1) == a[i]) x++;
        else {
            int t = sqrt(a[i]);
            b[y] = min(a[i] - t * t, (t + 1) * (t + 1) - a[i]);
            y++;
        }
    }
    //cout << x << " " << y << " " << z;
    if (x + z == n / 2) {
        cout << 0;
        return 0;
    }
    if (x + z >= (n / 2)) {
        if (x + z - (n / 2) <= x) {
            cout << x + z - (n / 2);
            return 0;
        }
        else {
            cout << x * 1 + 2 * (z - (n / 2));
            return 0;
        }
    }
    sort(b, b + y);
    long long ans = 0;
    //for (int i = 0; i < y; i++) cout << b[i] << '\n';
    for (int i = 0; i < (y - (n / 2)); i++) {
        ans += b[i];
    }
    cout << ans;
    return 0;
}