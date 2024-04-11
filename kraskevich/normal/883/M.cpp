#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int d1 = abs(a - c);
    if (d1 == 0)
        d1++;
    int d2 = abs(b - d);
    if (d2 == 0)
        d2++;
    cout << 2 * d1 + 2 * d2 + 4 << endl;
}