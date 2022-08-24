#include <bits/stdc++.h>
using namespace std;
int a[1005];
int n;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("log.in", "r", stdin);
    //freopen("log.out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    int mn = (int)1e6 + 10;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = n; i >= 1; i--) {
        if (a[i] < 0) {
            cout << a[i];
            return 0;
        }
        int x = (int)sqrt(a[i]);
        if (x * x != a[i]) {
            cout << a[i];
            return 0;
        }
    }
    return 0;
}