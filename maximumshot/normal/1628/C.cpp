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
    int res;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

vector<pii> get_spiral(int n) {
    vector<pii> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int cur_dir = 0;
    vector<vector<int>> used(n, vector<int>(n));
    int i = 0, j = 0;
    vector<pii> res;
    while (1) {
        used[i][j] = 1;
        res.emplace_back(i, j);
        int any = 0;
        for (int it = 0; it < 2; it++) {
            auto [di, dj] = dirs[cur_dir];
            int ti = i + di;
            int tj = j + dj;
            if (0 <= ti && ti < n && 0 <= tj && tj < n && !used[ti][tj]) {
                i = ti;
                j = tj;
                any = 1;
                break;
            }
            cur_dir = (cur_dir + 1) % 4;
        }
        if (!any)
            break;
    }
    return res;
}

struct input {
    int n;
    vector<vector<int>> a;

    input() = default;

    void read() {
        cin >> n;
        a.resize(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        }
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        vector<pii> spiral = get_spiral(n / 2);

        const string DIRS = "RDLU";
        auto get_next_dir = [&](char dir) -> char {
            for (int i = 0; i < 4; i++) {
                if (DIRS[i] == dir)
                    return DIRS[(i + 1) % 4];
            }
        };
        char dir = 'R';
        vector<pii> seq;

        for (int it = 0; it < (int) spiral.size(); it++) {
            auto [i, j] = spiral[it];
            int ok = it + 1 < (int) spiral.size();
            if (dir == 'R') {
                seq.emplace_back(2 * i, 2 * j);
                seq.emplace_back(2 * i, 2 * j + 1);
                if (ok && spiral[it].first != spiral[it + 1].first) {
                    dir = get_next_dir(dir);
                    seq.emplace_back(2 * i + 1, 2 * j + 1);
                }
            } else if (dir == 'D') {
                seq.emplace_back(2 * i, 2 * j + 1);
                seq.emplace_back(2 * i + 1, 2 * j + 1);
                if (ok && spiral[it].second != spiral[it + 1].second) {
                    dir = get_next_dir(dir);
                    seq.emplace_back(2 * i + 1, 2 * j);
                }
            } else if (dir == 'L') {
                seq.emplace_back(2 * i + 1, 2 * j + 1);
                seq.emplace_back(2 * i + 1, 2 * j);
                if (ok && spiral[it].first != spiral[it + 1].first) {
                    dir = get_next_dir(dir);
                    seq.emplace_back(2 * i, 2 * j);
                }
            } else if (dir == 'U') {
                seq.emplace_back(2 * i + 1, 2 * j);
                seq.emplace_back(2 * i, 2 * j);
                if (ok && spiral[it].second != spiral[it + 1].second) {
                    dir = get_next_dir(dir);
                    seq.emplace_back(2 * i, 2 * j + 1);
                }
            }
        }

//        for (auto [i, j] : seq)
//            cout << "(" << i << ", " << j << ")\n";
//        cout << "\n";

        int res = 0;
        for (int i = 0; i < (int) seq.size(); i += 4) {
            for (int j = 0; j < 2; j++) {
                auto [x, y] = seq[i + j];
                res ^= a[x][y];
            }
        }

        return output{res};
    }

    output slow() {
#ifndef DEBUG
        throw;
#endif
        return output();
    }
};

void test_case() {
    input in;
    in.read();
    output res = in.fast();
    res.print();
}

void work() {
    int t;
    cin >> t;
    while (t--)
        test_case();
}

void test() {
    for (int t = 1;;t++) {
        input in;
        in.gen();
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

void max_test() {
    input in;
    in.gen_max_test();
    input in_fs = in;
    output fs = in_fs.fast();
    fs.print();
}

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