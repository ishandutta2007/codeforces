#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        ll n, s, t;
        cin >> n >> s >> t;
        ll a = n - s;
        ll b = n - t;
        cout << max(a, b) + 1 << '\n';
    }
    return 0;
}