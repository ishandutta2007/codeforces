#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

struct SumTree {
    int n;
    vector<int> sum;

    SumTree(int n) : n(n), sum(2 * n) {}

    void set(int i) {
        i += n;
        sum[i] = 1;
        for (i /= 2; i > 0; i /= 2) {
            sum[i] = sum[2 * i] + sum[2 * i + 1];
        }
    }

    int get(int l, int r) {
        int res = 0;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) res += sum[l++];
            if (r & 1) res += sum[--r];
        }
        return res;
    }
};

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    for (char &c: s) c -= 'a';
    for (char &c: t) c -= 'a';
    string copy = s;
    sort(copy.begin(), copy.end());
    if (copy >= t) {
        cout << "-1\n";
        return;
    }
    SumTree moved(n);
    vector<vector<int>> index(26);
    for (int i = 0; i < n; ++i) index[s[i]].push_back(i);
    for (auto &row: index) reverse(row.begin(), row.end());
    ll ans = n * 1LL*n;
    ll cur = 0;
    for (int i = 0; i < n; ++i) {
        for (char c = 0; c < t[i]; ++c) {
            if (index[c].size()) {
                ans = min(ans, cur + index[c].back() - i + moved.get(index[c].back(), n));
            }
        }
        if (index[t[i]].empty()) break;
        int idx = index[t[i]].back();
        index[t[i]].pop_back();
        cur += idx - i + moved.get(idx, n);
        moved.set(idx);
    }
    cout << ans << '\n';
}