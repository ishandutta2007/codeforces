#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ui = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

const int inf = 1e9;
const ll inf64 = 1e18;

struct output {
    int can;
    vector<tuple<int, int, int>> res;

    void print() {
        if (can) {
            cout << "YES\n";
            cout << (int) res.size() << "\n";
            for (auto [x, y, z] : res)
                cout << x + 1 << " " << y + 1 << " " << z + 1 << "\n";
        } else {
            cout << "NO\n";
        }
    }

    bool operator == (const output& o) const {
        return can == o.can;
    }
};

vector<vector<int>> transpose(vector<vector<int>> A) {
    int n = (int) A.size();
    int m = (int) A[0].size();
    vector<vector<int>> res(m, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            res[j][i] = A[i][j];
    }
    return res;
}

output solve_slow(vector<int> b) {
    if (*max_element(b.begin(), b.end()) == 0)
        return output{1, {}};
    int n = (int) b.size();
    vector<vector<int>> A;
    vector<tuple<int, int, int>> ops;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int k = j + j - i;
            if (k < n) {
                vector<int> row(n);
                row[i] = row[j] = row[k] = 1;
                A.push_back(row);
                ops.emplace_back(i, j, k);
            }
        }
    }
    if (A.empty()) return output{0, {}};
    A = transpose(A);
    for (int i = 0; i < n; i++) {
        A[i].push_back(b[i]);
    }
    int M = (int) A[0].size();
    vector<int> row(M, -1);
    int r = 0;
    for (int j = 0; j + 1 < M && r < n; j++) {
        int q = r;
        while (q < n && !A[q][j]) q++;
        if (q == n) continue;
        swap(A[q], A[r]);
        for (q = 0; q < n; q++) {
            if (q == r) continue;
            if (!A[q][j]) continue;
            for (int t = 0; t < M; t++)
                A[q][t] ^= A[r][t];
        }
        row[j] = r;
        r++;
    }
    for (int q = r; q < n; q++) {
        if (A[q].back()) return output{0, {}};
    }
    vector<int> res(M);
    vector<tuple<int, int, int>> seq;
    for (int j = M - 2; j >= 0; j--) {
        r = row[j];
        if (r == -1) continue;
        int sm = 0;
        for (int nj = j + 1; nj + 1 < M; nj++)
            sm ^= (A[r][nj] & res[nj]);
        sm ^= A[r].back();
        res[j] = sm;
        if (sm) {
            seq.emplace_back(ops[j]);
        }
    }
    return output{1, seq};
}

struct input {
    int n;
    vector<int> a;

    input() = default;

    void read() {
        cin >> n;
        a.resize(n);
        for (auto& x : a)
            cin >> x;
    }

    void print() {
        cout << n << "\n";
        for (auto x : a)
            cout << x << " ";
        cout << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int MINN = 9;
        const int MAXN = 100;
        uniform_int_distribution<int> gen_n(MINN, MAXN);
        n = gen_n(rnd);
        a.resize(n);
        for (auto& x : a)
            x = rnd() % 2;
    }

    void gen_max_test() {

    }

    output fast() {
        vector<int> aa = a;
        vector<tuple<int, int, int>> res;
        auto op = [&](int x, int y, int z) {
            assert(0 <= x && x < y && y < z && x < n);
            assert(y - x == z - y);
            a[x] ^= 1;
            a[y] ^= 1;
            a[z] ^= 1;
            res.emplace_back(x, y, z);
        };
        int cur = 0;
        while (cur + 11 + 9 < n) {
            if (!a[cur]) {
                cur++;
                continue;
            }
            int sm = a[cur] + a[cur + 1] + a[cur + 2];
            if (sm == 0) {
                continue;
            } else if (sm == 3) {
                op(cur, cur + 1, cur + 2);
                continue;
            }
            if (sm == 1) {
                op(cur, cur + 3, cur + 6);
                continue;
            }
            assert(sm == 2);
            if (a[cur + 1] == 1) { // 110|***
                int n_sm = a[cur + 3] + a[cur + 4] + a[cur + 5];
                if (n_sm == 0) { // 110|000
                    op(cur, cur + 1, cur + 2);
                    op(cur + 2, cur + 6, cur + 10);
                    continue;
                } else if (n_sm == 3) { // 110|111
                    op(cur + 1, cur + 3, cur + 5); // 100|010
                    op(cur, cur + 4, cur + 8);
                    continue;
                } else if (n_sm == 1) {
                    int j = cur + 3;
                    while (!a[j]) j++;
                    op(cur, j, j + j - cur);
                    op(cur + 1, cur + 6, cur + 11);
                    continue;
                } else if (n_sm == 2) {
                    int j1 = cur + 3;
                    while (!a[j1]) j1++;
                    int j2 = j1 + 1;
                    while (!a[j2]) j2++;
                    op(cur, j1, j1 + j1 - cur);
                    op(cur + 1, j2, j2 + j2 - (cur + 1));
                    continue;
                }
            } else { // 101|***
                int n_sm = a[cur + 3] + a[cur + 4] + a[cur + 5];
                if (n_sm == 0) { // 101|000
                    op(cur + 2, cur + 4, cur + 6); // 100010
                    op(cur, cur + 4, cur + 8);
                } else if (n_sm == 3) { // 101|111
                    op(cur, cur + 2, cur + 4); // 000|101
                    op(cur + 3, cur + 5, cur + 7);
                } else if (n_sm == 1) { // 101|
                    int j = cur + 3;
                    while (!a[j]) j++;
                    op(cur, j, j + j - cur);
                    op(cur + 2, cur + 6, cur + 10);
                } else {
                    int j1 = cur + 3;
                    while (!a[j1]) j1++;
                    int j2 = j1 + 1;
                    while (!a[j2]) j2++;
                    op(cur, j1, j1 + j1 - cur);
                    op(cur + 2, j2, j2 + j2 - (cur + 2));
                    continue;
                }
            }
        }
        {
            vector<int> b(a.begin() + cur, a.end());
            output add = solve_slow(b);
            if (!add.can) return output{0, {}};
            for (auto [x, y, z] : add.res)
                res.emplace_back(cur + x, cur + y, cur + z);
        }
        assert((int) res.size() <= n / 3 + 12);
        for (auto [x, y, z] : res) {
            aa[x] ^= 1;
            aa[y] ^= 1;
            aa[z] ^= 1;
        }
        for (int i = 0; i < n; i++) {
            assert(aa[i] == 0);
        }
        return output{1, res};
    }

#ifdef DEBUG
    output slow() {
        return fast();
    }
#endif
};

void test_case() {
    input in;
    in.read();
    output res = in.fast();
    res.print();
}

void work() {
    int t = 1;
    while (t--)
        test_case();
}

#ifdef DEBUG
void test() {
    for (int t = 1;;t++) {
        input in;
        in.gen();
        in.print();
        cout.flush();
        input in_fs = in;
        input in_sl = in;
        output fs = in_fs.fast();
        output sl = in_sl.slow();
        if (fs == sl) {
            cout << "OK" << endl;
            fs.print();
            cout << "\n=========" << endl;
        } else {
            cout << "WA " << t << "\n";
            cout << "exp\n";
            sl.print();
            cout << "\n=========\n";
            cout << "fnd\n";
            fs.print();
            cout << "\n=========\n";
            in.print();
            break;
        }
    }
}
#endif

#ifdef DEBUG
void max_test() {
    input in;
    in.gen_max_test();
    input in_fs = in;
    output fs = in_fs.fast();
    fs.print();
}
#endif

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();
//    test();
//    max_test();

    return 0;
}