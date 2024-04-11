#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve();

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

template<typename T>
void setMax(T &t, T other) { t = max(t, other); }

template<typename T>
void setMin(T &t, T other) { t = min(t, other); }

#define answerExit(ans) { cout << (ans) << '\n'; exit(0); }
#define answerReturn(ans) { cout << (ans) << '\n'; return; }

int sign(int x) { return x < 0 ? -1 : (x > 0 ? 1 : 0); }

mt19937_64 rng(566);

int sans(int mask, int bit) { return mask & ~(1 << bit); }

int has(int mask, int bit) { return (mask >> bit) & 1; }

void solve() {
    int n;
    cin >> n;
    vector<char> s(1 << n);
    for (char &c : s) cin >> c;
    vector<char> t = s;
    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());
    vector<vector<int>> c(n + 1, vector<int>(1 << n));
    for (int i = 0; i < (1 << n); ++i) c[0][i] = lower_bound(t.begin(), t.end(), s[i]) - t.begin();
    vector<vector<int>> ord(n + 1, vector<int>(1 << n));
    iota(ord[0].begin(), ord[0].end(), 0);
    sort(ord[0].begin(), ord[0].end(), [&](int i, int j) { return s[i] < s[j]; });
    for (int bit = 1; bit <= n; ++bit) {
        auto cmp = [&](int mask1, int mask2) -> int {
            if (c[bit - 1][mask1] != c[bit - 1][mask2]) return c[bit - 1][mask1] - c[bit - 1][mask2];
            return c[bit - 1][mask1 ^ (1 << bit - 1)] - c[bit - 1][mask2 ^ (1 << bit - 1)];
        };
        iota(ord[bit].begin(), ord[bit].end(), 0);
        vector<vector<int>> x(4, vector<int>(4));
        for (int i = 0; i < 4; ++i)for (int j = 0; j < 4; ++j) x[i][j] = cmp(i, j);
        sort(ord[bit].begin(), ord[bit].end(), [&](int mask1, int mask2) {
            int c = cmp(mask1, mask2);
            return c < 0;
        });
        for (int i = 1; i < (1<<n); ++i) {
            c[bit][ord[bit][i]] = c[bit][ord[bit][i - 1]] + bool(cmp(ord[bit][i - 1], ord[bit][i]));
        }
    }
    for (int i = 0; i < (1 << n); ++i) cout << s[i ^ ord[n][0]];
}