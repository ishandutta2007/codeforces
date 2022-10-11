#pragma GCC optimize("O3")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            a[i][j] = (c == 'R' ? 0 : (c == 'G' ? 1 : (c == 'B' ? 2 : 3)));
        }

    vector<vector<array<int, 4>>> pref(n + 1, vector<array<int, 4>>(m + 1, {0, 0, 0, 0}));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < 4; k++)
                pref[i + 1][j + 1][k] = pref[i][j + 1][k] + pref[i + 1][j][k] - pref[i][j][k] + (a[i][j] == k);

    auto get_count = [&](int element, int lx, int ly, int rx, int ry) {
        rx++, ry++;
        return pref[rx][ry][element] - pref[lx][ry][element] - pref[rx][ly][element] + pref[lx][ly][element];
    };

    vector<vector<int>> value(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            auto good = [&]() {
                if (i - value[i][j] < 0 || i + 1 + value[i][j] >= n || j - value[i][j] < 0 || j + 1 + value[i][j] >= m)
                    return false;

                int need = (value[i][j] + 1) * (value[i][j] + 1);
                return get_count(0, i - value[i][j], j - value[i][j], i, j) == need
                    && get_count(1, i - value[i][j], j + 1, i, j + 1 + value[i][j]) == need
                    && get_count(2, i + 1, j + 1, i + 1 + value[i][j], j + 1 + value[i][j]) == need
                    && get_count(3, i + 1, j - value[i][j], i + 1 + value[i][j], j) == need;
            };

            while (good())
                value[i][j]++;
        }

    const int LG = __lg(max(n, m)) + 1;
    vector<vector<vector<vector<int>>>> sparse(n, vector<vector<vector<int>>>(m, vector<vector<int>>(LG, vector<int>(LG))));

    for (int l1 = 0; l1 < LG; l1++)
        for (int l2 = 0; l2 < LG; l2++)
            for (int i = 0; i + (1 << l1) <= n; i++)
                for (int j = 0; j + (1 << l2) <= m; j++)
                    if (l1 + l2 == 0)
                        sparse[i][j][l1][l2] = value[i][j];
                    else if (l1 > 0)
                        sparse[i][j][l1][l2] = max(sparse[i][j][l1 - 1][l2], sparse[i + (1 << (l1 - 1))][j][l1 - 1][l2]);
                    else
                        sparse[i][j][l1][l2] = max(sparse[i][j][l1][l2 - 1], sparse[i][j + (1 << (l2 - 1))][l1][l2 - 1]);

    auto get_max = [&](int lx, int ly, int rx, int ry) {
        if (rx < lx || ry < ly)
            return -1;

        rx++, ry++;
        int l1 = __lg(rx - lx);
        int l2 = __lg(ry - ly);
        return max({
            sparse[lx][ly][l1][l2],
            sparse[rx - (1 << l1)][ly][l1][l2],
            sparse[lx][ry - (1 << l2)][l1][l2],
            sparse[rx - (1 << l1)][ry - (1 << l2)][l1][l2]
        });
    };

    while (q--) {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        lx--, ly--, rx--, ry--;

        int l = 0, r = min((rx - lx + 1) / 2, (ry - ly + 1) / 2) + 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            (get_max(lx + mid - 1, ly + mid - 1, rx - mid, ry - mid) >= mid ? l : r) = mid;
        }
        cout << 4 * l * l << '\n';
    }
}