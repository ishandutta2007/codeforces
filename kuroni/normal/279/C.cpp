#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, m, l, r, a[N], le[N], ri[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        le[i] = (a[i] <= a[i - 1] ? le[i - 1] : i);
    }
    for (int i = n; i >= 1; i--) {
        ri[i] = (a[i] <= a[i + 1] ? ri[i + 1] : i);
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << le[i] << "-" << ri[i] << '\n';
    // }
    while (m--) {
        cin >> l >> r;
        cout << (ri[l] >= le[r] ? "Yes\n" : "No\n");
    }
}