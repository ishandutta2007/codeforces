#include <bits/stdc++.h>
using namespace std;

struct bit {
    int n;
    vector<int> ans;

    bit(int _n) : n(_n) {
        ans.resize(2 * _n);
    }

    void update(int u) {
        for (u += n; u > 0; u -= u & -u) {
            ans[u]++;
        }
    }

    int query(int u) {
        int ret = 0;
        for (u += n; u < ans.size(); u += u & -u) {
            ret += ans[u];
        }
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<bit> dt(3, bit(n + 1));
        string s; cin >> s;
        dt[0].update(0);
        int cur = 0;
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            cur += (s[i - 1] == '+' ? 1 : -1);
            int m = (cur % 3 + 3) % 3;
            ans += dt[m].query(cur);
            dt[m].update(cur);
        }
        cout << ans << '\n';
    }
}