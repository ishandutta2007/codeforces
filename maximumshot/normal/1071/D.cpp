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

const int MAXX = 1e6 + 3;
int pr[MAXX];
vector<int> f[MAXX];
vector<vector<int>> states;

const int MAXD = 300;

void rec(vector<int> cur_state, int cur_mul, int minc) {
    states.push_back(cur_state);
    for (int c = minc; 1ll * cur_mul * c < MAXD; c++) {
        cur_state.push_back(c);
        rec(cur_state, cur_mul * c, c);
        cur_state.pop_back();
    }
}

vector<int> dist[MAXD];

//const int mod = inf + 7;
//const int P = 43;
//int calc_hash(const vector<int>& seq) {
//    int res = 0;
//    for (auto x : seq)
//        res = (1ll * res * P + x) % mod;
//    return res;
//}

int multiply(const vector<int>& a) {
    int res = 1;
    for (auto x : a)
        res *= x;
    return res;
}

void precalc() {
    fill(pr, pr + MAXX, 1);
    pr[0] = pr[1] = 0;
    for (int p = 2; p * p < MAXX; p++) {
        if (!pr[p])
            continue;
        for (int x = p * p; x < MAXX; x += p)
            pr[x] = 0;
    }
    for (int p = 2; p < MAXX; p++) {
        if (!pr[p])
            continue;
        for (int x = p; x < MAXX; x += p) {
            int c = 0;
            for (int y = x; y % p == 0; y /= p) c++;
            f[x].push_back(c + 1);
        }
    }
    for (int x = 2; x < MAXX; x++) {
        sort(f[x].begin(), f[x].end());
    }
    rec({}, 1, 2);
    sort(states.begin(), states.end());
    states.erase(unique(states.begin(), states.end()), states.end());
//    cout << "n_states = " << (int) states.size() << "\n";
    for (int d = 1; d < MAXD; d++) {
        dist[d].assign(states.size(), inf);
        queue<int> q;
        for (int i = 0; i < (int) states.size(); i++) {
            if (multiply(states[i]) == d) {
                dist[d][i] = 0;
                q.push(i);
            }
        }
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            {
                vector<int> ar = states[v];
                ar.insert(ar.begin(), 2);
                int pos = lower_bound(states.begin(), states.end(), ar) - states.begin();
                if (pos < (int) states.size() && states[pos] == ar) {
                    if (dist[d][pos] > dist[d][v] + 1) {
                        dist[d][pos] = dist[d][v] + 1;
                        q.push(pos);
                    }
                }
            }
            {
                if (!states[v].empty() && states[v].front() == 2) {
                    vector<int> ar = states[v];
                    ar.erase(ar.begin());
                    int pos = lower_bound(states.begin(), states.end(), ar) - states.begin();
                    if (pos < (int) states.size() && states[pos] == ar) {
                        if (dist[d][pos] > dist[d][v] + 1) {
                            dist[d][pos] = dist[d][v] + 1;
                            q.push(pos);
                        }
                    }
                }
            }
            for (int i = 0; i < (int) states[v].size(); i++) {
                vector<int> ar = states[v];
                for (int x : {-1, +1}) {
                    ar[i] += x;
                    if (ar[i] >= 2 && multiply(ar) < MAXD) {
                        int pos = lower_bound(states.begin(), states.end(), ar) - states.begin();
                        if (pos < (int) states.size() && states[pos] == ar) {
                            if (dist[d][pos] > dist[d][v] + 1) {
                                dist[d][pos] = dist[d][v] + 1;
                                q.push(pos);
                            }
                        }
                    }
                    ar[i] -= x;
                }
            }
        }
    }
}

struct input {
    int a, b;

    input() = default;

    void read() {
        cin >> a >> b;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        int res = inf;
        int posa = lower_bound(states.begin(), states.end(), f[a]) - states.begin();
        int posb = lower_bound(states.begin(), states.end(), f[b]) - states.begin();
        for (int d = 1; d < MAXD; d++) {
            res = min(res, dist[d][posa] + dist[d][posb]);
        }
        return output{res};
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
    int t = 1;
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

    precalc();
    work();
//    test();
//    max_test();

    return 0;
}