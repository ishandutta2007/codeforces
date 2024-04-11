#include <bits/stdc++.h>

using namespace std;

int n;
int a[200005], b[200005];

bool ok(int k) {
    int x = k - 1, y = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] >= x && b[i] >= y) {
            --x;
            ++y;
            if (x == -1) return true;
        }
    }
    return false;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
        int l = 1, r = n;
        while (l < r) {
            int m = l + r + 1 >> 1;
            if (ok(m)) l = m;
            else r = m - 1;
        }
        cout << l << '\n';
    }
    return 0;
}