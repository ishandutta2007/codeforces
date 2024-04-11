#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), mn_pos(n + 1, inf), mx_pos(n + 1, -inf);
    vector<int> crd; crd.reserve(n);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        crd.push_back(x);
        a[i] = x;
    }
    sort(crd.begin(), crd.end());
    crd.resize(unique(crd.begin(), crd.end()) - crd.begin());
    int sz = (int) crd.size();
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(crd.begin(), crd.end(), a[i]) - crd.begin();
        int x = a[i];
        mn_pos[x] = min(mn_pos[x], i);
        mx_pos[x] = max(mx_pos[x], i);
    }
    multiset<int> mxs;
    auto get_mx = [&]() -> int {
        return mxs.empty() ? -inf : *(--mxs.end());
    };
    int res = inf;
    for (int l = -1, r = -1; l < sz; l++) {
        while (r + 1 < sz && mn_pos[r + 1] > get_mx()) {
            mxs.insert(mx_pos[r + 1]);
//            cout << "add " << mx_pos[r + 1] << " ?\n";
            r++;
        }
        res = min(res, l + 1 + sz - 1 - r);
        if (l + 1 < sz) {
//            cout << "erase " << mx_pos[l + 1] << " ?\n";
            mxs.erase(mxs.lower_bound(mx_pos[l + 1]));
        }
    }
    cout << res << "\n";
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;
    while (q--) solve();

    return 0;
}