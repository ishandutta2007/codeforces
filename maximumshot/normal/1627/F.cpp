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

struct input {
    int n, k;
    vector<pair<pii, pii>> a;

    input() = default;

    void read() {
        cin >> n >> k;
        a.resize(n);
        for (auto& [p1, p2] : a) {
            cin >> p1.first >> p1.second >> p2.first >> p2.second;
            p1.first--;
            p1.second--;
            p2.first--;
            p2.second--;
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
        vector<vector<int>> R(k + 1, vector<int>(k)), D(k, vector<int>(k + 1));
        for (auto [p1, p2] : a) {
            auto [r1, c1] = p1;
            auto [r2, c2] = p2;
            for (int it = 0; it < 2; it++) {
                if (r1 > r2 || c1 > c2) {
                    swap(r1, r2);
                    swap(c1, c2);
                    swap(p1, p2);
                }
                if (r1 == r2) {
                    D[r2][c2]++;
                } else {
                    R[r2][c2]++;
                }
                r1 = k - 1 - r1;
                c1 = k - 1 - c1;
                r2 = k - 1 - r2;
                c2 = k - 1 - c2;
            }
        }
        vector<vector<int>> dist(k + 1, vector<int>(k + 1, inf));
        dist[0][0] = 0;
        set<pair<int, pii>> Q;
        Q.insert({dist[0][0], {0, 0}});
        while (!Q.empty()) {
            auto [i, j] = Q.begin()->second;
            Q.erase(Q.begin());
            if (i < k && dist[i + 1][j] > dist[i][j] + D[i][j]) {
                Q.erase({dist[i + 1][j], {i + 1, j}});
                dist[i + 1][j] = dist[i][j] + D[i][j];
                Q.insert({dist[i + 1][j], {i + 1, j}});
            }
            if (j < k && dist[i][j + 1] > dist[i][j] + R[i][j]) {
                Q.erase({dist[i][j + 1], {i, j + 1}});
                dist[i][j + 1] = dist[i][j] + R[i][j];
                Q.insert({dist[i][j + 1], {i, j + 1}});
            }
            if (j > 0 && dist[i][j - 1] > dist[i][j] + R[i][j - 1]) {
                Q.erase({dist[i][j - 1], {i, j - 1}});
                dist[i][j - 1] = dist[i][j] + R[i][j - 1];
                Q.insert({dist[i][j], {i, j - 1}});
            }
            if (i > 0 && dist[i - 1][j] > dist[i][j] + D[i - 1][j]) {
                Q.erase({dist[i - 1][j], {i - 1, j}});
                dist[i - 1][j] = dist[i][j] + D[i - 1][j];
                Q.insert({dist[i - 1][j], {i - 1, j}});
            }
        }
        return output{n - dist[k / 2][k / 2]};
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