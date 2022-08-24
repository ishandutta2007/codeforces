#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    ll n, k;
    cin >> n >> k;
    if (n * (n - 1) / 2 < k) {
        cout << "Impossible" << endl;
        return 0;
    }
    ll a = 1;
    while (a * (a - 1) / 2 < k) {
        ++a;
    }
    --a;
    for (int i = 1; i <= n - a - 1; ++i) {
        cout << "()";
    }
    for (int i = 1; i <= a; ++i) {
        cout << "(";
    }
    ll t = (k - a * (a - 1) / 2);
    for (int i = 1; i <= a - t; ++i) {
        cout << ")";
    }
    cout << "()";
    for (int i = 1; i <= t; ++i) {
        cout << ")";
    }
    cout << endl;
    return 0;
}