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
    vector<int> res;
    ll score = 0;

    void print() {
        for (auto x : res)
            cout << x + 1 << " ";
        cout << "\n";
    }

    bool operator == (const output& o) const {
        cout << score << " vs " << o.score << "\n";
        return score == o.score;
    }
};

struct input {
    int n, m;
    vector<vector<int>> a;
    vector<int> x;

    input() = default;

    void read() {
        cin >> n >> m;
        x.resize(n);
        for (int i = 0; i < n; i++)
            cin >> x[i];
        a.resize(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            string buf;
            cin >> buf;
            for (int j = 0; j < m; j++) {
                a[i][j] = buf[j] - '0';
            }
        }
    }

    ll calc_score(vector<int> p) {
        ll score = 0;
        for (int i = 0; i < n; i++) {
            int ri = 0;
            for (int j = 0; j < m; j++) {
                ri += (p[j] + 1) * a[i][j];
            }
            score += abs(ri - x[i]);
        }
        return score;
    }

    void print() {
        cout << n << " " << m << "\n";
        for (int i = 0; i < n; i++)
            cout << x[i] << " ";
        cout << "\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << a[i][j];
            }
            cout << "\n";
        }
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 2;
        const int MAXM = 3;
        n = rnd() % MAXN + 1;
        m = rnd() % MAXM + 1;
        x.resize(n);
        for (int i = 0; i < n; i++)
            x[i] = rnd() % (m * (m + 1) / 2 + 1);
        a.resize(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = rnd() % 2;
            }
        }
    }

    output fast() {
        vector<int> res(m), tmp;
        iota(res.begin(), res.end(), 0);
        tmp = res;
        ll best_score = calc_score(res), tmp_score;
        auto update = [&]() {
            tmp_score = calc_score(tmp);
            if (tmp_score > best_score) {
                best_score = tmp_score;
                res = tmp;
            }
        };
        vector<int> phi(m), psi = tmp;
        for (int mask = 0; mask < (1 << n); mask++) {
            phi.assign(m, 0);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if ((1 << i) & mask) phi[j] -= a[i][j];
                    else phi[j] += a[i][j];
                }
            }
            sort(psi.begin(), psi.end(), [&](int i, int j) {
                return phi[i] < phi[j];
            });
            for (int i = 0; i < m; i++)
                tmp[psi[i]] = i;
            update();
            reverse(tmp.begin(), tmp.end());
            update();
        }
        return output{res, best_score};
    }

    output slow() {
        vector<int> perm(m), res(m);
        iota(perm.begin(), perm.end(),0);
        res = perm;
        ll best_score = calc_score(perm);
        do {
            ll tmp_score = calc_score(perm);
            if (tmp_score > best_score) {
                best_score = tmp_score;
                res = perm;
            }
        } while (next_permutation(perm.begin(), perm.end()));
        return output{res, best_score};
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