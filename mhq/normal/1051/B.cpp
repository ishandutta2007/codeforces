#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    ll l, r;
    cin >> l >> r;
    cout << "YES" << '\n';
    for (ll i = l; i <= r - 1; i += 2) {
        cout << i << " " << i + 1 << '\n';
    }
    return 0;
}