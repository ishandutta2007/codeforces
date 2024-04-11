#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = (int)1e5 + 100;
int a[maxN];
ll pref[maxN];
int n, s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        cin >> n >> s;
        int mx = 0;
        ll sm = 0;
        int ans = 0;
        pair < int, int > best = make_pair(-1, -1);
        int ind = -1;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (ind == -1 || a[ind] < a[i]) ind = i;
            sm += a[i];
            if (sm <= s) best = max(best, {i, (i == n ? 0 : i + 1)});
            if (sm - a[ind] <= s) best = max(best, max(best, {i - 1, ind}));
        }
        cout << best.second << '\n';
    }
    return 0;
}