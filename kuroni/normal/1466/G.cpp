#include <bits/stdc++.h>
using namespace std;

const int N = 100005, MOD[2] = {1000000007, 998244353}, MX = 1E6 + 5;
const int B = 37, C = 26;

int n, q, k, cur = 0, mx = 0, in[N], out[N][C];
long long ans[N], pw[4 * MX][2], hsh[4 * MX][2];
long long tin = 1, cr[C];
string s, t, sq[N];
vector<pair<string, int>> eve[N];

void init() {
    pw[0][0] = pw[0][1] = 1;
    for (int i = 1; i < 4 * MX; i++) {
        for (int j = 0; j < 2; j++) {
            pw[i][j] = pw[i - 1][j] * B % MOD[j];
        }
    }
}

void init_hash() {
    for (int i = 1; i <= s.size(); i++) {
        for (int j = 0; j < 2; j++) {
            hsh[i][j] = (hsh[i - 1][j] * B + s[i - 1] - 'a' + 1) % MOD[j];
        }
    }
}

pair<long long, long long> get_hash(int l, int r) {
    long long u = (hsh[r][0] - hsh[l - 1][0] * pw[r - l + 1][0] + 1LL * MOD[0] * MOD[0]) % MOD[0];
    long long v = (hsh[r][1] - hsh[l - 1][1] * pw[r - l + 1][1] + 1LL * MOD[1] * MOD[1]) % MOD[1];
    return {u, v};
}

pair<long long, long long> get_hash(const string& s) {
    long long hsh[2] = {0, 0};
    for (int i = 1; i <= s.size(); i++) {
        for (int j = 0; j < 2; j++) {
            hsh[j] = (hsh[j] * B + s[i - 1] - 'a' + 1) % MOD[j];
        }
    }
    return {hsh[0], hsh[1]};
}

int check(const string& u) {
    int cnt = 0;
    auto [h0, h1] = get_hash(u);
    for (int i = u.size(); i <= s.size(); i++) {
        auto [t0, t1] = get_hash(i - (int)u.size() + 1, i);
        if (t0 == h0 && t1 == h1) {
            cnt++;
        }
    }
    return cnt;
}

int pre_calc(const string& u) {
    int n = s.size() / 2, cnt = 0;
    auto [h0, h1] = get_hash(u);
    for (int i = n + 1; i <= n + (int)u.size(); i++) {
        auto [t0, t1] = get_hash(i - (int)u.size() + 1, i);
        if (t0 == h0 && t1 == h1) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q >> s >> t;
    init();
    for (int i = 1; i <= q; i++) {
        cin >> k >> sq[i];
        eve[k].push_back({sq[i], i});
        ans[i] = -1;
        mx = max(mx, (int)sq[i].size());
    }
    for (; s.size() < mx && cur <= n; cur++) {
        init_hash();
        for (auto [s, ind] : eve[cur]) {
            ans[ind] = check(s);
        }
        if (cur < n) {
            s = s + t[cur] + s;
        }
    }
    init_hash();
    for (int i = 1; i <= q; i++) {
        in[i] = check(sq[i]);
    }
    for (char c = 'a'; c <= 'z'; c++) {
        string ts = s;
        s = s + c + s;
        init_hash();
        for (int i = 1; i <= q; i++) {
            out[i][c - 'a'] = pre_calc(sq[i]);
        }
        s = ts;
    }
    for (; cur <= n; cur++) {
        for (auto [s, ind] : eve[cur]) {
            ans[ind] = in[ind] * tin % MOD[0];
            for (int i = 0; i < C; i++) {
                (ans[ind] += cr[i] * out[ind][i]) %= MOD[0];
            }
        }
        (tin *= 2) %= MOD[0];
        for (int i = 0; i < C; i++) {
            (cr[i] *= 2) %= MOD[0];
        }
        if (cur < n) {
            (cr[t[cur] - 'a'] += 1) %= MOD[0];
        }
    }
    for (int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
    }
}