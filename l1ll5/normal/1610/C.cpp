#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 200000 + 5;

bool ck(int n, const vector<int>& a, const vector<int>& b, int x) {
    vector<pair<int, int> > c;
    for (int i = 0; i < n; i += 1) {
        int L = max(1, x - a[i]);
        int R = min(x, b[i] + 1);
        if (L > R) continue;
        c.push_back(make_pair(L, R));
    }
    //sort(c.begin(), c.end());
    int cur = 1;
    for (int i = 0; i < c.size(); i += 1) {
        if (c[i].first <= cur && c[i].second >= cur) {
            cur++;
        }
        /*if (c[i].first > cur) {
            return 0;
        }
        if (c[i].second < cur) continue;
        cur++;*/
    }
    if (cur > x) return 1;
    return 0;
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i += 1) {
        cin >> a[i] >> b[i];
    }
    int l = 0, r = n, ret = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (ck(n, a, b, mid)) {
            ret = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    cout << ret << '\n';
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}