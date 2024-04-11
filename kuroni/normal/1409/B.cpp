#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, t, x, y, a, b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> a >> b >> x >> y >> n;
        int la = max(x, a - n), lb = max(y, b - (n - (a - la)));
        int rb = max(y, b - n), ra = max(x, a - (n - (b - rb)));
        cout << min(1LL * la * lb, 1LL * ra * rb) << '\n';
    }
}