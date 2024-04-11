#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1e5 + 10;
int p, n;
int a[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int at_least = a[1];
    for (int i = 1; i <= n; i++) {
        at_least = max(at_least, a[i] - i + 1);
    }
    reverse(a + 1, a + n + 1);
    //a[n] >= ... >= a[1]
    int big_bad = INT_MAX;
    vector < int > bad(p + 1, 1e9);
    for (int i = 1; i <= n; i++) {
        int val = n - i + 1;
        if (val % p == 0) {
            // x >= a[i]
            big_bad = min(big_bad, a[i]);
        }
        int bad_res = (a[i] + i - n - 1) % p;
        bad_res %= p;
        if (bad_res < 0) bad_res += p;
        bad[bad_res] = min(bad[bad_res], i);
    }
    vector < int > ans;
    for (int i = at_least; i < big_bad; i++) {
        int res = i % p;
        if (bad[res] > n || i >= a[bad[res]]) {
            ans.emplace_back(i);
        }
    }
    cout << ans.size() << '\n';
    for (auto& it : ans) cout << it << " ";
    // min(n, x - a[i]) - i + 1
    //
    return 0;
}