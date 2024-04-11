#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        ll l, r, d;
        cin >> l >> r >> d;
        if (d < l) {
            cout << d << '\n';
        }
        else {
            cout << ((r + 1 + d - 1) / d) * d << '\n';
        }
    }
    return 0;
}