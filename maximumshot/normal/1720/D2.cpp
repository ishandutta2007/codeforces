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

const int LOG = 30;

struct Trie {

    struct Node {
        int dp[2] = {0, 0};
        int nxt[2] = {-1, -1};
    };

    vector<Node> t;

    Trie() {
        t.emplace_back();
    }

    void add(int i, int ai, int f) {
        int v = 0;
        for (int bit = LOG - 1; bit >= 0; bit--) {
            int x_bit = ((i ^ ai) >> bit) & 1;
            int to = t[v].nxt[x_bit];
            if (to == -1) {
                to = t[v].nxt[x_bit] = (int) t.size();
                t.emplace_back();
            }
            v = to;
            t[v].dp[(i >> bit) & 1] = max(t[v].dp[(i >> bit) & 1], f);
        }
    }

    int query(int i, int ai) {
        int res = 0;
        int v = 0;
        for (int bit = LOG - 1; bit >= 0 && v != -1; bit--) {
            int x_bit = ((i ^ ai) >> bit) & 1;
            int to = t[v].nxt[x_bit ^ 1];
            if (to != -1) {
                int j_bit = ((ai >> bit) & 1) ^ 1;
                res = max(res, t[to].dp[j_bit]);
            }
            v = t[v].nxt[x_bit];
        }
        return res;
    }
};

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

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        vector<int> dp(n);
        int res = 0;
        Trie trie;
        for (int i = 0; i < n; i++) {
            dp[i] = 1 + trie.query(i, a[i]);
            trie.add(i, a[i], dp[i]);
            res = max(res, dp[i]);
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