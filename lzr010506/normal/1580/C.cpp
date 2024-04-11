#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int B = 300;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> x(n), y(n), op(m), k(m);
    for (int i = 0; i < n; i += 1) cin >> x[i] >> y[i];
    for (int i = 0; i < m; i += 1) cin >> op[i] >> k[i];
    map<int, int> mp;
    for (int i = 0; i < n; i += 1) mp[i] = m;
    vector<int> s(m);
    vector<vector<int>> sb(B + 1, vector<int>(m));
    auto add = [&](int i, int L, int R) {
        if (x[i] + y[i] > B) {
            for (LL j = L + x[i]; j <= R; j += x[i] + y[i]) {
                s[j] += 1;
                if (min(j + y[i], R + 1LL) < m) s[min(j + y[i], R + 1LL)] -= 1;
            }
        }
        else {
            for (int j = 0; j < y[i]; j += 1) {
                int l = L, r = R;
                int mod = x[i] + y[i], rem = (L + x[i] + j) % mod;
                l += (rem + mod - l % mod) % mod;
                r -= (r + mod - rem) % mod;
                r += mod;
                if (l >= r or l > m) continue;
                sb[mod][l] += 1;
                if (r < m) sb[mod][r] -= 1;
            }
        }
    };
    for (int i = m - 1; i >= 0; i -= 1) {
        k[i] -= 1;
        if (op[i] == 2) mp[k[i]] = i;
        else add(k[i], i, mp[k[i]] - 1);
    }
    for (int i = 1; i < m; i += 1) s[i] += s[i - 1];
    for (int i = 1; i <= B; i += 1)
        for (int j = i; j < m; j += 1) sb[i][j] += sb[i][j - i];
    for (int i = 0; i < m; i += 1) {
        int res = s[i];
        for (int j = 1; j <= B; j += 1) res += sb[j][i];
        cout << res << "\n";
    }
    return 0;
}