#include <bits/stdc++.h>

using namespace std;

int n, k, a, b, c, d;
int v[1005], m;

int main() {
    cin >> n >> k >> a >> b >> c >> d;
    if (n == 4 || k < n + 1) {
        cout << "-1\n";
        return 0;
    }

    for (int i = 1; i <= n; i++)
        if (i != a && i != b && i != c && i != d)
            v[m++] = i;

    assert(m + 4 == n);

    cout << a << ' ' << c << ' ';
    for (int i = 0; i < m; i++) cout << v[i] << ' ';
    cout << d << ' ' << b << '\n';

    cout << c << ' ' << a << ' ';
    for (int i = m - 1; i >= 0; i--) cout << v[i] << ' ';
    cout << b << ' ' << d << '\n';
}