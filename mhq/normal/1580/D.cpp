#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = 4005;
ll a[maxN];
vector<ll> solve(int l, int r) {
    if (l > r) {
        return {0LL};
    }
    int where = l;
    for (int k = l; k <= r; k++) {
        if (a[k] < a[where]) where = k;
    }
    auto t1 = solve(l, where - 1);
    auto t2 = solve(where + 1, r);
    for (int z = 0; z < t1.size(); z++) {
        t1[z] += a[where] * z * z;
    }
    for (int z = 0; z < t2.size(); z++) {
        t2[z] += a[where] * z * z;
    }
    vector<ll> ans(r - l + 1 + 1, -1e18);
    int pt1 = 0;
    int pt2 = 0;
    for (int z = 0; z < t1.size() + t2.size() - 1; z++) {
        ans[z] = t1[pt1] + t2[pt2] - z * z * a[where];
        if (z != (int)ans.size() - 2) {
            if (pt1 + 1 < (int)t1.size() && (pt2 == (int)t2.size() - 1 || t1[pt1 + 1] - t1[pt1] > t2[pt2 + 1] - t2[pt2])) {
                pt1++;
            }
            else {
                pt2++;
            }
        }
    }
    assert(pt1 == (int)t1.size() - 1 && pt2 == (int)t2.size() - 1);
    for (int i = (int)ans.size() - 2; i >= 0; i--) {
        ans[i + 1] = max(ans[i + 1], ans[i] + (m - 1) * a[where] - 2 * i * a[where]);
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<ll> t = solve(1, n);
    cout << t[m] << '\n';
    return 0;
}