#include<bits/stdc++.h>
using namespace std;
int const nax = 4e5 + 10;

struct fenwick {

    int n;
    int bit[nax];

    fenwick() {
        memset(bit, 0, sizeof(bit));
    }

    void set_size(int _n) {
        n = _n;
        fill(bit, bit + n + 10, 0);
    }

    void update(int idx, int val) {
        for (; idx <= n ; idx += idx & -idx) {
            bit[idx] += val;
        }
    }

    int get(int idx) {
        int res = 0;
        for ( ; idx > 0 ; idx -= idx & -idx)
            res += bit[idx];
        return res;
    }

    int get(int l, int r) {
        return get(r) - get(l - 1);
    }
};

pair <int, int> a[nax];
int n;
fenwick f1, f2;

void solve() {
    cin >> n;

    vector <int> com;


    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i].first >> a[i].second;
        com.push_back(a[i].first);
        com.push_back(a[i].second);
    }

    sort(com.begin(), com.end());
    com.erase(unique(com.begin(), com.end()), com.end());

    f1.set_size(com.size());
    f2.set_size(com.size());

    auto where = [&](int x)->int {
        return lower_bound(com.begin(), com.end(), x) - com.begin() + 1;
    };

    sort(a + 1, a + 1 + n);

    for (int i = 1 ; i <= n ; ++ i) {
        f2.update(where(a[i].first), 1);
    }

    int ans = 0;
    /**
        [--------------]
        [-----------]

    [   .......]
    */

    for (int i = 1 ; i <= n ; ++ i) {
        auto [l, r] = a[i];
        l = where(l);
        r = where(r);
        int bk = f2.get(1, r);
        int fnt = f1.get(l, com.size());
        ans = max(ans, bk + fnt);
        f1.update(r, 1);
        f2.update(l, -1);
    }

    cout << n - ans << '\n';

}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ;T -- ;) {
        solve();
    }
}