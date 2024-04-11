#include <bits/stdc++.h>
using namespace std;
int n;
int a[1505];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i] > a[j]) ans = (ans + 1) % 2;
        }
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        ans = (ans + (r - l + 1) / 2) % 2;
        if (ans) cout << "odd" << '\n';
        else cout << "even" << '\n';
    }
}