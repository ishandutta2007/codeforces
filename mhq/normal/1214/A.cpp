#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
ll n;
ll d, e;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> d >> e;
    e *= 5;
    ll best = n + 10;
    for (ll p = 0; p * e <= n; p++) {
        best = min(best, (n - p * e) % d);
    }
    cout << best;
    return 0;
}