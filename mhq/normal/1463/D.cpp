#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 4e5 + 10;
bool can[maxN];
int b[maxN];
void solve() {
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) can[i] = true;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        can[b[i]] = false;
    }
    int max_x = 0;
    int ptr = 1;
    for (int i = 1; i <= n; i++) {
        ptr = max(ptr, b[i]);
        while (ptr <= 2 * n && !can[ptr]) ptr++;
        if (ptr == 2 * n + 1) break;
        max_x = max(max_x, i);
        ptr++;
    }
    int min_x = n;
    ptr = 2 * n;
    for (int i = n; i >= 1; i--) {
        ptr = min(ptr, b[i]);
        while (ptr > 0 && !can[ptr]) ptr--;
        if (ptr == 0) break;
        min_x = min(min_x, i - 1);
        ptr--;
    }
    cout << max(0, max_x - min_x + 1) << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) solve();
    return 0;
}