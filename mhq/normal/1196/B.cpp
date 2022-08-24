#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, k;
const int maxN = 3 * (int)1e5 + 100;
int pref[maxN];
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        pref[i] = (pref[i - 1] + x) & 1;
    }
    if (pref[n] % 2 != k % 2) {
        cout << "NO" << '\n';
        return;
    }
    int need = 1;
    vector < int > all;
    for (int i = 1; i <= n; i++) {
        if (all.size() == k - 1) break;
        if (pref[i] == need) {
            all.push_back(i);
            need ^= 1;
        }
    }
    if (all.size() != k - 1) cout << "NO" << '\n';
    else {
        cout << "YES" << '\n';
        all.push_back(n);
        for (int v : all) cout << v << " ";
        cout << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) solve();
    return 0;
}