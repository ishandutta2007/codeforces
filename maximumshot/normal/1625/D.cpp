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
        if ((int) res.size() < 2) {
            cout << "-1\n";
        } else {
            cout << (int) res.size() << "\n";
            for (auto i : res)
                cout << i + 1 << " ";
            cout << "\n";
        }
    }

    bool operator == (const output& o) const {
        return true;
    }
};

struct Trie {
    int LOG;

    struct Node {
        vector<int> nxt = {-1, -1};
        pii leaf = {-1, -1};
    };

    vector<Node> t;

    Trie() = default;

    Trie(int LOG_) {
        LOG = LOG_;
        t.emplace_back();
    }

    void add(pii x) {
        int v = 0;
        for (int j = LOG - 1; j >= 0; j--) {
            int w = (x.first >> j) & 1;
            if (t[v].nxt[w] == -1) {
                t[v].nxt[w] = (int) t.size();
                t.emplace_back();
            }
            v = t[v].nxt[w];
        }
        t[v].leaf = x;
    }

    pii get(int x) {
        if ((int) t.size() == 1)
            return {-1, -1};
        int v = 0;
        for (int j = LOG - 1; j >= 0; j--) {
            int w = (x >> j) & 1;
            if (t[v].nxt[w ^ 1] != -1) {
                v = t[v].nxt[w ^ 1];
            } else {
                v = t[v].nxt[w];
            }
        }
        return t[v].leaf;
    }
};

struct input {
    int n, k;
    vector<pii> a;
    vector<int> vals;

    input() = default;

    void read() {
        cin >> n >> k;
        a.resize(n);
        vals.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first, a[i].second = i;
            vals[i] = a[i].first;
        }
    }

    void print() {

    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 50;
        const int MAX_LOG = 30;
        n = rnd() % MAXN + 2;
        k = rnd() % (1 << MAX_LOG);
        a.resize(n);
        vals.resize(n);
        for (int i = 0; i < n; i++) {
            a[i].first = vals[i] = rnd() % (1 << MAX_LOG);
            a[i].second = i;
        }
    }

    void gen_max_test() {

    }

    bool validate(vector<int> res) {
        for (int i : res) {
            for (int j : res) {
                if (i != j && (vals[i] ^ vals[j]) < k)
                    return false;
            }
        }
        return true;
    }

    output fast() {
        if (k == 0) {
            vector<int> res(n);
            iota(res.begin(), res.end(), 0);
            return output{res};
        }
        int high = 29;
        while (!((1 << high) & k))
            high--;
        int mask = 0;
        for (int j = high + 1; j < 30; j++)
            mask |= 1 << j;
        sort(a.begin(), a.end());
        vector<int> res;
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j < n && (a[i].first & mask) == (a[j].first & mask)) j++; j--;
            // [i, j]
            int p1 = -1, p2 = -1;
//            for (int q1 = i; q1 <= j; q1++) {
//                for (int q2 = q1 + 1; q2 <= j; q2++) {
//                    if ((a[q1].first ^ a[q2].first) >= k) {
//                        p1 = q1;
//                        p2 = q2;
//                    }
//                }
//            }
            Trie trie(30);
            for (int q = i; q <= j; q++) {
                auto [x, q2] = trie.get(a[q].first);
                if (q2 != -1 && (x ^ a[q].first) >= k) {
                    p1 = q2;
                    p2 = a[q].second;
                    break;
                }
                trie.add(a[q]);
            }
            if (p1 == -1) {
                res.push_back(a[i].second);
            } else {
                res.push_back(p1);
                res.push_back(p2);
            }
            i = j;
        }
#ifdef DEBUG
        assert(validate(res));
#endif
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