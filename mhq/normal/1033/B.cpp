#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int tst;
void solve() {
    ll a, b;
    cin >> a >> b;
    if (a > b + 1) {
        cout << "NO" << '\n';
        return ;
    }
    ll p = a + b;
    for (int i = 2; 1LL * i * i <= p; i++) {
        if (p % i == 0) {
            cout << "NO" << '\n';
            return ;
        }
    }
    cout << "YES" << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> tst;
    while (tst--) solve();
}