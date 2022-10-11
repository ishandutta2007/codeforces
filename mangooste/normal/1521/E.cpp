#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define vec vector
#define ar array

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
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

void solve() {
    int m, k;
    cin >> m >> k;
    vec<int> cnt(k);
    for (auto &x : cnt) {
        cin >> x;
    }
    vec<int> sorted(k);
    iota(all(sorted), 0);
    sort(all(sorted), [&](int a, int b) { return cnt[a] > cnt[b]; });
    auto solve = [&](int n) {
        vec<pair<int, int>> ord;
        for (int i = 0; i < n; i += 2) {
            for (int j = 1; j < n; j += 2) {
                ord.emplace_back(i, j);
            }
        }
        for (int i = 0; i < n; i += 2) {
            for (int j = 0; j < n; j += 2) {
                ord.emplace_back(i, j);
            }
        }
        for (int i = 1; i < n; i += 2) {
            for (int j = 0; j < n; j += 2) {
                ord.emplace_back(i, j);
            }
        }
        if (len(ord) < m) return vec<vec<int>>();
        vec<vec<int>> mat(n, vec<int>(n));
        int pos = 0;
        for (auto i : sorted) {
            for (int j = 0; j < cnt[i]; j++) {
                mat[ord[pos].first][ord[pos].second] = i + 1;
                pos++;
            }
        }
        return mat;
    };
    int l = 0, r = min(1000, m);
    while (r - l > 1) {
        int mid = (l + r) / 2;
        auto mat = solve(mid);
        bool ok = (len(mat) >= 1);
        for (int i = 0; i < len(mat) && ok; i++) {
            for (int j = 0; j < len(mat) && ok; j++) {
                if (i >= 1 && j >= 1 && mat[i][j] == mat[i - 1][j - 1] && mat[i][j] != 0) ok = false;
                if (i < len(mat) - 1 && j > 0 && mat[i][j] == mat[i + 1][j - 1] && mat[i][j] != 0) ok = false;
            }
        }
        if (ok) {
            r = mid;
        } else {
            l = mid;
        }
    }
    auto mat = solve(r);
    cout << r << '\n';
    for (auto xs : mat) {
        for (auto x : xs) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}