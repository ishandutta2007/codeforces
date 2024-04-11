#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7, lim = 1e6 + 5;
const int m1 = 1007050321, b1 = 1234;
const int m2 = 1000000009, b2 = 2345;

int n, q;
string s0, t;
vector<string> s;
vector<vector<pair<int, int>>> f;
vector<pair<int, int>> pw;
int p2[100005];
int i2[100005];
int cnt[100005][26];

pair<int, int> get_next(pair<int, int> p, int c) {
    return {(1ll * p.first * b1 + c) % m1, (1ll * p.second * b2 + c) % m2};
}
pair<int, int> mul(pair<int, int> a, pair<int, int> b) {
    return {1ll * a.first * b.first % m1, 1ll * a.second * b.second % m2};
}
pair<int, int> sub(pair<int, int> a, pair<int, int> b) {
    return {(a.first - b.first + m1) % m1, (a.second - b.second + m2) % m2};
}

pair<int, int> get_h(const vector<pair<int, int>> &h, int l, int r) {
    if (l > r) return {0, 0};
    pair<int, int> hr = h[r];
    if (l == 0) return hr;
    pair<int, int> hl = mul(h[l-1], pw[r-l+1]);
    return sub(hr, hl);
}

void prep(void) {
    p2[0] = 1;
    for (int i = 1; i <= n; ++i) p2[i] = 2 * p2[i-1] % mod;
    i2[0] = 1;
    for (int i = 1; i <= n; ++i) i2[i] = 1ll * (mod + 1) / 2 * i2[i-1] % mod;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 26; ++j) cnt[i][j] = cnt[i-1][j];
        cnt[i][t[i-1] - 'a'] = (cnt[i][t[i-1] - 'a'] + i2[i]) % mod;
    }

    int mx = s.back().size();
    pw.push_back({1, 1});
    for (int i = 1; i <= mx; ++i) {
        pw.push_back(get_next(pw.back(), 0));
    }
    for (auto x: s) {
        f.push_back({});
        pair<int, int> cur = {0, 0};
        for (auto c: x) {
            cur = get_next(cur, c);
            f.back().push_back(cur);
        }
    }
}

int matches(int k, string p) {
    int ret = 0;
    pair<int, int> key = {0, 0};
    for (auto c: p) key = get_next(key, c);
    for (int i = 0; i + p.size() <= s[k].size(); ++i) {
        if (get_h(f[k], i, i + p.size() - 1) == key) ++ret;
    }
    return ret;
}

int cal(int k, string p) {
    int m = p.size();
    int id = 0;
    while (id < k && s[id].size() < m) ++id;
    if (id == k) return matches(k, p);

    int ret = 1ll * matches(id, p) * p2[k - id] % mod;
    vector<pair<int, int>> g;
    pair<int, int> cur = {0, 0};
    for (auto c: p) {
        cur = get_next(cur, c);
        g.push_back(cur);
    }
    for (int i = 0; i < m; ++i) {
        pair<int, int> pref  = get_h(g, 0, i - 1);
        pair<int, int> suff  = get_h(g, i + 1, m - 1);
        pair<int, int> prefw = get_h(f[id], 0, m - 2 - i);
        pair<int, int> suffw = get_h(f[id], s[id].size() - i, s[id].size() - 1);
        if (pref == suffw && suff == prefw) {
            int c = p[i] - 'a';
            int add = 1ll * p2[k] * (cnt[k][c] - cnt[id][c] + mod) % mod;
            ret = (ret + add) % mod;
        }
    }

    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q >> s0 >> t;
    s.push_back(s0);
    while (s.back().size() < lim && s.size() <= t.size()) {
        string nx = s.back() + t[s.size() - 1] + s.back();
        s.push_back(nx);
    }
    prep();
    while (q--) {
        int k;
        string p;
        cin >> k >> p;
        cout << cal(k, p) << '\n';
    }
    return 0;
}