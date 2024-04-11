#include <bits/stdc++.h>
using namespace std;
int n, m;
/*
    a, b -> 1, 14
    d = 13;
    d = 1;
    a a + 13
    a + 13, a + 26
    a, a + 26
    a -> a / 2
    a -> (a + 1) / 2
    1, 2
    1, 3
    2, 4
    1, 4
    3, 5
    1, 5
*/
int solve (int x) {
    long long l = (x / 2) + 1;
    long long r = (1LL * x * x + m) / (2LL * x);
    r = min(r, 1LL * n);
    return max(0LL, (r - l + 1));
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    long long ans = 0;
    for (int i = 1; i <= 2 * n; i++) {
        ans -= solve(i);
    }
    for (int i = 1; i <= 2 * n; i++) {
        if (i % 2 == 1) {
            if (i <= m && (i + 1 <= 2 * n)) ans++;
        }
        if (i % 2 == 0) {
            if (2 * i <= m && (i + 2 <= 2 * n)) ans++;
        }
    }
    int ind = -1;
    for (int i = 1; i <= n; i++) {
        if (i * i > m) {
            ind = i;
            break;
        }
        ans += 2 * (i * i) - 1;
    }
    if (ind != -1) {
        ans += 2LL * m * (n - ind + 1);
    }
    cout << ans;
    return 0;
}