#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;

const int MAXN = 200228;

int b[MAXN];
int a[MAXN];

int main() {
#ifdef PAUNSVOKNO
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(20); cout.tie(nullptr); cin.tie(nullptr);
    ll ans = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = n; i > 0; --i) {
        b[i] = max(a[i - 1] + 1, b[i + 1] - 1);
    }

    b[0] = 0;

    for (int i = 0; i < n; ++i) {
        b[i + 1] = max(b[i + 1], b[i]);
    }

    for (int i = 0; i < n; ++i) {
        ans += b[i + 1] - a[i] - 1;
    }

    cout << ans << "\n";
}