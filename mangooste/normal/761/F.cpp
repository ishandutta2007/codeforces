#ifndef LOCAL
    #pragma GCC optimize("Ofast,O3,unroll-loops")
#endif

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vec vector
#define ar array

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif

#define int ll

inline char get_char() {
    char c;
    cin >> c;
    return c;
}

inline void init(vec<vec<ar<int, 26>>> &pref) {
    for (int i = 1; i < len(pref); i++) {
        for (int j = 1; j < len(pref[i]); j++) {
            for (int k = 0; k < 26; k++) {
                pref[i][j][k] += pref[i - 1][j][k] + pref[i][j - 1][k] - pref[i - 1][j - 1][k];
            }
        }
    }
}

inline void reset(vec<vec<ar<int, 26>>> &pref) {
    for (auto &xss : pref) {
        for (auto &xs : xss) {
            for (auto &x : xs) {
                x = 0;
            }
        }
    }
}

inline int get_cnt(vec<vec<ar<int, 26>>> &pref, int l1, int r1, int l2, int r2, int who) {
    return pref[l2 + 1][r2 + 1][who] - pref[l2 + 1][r1][who] - pref[l1][r2 + 1][who] + pref[l1][r1][who];
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m, nq;
    cin >> n >> m >> nq;
    vec<vec<pair<int, int>>> poses(26);
    vec<vec<ar<int, 26>>> pref(n + 2, vec<ar<int, 26>>(m + 2, ar<int, 26>()));
    vec<vec<int>> grid(n, vec<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int c = get_char() - 'a';
            poses[c].emplace_back(i, j);
            pref[i + 1][j + 1][c]++;
            grid[i][j] = c;
        }
    }
    init(pref);
    vec<int> start_cost(nq);
    vec<ar<int, 5>> queries;
    for (int i = 0; i < nq; i++) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2, l1--, r1--, l2--, r2--;
        int c = get_char() - 'a';
        for (int k = 0; k < 26; k++) {
            start_cost[i] += get_cnt(pref, l1, r1, l2, r2, k) * abs(k - c);
        }
        queries.push_back({l1, r1, l2, r2, c});
    }
    reset(pref);
    for (int i = 0; i < nq; i++) {
        auto [l1, r1, l2, r2, c] = queries[i];
        pref[l1 + 1][r1 + 1][c]++;
        pref[l2 + 2][r1 + 1][c]--;
        pref[l1 + 1][r2 + 2][c]--;
        pref[l2 + 2][r2 + 2][c]++;
    }
    init(pref);
    vec<ll> to_sub(nq);
    for (int i = 0; i < nq; i++) {
        to_sub[i] = -ll(nq) * start_cost[i];
    }
    vec<vec<ar<int, 26>>> want(n + 1, vec<ar<int, 26>>(m + 1, ar<int, 26>()));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 26; k++) {
                want[i + 1][j + 1][k] = get_cnt(pref, 0, 0, i, j, k);
            }
        }
    }
    init(want);
    for (int i = 0; i < nq; i++) {
        auto [l1, r1, l2, r2, c] = queries[i];
        for (int k = 0; k < 26; k++) {
            to_sub[i] -= abs(k - c) * get_cnt(want, l1, r1, l2, r2, k);
        }
    }
    reset(want);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 26; k++) {
                want[i + 1][j + 1][k] = get_cnt(pref, 0, 0, i, j, k) * abs(k - grid[i][j]);
            }
        }
    }
    init(want);
    for (int i = 0; i < nq; i++) {
        auto [l1, r1, l2, r2, c] = queries[i];
        for (int k = 0; k < 26; k++) {
            to_sub[i] += get_cnt(want, l1, r1, l2, r2, k);
        }
    }
    reset(want);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 26; k++) {
                want[i + 1][j + 1][grid[i][j]] += get_cnt(pref, 0, 0, i, j, k);
            }
        }
    }
    init(want);
    for (int i = 0; i < nq; i++) {
        auto [l1, r1, l2, r2, c] = queries[i];
        for (int k = 0; k < 26; k++) {
            to_sub[i] += get_cnt(want, l1, r1, l2, r2, k) * abs(k - c);
        }
    }
    cout << accumulate(all(start_cost), 0ll) - *max_element(all(to_sub)) << '\n';
}