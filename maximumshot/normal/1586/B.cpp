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

struct input {
    int n, m;

    struct Triple {
        int a = 0;
        int b = 0;
        int c = 0;
    };

    vector<Triple> ts;

    input() = default;

    void read() {
        cin >> n >> m;
        ts.resize(m);
        for (auto& t : ts)
            cin >> t.a >> t.b >> t.c;
    }

    void print() {

    }

    void gen() {
        // use static
    }
};

struct output {
    vector<pii> edges;

    output() = default;

    void print() {
        for (auto [u, v] : edges)
            cout << u << " " << v << "\n";
    }

    bool operator == (const output& o) const {
        return true;
    }
};

output slow(input in) {
    return output();
}

output fast(input in) {
    output res;
    vector<int> used(in.n + 1);
    for (auto t : in.ts)
        used[t.b] = 1;
    int c = 1;
    while (used[c]) c++;
    for (int v = 1; v <= in.n; v++) {
        if (v != c)
            res.edges.emplace_back(v, c);
    }
    return res;
}

void test_case() {
    input in;
    in.read();
    output res = fast(in);
    res.print();
}

void work() {
    int t;
    cin >> t;
    while (t--)
        test_case();
}

void test() {
    while (1) {
        input in;
        in.gen();
        output fs = fast(in);
        output sl = slow(in);
        if (fs == sl) {
            cout << "OK" << endl;
            fs.print();
            cout << "\n=========" << endl;
        } else {
            cout << "WA\n";
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