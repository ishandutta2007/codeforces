#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, c;
const int maxN = 1e6 + 10;
int pref[maxN];
int a[maxN];
void solve() {
    cin >> n >> c;
    for (int i = 0; i <= c; i++) pref[i] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[a[i]]++;
    }
    for (int i = 1; i <= c; i++) pref[i] += pref[i - 1];
    for (int i = 1; i <= c; i++) {
        if (pref[i] > pref[i - 1]) {
            for (int j = 1; j * i <= c; j++) {
                if (pref[j] == pref[j - 1]) {
                    int from = i * j;
                    int to = min(c, i * j + i - 1);
                    if (pref[to] > pref[from - 1]) {
                        cout << "No\n";
                        return;
                    }
                }
            }
        }
    }
    cout << "Yes\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}