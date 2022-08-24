#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = (int) 1e9 + 7;

int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}

int mult(int a, int b) {
    return (1LL * a * b) % mod;
}

int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}

int pw(int a, int b)  {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}

const int maxN = 1e6 + 10;
int pw2[maxN];
vector < int > z_function(string& s) {
    vector < int > z(s.size());
    int l = 0;
    int r = 0;
    for (int i = 1; i < s.size(); i++) {
        if (r < i) {
            l = r = i;
        }
        z[i] = min(r - i, z[i - l]);
        while (i + z[i] < s.size() && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}
const int maxQ = 1e5 + 10;
int posPref[maxQ];
string ask[maxQ];
int k[maxQ];
int ans[maxQ];
vector<pair<int,int>> add[maxQ];
int PREF[maxQ][26];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int n, q;
    cin >> n >> q;
    pw2[0] = 1;
    for (int i = 1; i < maxN; i++) {
        pw2[i] = mult(pw2[i - 1], 2);
    }
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < n; i++) {
        PREF[i][t[i] - 'a'] = sum(PREF[i][t[i] - 'a'], pw(pw2[i], mod - 2));
        if (i) {
            for (int j = 0; j < 26; j++) {
                PREF[i][j] = sum(PREF[i][j], PREF[i - 1][j]);
            }
        }
    }

    string big;
    big += s;
    for (int i = 1; i <= q; i++) {
        cin >> k[i] >> ask[i];
        posPref[i] = big.size();
        big += ask[i];
    }

    auto zz = z_function(big);
    string tue;
    for (int j = 0; j <= 20 && j < n; j++) {
        tue = tue + t[j] + tue;
    }

    for (int i = 1; i <= q; i++) {
        for (int len_pref = 0; len_pref <= s.size() && len_pref < ask[i].size(); len_pref++) {
            if (len_pref > 0 && s.substr(s.size() - len_pref) != ask[i].substr(0, len_pref)) continue;
            bool ok = true;
            int st = len_pref;
            string tt;
            while (st < ask[i].size()) {
                tt += ask[i][st];
                st += 1;
                if (st < ask[i].size() && zz[posPref[i] + st] < min((int)s.size(), (int)ask[i].size() - st)) {
                    ok = false;
                    break;
                }
                st += s.size();
            }
            if (ok) {
                int pos_pref = tue.size();
                tue += tt;
                reverse(tt.begin(), tt.end());
                int pos_suf = tue.size();
                tue += tt;
                add[i].emplace_back(pos_pref, pos_suf);
            }
        }
    }

    auto zz_tue = z_function(tue);
    for (int i = 1; i <= q; i++) {
        int ptr = 0;
        for (int len_pref = 0; len_pref <= s.size() && len_pref < ask[i].size(); len_pref++) {
            if (s.substr(s.size() - len_pref) != ask[i].substr(0, len_pref)) continue;
            bool ok = true;
            int st = len_pref;
            string tt;
            while (st < ask[i].size()) {
                tt += ask[i][st];
                st += 1;
                if (st < ask[i].size() && zz[posPref[i] + st] < min((int)s.size(), (int)ask[i].size() - st)) {
                    ok = false;
                    break;
                }
                st += s.size();
            }
            if (ok) {
                ptr++;
                int pos_pref = add[i][ptr - 1].first;
                int pos_suf = add[i][ptr - 1].second;
                for (int mx = 0; mx < tt.size(); mx++) {
                    if (mx + 1 < tt.size() && zz_tue[pos_pref + mx + 1] < (int)tt.size() - mx - 1) continue;
                    if (mx > 0 && zz_tue[pos_suf + tt.size() - mx - 1 + 1] < mx) continue;
                    int len = max(mx, (int)tt.size() - mx - 1) + 1;
                    int c = 0;
                    while ((1 << c) < len) c++;
                    if (k[i] >= 1 && c <= k[i] - 1) {
                        int tot = PREF[k[i] - 1][tt[mx] - 'a'];
                        if (c > 0) {
                            tot = sub(tot, PREF[c - 1][tt[mx] - 'a']);
                        }
                        ans[i] = sum(ans[i], mult(pw2[k[i] - 1], tot));
                    }
                }

            }
        }
        assert(ptr == add[i].size());
        if (ask[i].size() <= s.size()) {
            string rr = ask[i] + s;
            auto zt = z_function(rr);
            for (int j = 0; j < s.size(); j++) {
                if (zt[j + ask[i].size()] >= (int)ask[i].size()) ans[i] = sum(ans[i], pw2[k[i]]);
            }
        }
        cout << ans[i] << '\n';
    }
    return 0;
}