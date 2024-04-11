#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline ll mod(ll x, ll y) {
    return (x % y + y) % y;
}

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    if (n == 1)
        return cout << "1 1\n0\n1 1\n0\n1 1\n" << -a[0] << '\n', 0;

    auto print = [&](int index, ll delta) {
        cout << delta << ' ';
        a[index] += delta;
    };

    cout << "1 " << n - 1 << '\n';
    for (int i = 0; i < n - 1; i++)
        print(i, (n - 1) * mod(a[i], n));
    cout << '\n';

    cout << "2 " << n << '\n';
    for (int i = 1; i < n; i++)
        print(i, (n - 1) * mod(a[i], n));
    cout << '\n';

    cout << "1 " << n << '\n';
    for (auto x : a)
        cout << -x << ' ';
    cout << '\n';
}