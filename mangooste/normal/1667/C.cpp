#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "/home/Templates/debug.h"
#else
    #define dbg(...)
#endif // LOCAL

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    if (n == 1) {
        cout << "1\n1 1\n";
        return 0;
    }

    int ans = 0;
    while (ans * 3 + 1 < 2 * n) ans++;
    cout << ans << '\n';

    int sz = n - ans;
    assert(sz * 3 <= n + 1);
    int st1 = n - 3 * sz + 2;
    int st2 = n - 2 * sz + 1;
    dbg(st1, st2);
    for (int i = 1; i < st1; i++) {
        cout << i << ' ' << i << '\n';
    }
    for (int i = 0; i < sz - 1; i++) {
        cout << st1 + sz - 2 - i << ' ' << st1 + i << '\n';
    }
    for (int i = 0; i < sz; i++) {
        cout << st2 + sz - 1 - i << ' ' << st2 + i << '\n';
    }
}