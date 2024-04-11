#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int tst;
void solve() {
    ll s, a, b, c;
    cin >> s >> a >> b >> c;
    cout << (s / c) + ((s / c) / a) * b << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> tst;
    while (tst--) solve();
    return 0;
}