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

    void print() {
        for (auto x : res)
            cout << x << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

const vector<string> I = {"a", "b", "c", "ab", "bc"};
int N;
vector<vector<int>> mrg;
vector<int> states, st_to_pos;
vector<tuple<int, int, int>> merges;

void precalc() {
    N = 1 << (int) I.size();
    mrg.assign(N, vector<int>(N, -1));

    for (int x = 0; x < N; x++) {
        if (((1 << 3) & x) && !((1 << 0) & x)) continue;
        if (((1 << 3) & x) && !((1 << 1) & x)) continue;
        if (((1 << 4) & x) && !((1 << 1) & x)) continue;
        if (((1 << 4) & x) && !((1 << 2) & x)) continue;
        states.push_back(x);
    }

    st_to_pos.assign(N, -1);
    for (int i = 0; i < (int) states.size(); i++)
        st_to_pos[states[i]] = i;

    for (int x : states) {
        for (int y : states) {
            int ok = 1;
            for (int i = 0; i < (int) I.size(); i++) {
                if ((1 << i) & x) {
                    for (int j = 0; j < (int) I.size(); j++) {
                        if ((1 << j) & y) {
                            if ((I[i] == "a" && I[j] == "bc") || (I[i] == "ab" && I[j] == "c")) {
                                ok = 0;
                            }
                        }
                    }
                }
            }
            if (!ok)
                continue;
            int z = x | y;
            if (((1 << 0) & x) && ((1 << 1) & y))
                z |= 1 << 3;
            if (((1 << 1) & x) && ((1 << 2) & y))
                z |= 1 << 4;
            mrg[x][y] = z;
            merges.emplace_back(st_to_pos[x], st_to_pos[y], st_to_pos[z]);
        }
    }
}


struct RangeTree {
    int n = 0; // [0, n)

    struct Node {
        vector<int> dp;

        Node() {
            dp.assign(states.size(), 0);
        }

        Node(char x) {
            dp.assign(states.size(), 0);
            if (x == 'a') dp[1] = 1;
            if (x == 'b') dp[2] = 1;
            if (x == 'c') dp[4] = 1;
        }
    };

    Node merge(const Node& l, const Node& r) {
        Node res;
        for (auto [x, y, z] : merges)
            res.dp[z] = max(res.dp[z], l.dp[x] + r.dp[y]);
        return res;
    }

    vector<Node> t;

    RangeTree() = default;

    RangeTree(const string& s) {
        n = (int) s.size();
        t.resize(4 * n);
        build(1, 0, n - 1, s);
    }

    void build(int v, int tl, int tr, const string& s) {
        if (tl == tr) {
            t[v] = Node(s[tl]);
        } else {
            int tm = (tl + tr) >> 1;
            build(v << 1, tl, tm, s);
            build(v << 1 | 1, tm + 1, tr, s);
            t[v] = merge(t[v << 1], t[v << 1 | 1]);
        }
    }

    void update(int v, int tl, int tr, int pos, char symb) {
        if (tl == tr) {
            t[v] = Node(symb);
        } else {
            int tm = (tl + tr) >> 1;
            if (pos <= tm)
                update(v << 1, tl, tm, pos, symb);
            else
                update(v << 1 | 1, tm + 1, tr, pos, symb);
            t[v] = merge(t[v << 1], t[v << 1 | 1]);
        }
    }

    void update(int pos, char symb) {
        update(1, 0, n - 1, pos, symb);
    }

    int get_max() {
        return *max_element(t[1].dp.begin(), t[1].dp.end());
    }
};

struct input {
    int n, q;
    string s;
    vector<pair<int, char>> ops;

    input() = default;

    void read() {
        cin >> n >> q >> s;
        ops.resize(q);
        for (auto& [pos, symb] : ops) {
            cin >> pos >> symb;
            pos--;
        }
    }

    void print() {

    }

    void gen() {
        // use static
    }

    output fast() {
        RangeTree rt(s);
        vector<int> res;
        for (auto [pos, symb] : ops) {
            rt.update(pos, symb);
            res.push_back(n - rt.get_max());
        }
        return output{res};
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
    int t = 1;
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

    precalc();
    work();
//    test();

    return 0;
}