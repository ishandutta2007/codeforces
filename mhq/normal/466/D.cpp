#include <bits/stdc++.h>

using namespace std;
const int mod = (int)1e9 + 7;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
const int maxN = 2005;
int n, h;
int a[maxN];
int d[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> h;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d[i] = h - a[i];
        if (d[i] < 0) {
            cout << 0;
            return 0;
        }
    }
    if (d[1] > 1 || d[n] > 1) {
        cout << 0;
        return 0;
    }
    int open = d[1];
    int ans = 1;
    for (int i = 1; i + 1 <= n; i++) {
        if (d[i + 1] > open + 1) {
            cout << 0;
            return 0;
        }
        if (d[i + 1] < open - 1) {
            cout << 0;
            return 0;
        }
        if (d[i + 1] == open) {
            ans = mult(ans, open + 1);
        }
        else if (d[i + 1] == open - 1) {
            ans = mult(ans, open);
        }
        open = d[i + 1];
    }
    cout << ans;
    return 0;
}