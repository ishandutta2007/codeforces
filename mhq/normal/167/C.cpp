#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
ll a, b;
bool go(ll a, ll b) {
    if (a == 0 || b == 0) return false;
    if (a > b) swap(a, b);
    if (!go(a, b % a)) return true;
    ll moves = (b / a);
    if (a % 2 == 1) {
        return (moves % 2) == 0;
    }
    else {
        ll res = (moves % (a + 1));
        return (res % 2 == 0);
    }
}
void solve() {
    cin >> a >> b;
    bool who = go(a, b);
    if (who) cout << "First" << '\n';
    else cout << "Second" << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) solve();
    return 0;
}