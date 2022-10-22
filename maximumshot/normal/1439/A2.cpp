#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

pair<vector<tuple<int, int, int>>, vector<tuple<int, int, int>>> precalc() {
    auto get_mask = [](vector<vector<int>> A) -> int {
        int n = (int) A.size();
        int m = (int) A[0].size();
        int mask = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (A[i][j])
                    mask |= (1 << (i * m + j));
        return mask;
    };

    auto get_table = [](int n, int m, int mask) -> vector<vector<int>> {
        vector<vector<int>> A(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                A[i][j] = (mask >>  (i * m + j)) & 1;
        return A;
    };

    auto _xor = [](vector<vector<int>> A, vector<vector<int>> B, int x, int y) -> vector<vector<int>> {
        vector<vector<int>> C = A;
        for (int i = 0; i < (int) B.size(); i++)
            for (int j = 0; j < (int) B[i].size(); j++)
                C[x + i][y + j] ^= B[i][j];
        return C;
    };

    vector<int> d6(1 << 6, inf);
    vector<tuple<int, int, int>> fr6(1 << 6, {-1, -1, -1});
    // {i, j, type}

    {
        d6[0] = 0;
        queue<int> que;
        que.push(0);
        while (!que.empty()) {
            int v = que.front();
            que.pop();

            vector<vector<int>> A = get_table(2, 3, v);

            for (int t = 0; t < 4; t++) {
                for (int i = 0; i + 1 < 2; i++) {
                    for (int j = 0; j + 1 < 3; j++) {
                        auto C = _xor(A, get_table(2, 2, 15 ^ (1 << t)), i, j);
                        int to = get_mask(C);
                        if (d6[to] > d6[v] + 1) {
                            d6[to] = d6[v] + 1;
                            fr6[to] = {i, j, t};
                            que.push(to);
                        }
                    }
                }
            }
        }
    }

    vector<int> d9(1 << 9, inf);
    vector<tuple<int, int, int>> fr9(1 << 9, {-1, -1, -1});
    // {i, j, type}

    {
        d9[0] = 0;
        queue<int> que;
        que.push(0);
        while (!que.empty()) {
            int v = que.front();
            que.pop();

            vector<vector<int>> A = get_table(3, 3, v);

            for (int t = 0; t < 4; t++) {
                for (int i = 0; i + 1 < 3; i++) {
                    for (int j = 0; j + 1 < 3; j++) {
                        auto C = _xor(A, get_table(2, 2, 15 ^ (1 << t)), i, j);
                        int to = get_mask(C);
                        if (d9[to] > d9[v] + 1) {
                            d9[to] = d9[v] + 1;
                            fr9[to] = {i, j, t};
                            que.push(to);
                        }
                    }
                }
            }
        }
    }
    return {fr6, fr9};
}

void solve(const vector<tuple<int, int, int>>& fr6, const vector<tuple<int, int, int>>& fr9) {

    auto get_mask = [](vector<vector<int>> A) -> int {
        int n = (int) A.size();
        int m = (int) A[0].size();
        int mask = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (A[i][j])
                    mask |= (1 << (i * m + j));
        return mask;
    };

    auto get_table = [](int n, int m, int mask) -> vector<vector<int>> {
        vector<vector<int>> A(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                A[i][j] = (mask >>  (i * m + j)) & 1;
        return A;
    };

    auto _xor = [](vector<vector<int>> A, vector<vector<int>> B, int x, int y) -> vector<vector<int>> {
        vector<vector<int>> C = A;
        for (int i = 0; i < (int) B.size(); i++)
            for (int j = 0; j < (int) B[i].size(); j++)
                C[x + i][y + j] ^= B[i][j];
        return C;
    };

    auto get_ops6 = [&](vector<vector<int>> A) -> vector<vector<pii>> {
        int mask = get_mask(A);
        vector<vector<pii>> res6;
        while (mask > 0) {
            auto [i, j, t] = fr6[mask];
            auto A = get_table(2, 3, mask);
            auto B = get_table(2, 2, 15 ^ (1 << t));
            auto C = _xor(A, B, i, j);
            vector<pii> ops;
            for (int x = 0; x < 2; x++)
                for (int y = 0; y < 2; y++)
                    if (B[x][y])
                        ops.emplace_back(i + x, j + y);
            res6.push_back(ops);
            mask = get_mask(C);
        }
        return res6;
    };

    auto get_ops9 = [&](vector<vector<int>> A) -> vector<vector<pii>> {
        int mask = get_mask(A);
        vector<vector<pii>> res9;
        while (mask > 0) {
            auto [i, j, t] = fr9[mask];
            auto A = get_table(3, 3, mask);
            auto B = get_table(2, 2, 15 ^ (1 << t));
            auto C = _xor(A, B, i, j);
            vector<pii> ops;
            for (int x = 0; x < 2; x++)
                for (int y = 0; y < 2; y++)
                    if (B[x][y])
                        ops.emplace_back(i + x, j + y);
            res9.push_back(ops);
            mask = get_mask(C);
        }
        return res9;
    };

    int n, m;
    cin >> n >> m;

    vector<vector<pii>> res;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
            a[i][j] = s[j] - '0';
    }

    auto process = [&](int i, int j) {
        int need = 0;
        for (int x = 0; x < 2; x++)
            for (int y = 0; y < 2; y++)
                if (a[i + x][j + y])
                    need ^= (1 << (x * 2 + y));
        for (int take = 0; take < (1 << 4); take++) {
            int mask = 0;
            for (int it = 0; it < 4; it++) {
                if ((1 << it) & take)
                    mask ^= (15 ^ (1 << it));
            }
            if (mask == need) {
                for (int it = 0; it < 4; it++) {
                    if ((1 << it) & take) {
                        vector<pii> op;
                        for (int x = 0; x < 2; x++) {
                            for (int y = 0; y < 2; y++) {
                                if (2 * x + y == it)
                                    continue;
                                op.emplace_back(i + x, j + y);
                                a[i + x][j + y] ^= 1;
                            }
                        }
                        res.push_back(op);
                    }
                }
                break;
            }
        }
    };

    for (int i = 0; i + 1 < n; i += 2) {
        for (int j = 0; j + 1 < m; j += 2) {
            if (i + 2 == n - 1 || j + 2 == m - 1)
                break;
            process(i, j);
        }
    }

    if (n % 2) {
        for (int j = 0; j + 1 < m; j += 2) {
            if (j + 2 == m - 1)
                break;
            vector<vector<int>> A(2, vector<int>(3));
            for (int x = 0; x < 2; x++)
                for (int y = 0; y < 3; y++)
                    A[x][y] = a[n - 3 + y][j + 1 - x];
            vector<vector<pii>> res6 = get_ops6(A);

            for (auto ops : res6) {
                vector<pii> _ops;

                for (auto [x, y] : ops) {
                    int I = n - 3 + y;
                    int J = j + 1 - x;
                    _ops.emplace_back(I, J);
                }

                for (auto [x, y] : _ops)
                    a[x][y] ^= 1;

                res.push_back(_ops);
            }
        }
    }

    if (m % 2) {
        for (int i = 0; i + 1 < n; i += 2) {
            if (i + 2 == n - 1)
                break;
            vector<vector<int>> A(2, vector<int>(3));
            for (int x = 0; x < 2; x++)
                for (int y = 0; y < 3; y++)
                    A[x][y] = a[i + x][m - 3 + y];
            vector<vector<pii>> res6 = get_ops6(A);
            for (auto ops : res6) {
                vector<pii> _ops;

                for (auto [x, y] : ops) {
                    _ops.emplace_back(i + x, m - 3 + y);
                }

                for (auto [x, y] : _ops)
                    a[x][y] ^= 1;

                res.push_back(_ops);
            }
        }
    }

    if (n % 2 && m % 2) {
        vector<vector<int>> A(3, vector<int>(3));
        for (int x = 0; x < 3; x++)
            for (int y = 0; y < 3; y++)
                A[x][y] = a[n - 3 + x][m - 3 + y];
        vector<vector<pii>> res9 = get_ops9(A);
        for (auto ops : res9) {
            vector<pii> _ops;

            for (auto [x, y] : ops)
                _ops.emplace_back(n - 3 + x, m - 3 + y);

            for (auto [x, y] : _ops)
                a[x][y] ^= 1;

            res.push_back(_ops);
        }
    }

    cout << (int) res.size() << "\n";
    for (auto op : res) {
        for (auto p : op)
            cout << p.first + 1 << " " << p.second + 1 << " ";
        cout << "\n";
    }

//    cout << "\n";
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            cout << a[i][j] << " ";
//        }
//        cout << "\n";
//    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    auto [fr6, fr9] = precalc();

    int t;
    cin >> t;

    while (t--) {
        solve(fr6, fr9);
    }

    return 0;
}