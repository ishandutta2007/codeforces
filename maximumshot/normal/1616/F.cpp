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
    vector<int> res;

    void print() {
        if (can) {
            for (auto x : res)
                cout << x << " ";
            cout << "\n";
        } else {
            cout << "-1\n";
        }
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int n, m;

    struct Edge {
        int u, v, c;

        int get_to(int x) {
            return u ^ v ^ x;
        }
    };

    vector<Edge> edges;
    vector<vector<int>> g, G;

    input() = default;

    void read() {
        cin >> n >> m;
        edges.resize(m);
        g.resize(n + 1);
        G.resize(n + 1, vector<int>(n + 1, -1));
        for (int i = 0; i < m; i++) {
            auto& e = edges[i];
            cin >> e.u >> e.v >> e.c;
            g[e.u].push_back(i);
            g[e.v].push_back(i);
            G[e.u][e.v] = i;
            G[e.v][e.u] = i;
        }
    }

    void print() {

    }

    void gen() {
        // use static
    }

    output fast() {
        vector<vector<int>> A;
        vector<int> B;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (G[i][j] == -1)
                    continue;
                for (int k = j + 1; k <= n; k++) {
                    if (G[i][k] == -1 || G[j][k] == -1)
                        continue;
                    int e_ij = G[i][j];
                    int e_ik = G[i][k];
                    int e_jk = G[j][k];
                    vector<int> row(m);
                    row[e_ij] = row[e_ik] = row[e_jk] = 1;
                    A.push_back(row);
                    B.push_back(0);
                }
            }
        }
        for (int i = 0; i < m; i++) {
            int c = edges[i].c;
            if (c != -1) {
                vector<int> row(m);
                row[i] = 1;
                A.push_back(row);
                B.push_back(c % 3);
            }
        }
        int row, j;
        vector<int> C(A.size(), -1), R(m, -1);
        for (row = 0, j = 0; j < m; j++) {
            int i = row;
            while (i < (int) A.size() && !A[i][j])
                i++;
            if (i == (int) A.size())
                continue;
            swap(A[i], A[row]);
            swap(B[i], B[row]);
            for (i = row + 1; i < (int) A.size(); i++) {
                if (!A[i][j])
                    continue;
                int coef = -A[row][j] * A[i][j];
                coef = (coef % 3 + 3) % 3;
                for (int q = 0; q < m; q++) {
                    A[i][q] = (A[i][q] + coef * A[row][q]) % 3;
                }
                B[i] = (B[i] + coef * B[row]) % 3;
            }
            C[row] = j;
            R[j] = row;
            row++;
        }
        for (int i = row; i < (int) A.size(); i++) {
            if (B[i])
                return output{0, {}};
        }
        vector<int> x(m, -1);
        for (j = m - 1; j >= 0; j--) {
            if (R[j] == -1) {
                x[j] = 0;
                continue;
            }
            int need = 0;
            for (int k = j + 1; k < m; k++)
                need = (need + A[R[j]][k] * x[k]) % 3;
            need = (B[R[j]] - need) * A[R[j]][j];
            need = (need % 3 + 3) % 3;
            x[j] = need;
        }
        for (auto& elem : x) {
            if (!elem)
                elem += 3;
        }
        return output{1, x};
    }

    output slow() {
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

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();
//    test();

    return 0;
}