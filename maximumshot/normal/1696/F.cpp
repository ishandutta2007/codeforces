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
    vector<pii> es;

    void print() {
        if (can) {
            cout << "Yes\n";
            for (auto [x, y] : es) {
                cout << x + 1 << " " << y + 1 << "\n";
            }
        } else {
            cout << "No\n";
        }
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int n;
    vector<vector<vector<int>>> a;

    input() = default;

    void read() {
        cin >> n;
        a.resize(n, vector<vector<int>>(n, vector<int>(n)));
        for (int x = 0; x < n; x++) {
            for (int y = x + 1; y < n; y++) {
                string buf;
                cin >> buf;
                for (int z = 0; z < n; z++)
                    a[x][y][z] = buf[z] - '0';
            }
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
        vector<int> blocked(n);
        vector<pii> es;
        vector<vector<int>> color(n, vector<int>(n, -1));
        for (int v = 0; v < n; v++) {
            int cc = 0;
            for (int u = 0; u < n; u++) {
                if (color[v][u] != -1)
                    continue;
                color[v][u] = cc;
                for (int w = u + 1; w < n; w++) {
                    if (a[u][w][v]) {
                        color[v][w] = cc;
                    }
                }
                cc++;
            }
        }
        vector<int> used(n), de(n);
        int used_timer = 10;
        for (int rem = n, it = 0; it < n - 1; it++, rem--) {
            int leaf = -1;
            int best_d = -1;
            for (int v = 0; v < n; v++) {
                if (blocked[v])
                    continue;
                used_timer++;
                int depth = 0;
                for (int u = 0; u < n; u++) {
                    int c = color[v][u];
                    if (c == -1) continue;
                    if (used[c] != used_timer) {
                        used[c] = used_timer;
                        depth++;
                    }
                }
                de[v] = depth;
                if (depth > best_d) {
                    best_d = depth;
                    leaf = v;
                }
            }
            vector<vector<int>> need, buf(n);
            for (int v = 0; v < n; v++) {
                int c = color[leaf][v];
                if (v == leaf || c == -1) continue;
                buf[c].push_back(v);
            }
            for (int c = 0; c < n; c++) {
                if (buf[c].empty()) continue;
                need.push_back(buf[c]);
                buf[c].clear();
            }
            sort(need.begin(), need.end());
            int cand = -1;
            for (int v = 0; v < n; v++) {
                if (v == leaf || blocked[v] || (de[v] > 2 && de[v] != de[leaf] - 1)) continue;
                for (int u = 0; u < n; u++) {
                    int c = color[v][u];
                    if (u == leaf || c == -1) continue;
                    buf[c].push_back(u);
                }
                vector<vector<int>> tmp;
                for (int c = 0; c < n; c++) {
                    if (buf[c].empty()) continue;
                    tmp.push_back(buf[c]);
                    buf[c].clear();
                }
                sort(tmp.begin(), tmp.end());
                if (tmp == need) {
                    cand = v;
                    break;
                }
            }
            if (cand == -1)
                return output{0, {}};
            es.emplace_back(leaf, cand);
            blocked[leaf] = 1;
            for (int v = 0; v < n; v++) {
                color[v][leaf] = -1;
            }
        }
        vector<vector<int>> D(n, vector<int>(n, inf));
        for (int v = 0; v < n; v++) D[v][v] = 0;
        for (auto [u, v] : es)
            D[u][v] = D[v][u] = 1;
        for (int w = 0; w < n; w++) {
            for (int u = 0; u < n; u++) {
                for (int v = 0; v < n; v++) {
                    D[u][v] = min(D[u][v], D[u][w] + D[w][v]);
                }
            }
        }
        for (int x = 0; x < n; x++) {
            for (int y = x + 1; y < n; y++) {
                for (int z = 0; z < n; z++) {
                    if (a[x][y][z] != int(D[x][z] == D[y][z]))
                        return output{0, {}};
                }
            }
        }
        return output{1, es};
    }

#ifdef DEBUG
    output slow() {
        return output();
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
    int t;
    cin >> t;
    while (t--)
        test_case();
}

#ifdef DEBUG
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