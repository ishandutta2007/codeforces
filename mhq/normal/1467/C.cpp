#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 3e5 + 10;
int n[3];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    ll S = 0;
    vector<int> a[3];
    cin >> n[0] >> n[1] >> n[2];
    vector<int> xx;
    for (int i = 0; i < 3; i++) {
        int sz = n[i];
        a[i].resize(sz);
        for (int j = 0; j < sz; j++) {
            cin >> a[i][j];
            S += a[i][j];
            xx.emplace_back(a[i][j]);
        }
    }
    ll best = -1e18;
    for (int i = 0; i < 3; i++) sort(a[i].begin(), a[i].end());
    for (int i = 0; i < 3; i++) {
        ll f = 0;
        for (int c = 0; c < n[i]; c++) f += a[i][c];
        best = max(best, S - 2 * f);
    }
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) best = max(best, S - 2 * a[i][0] - 2 * a[j][0]);
    }
    cout << best << '\n';
    return 0;
}