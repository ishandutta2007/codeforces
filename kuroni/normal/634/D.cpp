#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int d, n, m, x, p;
long long ans = 0;
vector<pair<int, int>> ve;

struct SGas {
    int val;
    mutable int num;

    SGas(int _val = 0, int _num = 0) : val(_val), num(_num) {}

    bool operator<(const SGas &oth) const {
        return val < oth.val;
    }

    long long price() const {
        return 1LL * val * num;
    }
};
set<SGas> se;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> d >> n >> m;
    while (m--) {
        cin >> x >> p;
        ve.push_back({x, p});
    }
    se = {{0, n}};
    ve.push_back({0, 0}); ve.push_back({d, 0});
    sort(ve.begin(), ve.end());
    for (int i = 1; i < ve.size(); i++) {
        int rem = ve[i].fi - ve[i - 1].fi, cur = rem;
        if (rem > n) {
            return cout << -1, 0;
        }
        while (rem > 0) {
            if (se.begin()->num <= rem) {
                rem -= se.begin()->num;
                se.erase(se.begin());
            } else {
                se.begin()->num -= rem;
                rem = 0;
            }
        }
        while (!se.empty() && se.rbegin()->val >= ve[i].se) {
            cur += se.rbegin()->num;
            ans -= se.rbegin()->price();
            se.erase(prev(se.end()));
        }
        SGas add = SGas(ve[i].se, cur);
        ans += add.price();
        se.insert(add);
    }
    cout << ans;
}