#include <bits/stdc++.h>

using namespace std;

int n, m;
int l1 = 0, r1 = 1e9;
int l2 = 0, r2 = 1e9;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        l1 = max(l1, l);
        r1 = min(r1, r);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l2 = max(l2, l);
        r2 = min(r2, r);
    }
    int ans = 0;
    ans = max(ans, l2 - r1);
    ans = max(ans, l1 - r2);
    cout << ans << endl;
}