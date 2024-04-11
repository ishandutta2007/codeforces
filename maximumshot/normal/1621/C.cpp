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
    vector<int> p;

    void print() {
        cout << "! ";
        for (auto x : p)
            cout << x << " ";
        cout << endl;
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int n;

    input() = default;

    void read() {
        cin >> n;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    int ask(int i) {
        cout << "? " << i << endl;
        int res;
        cin >> res;
        return res;
    }

    output fast() {
        vector<int> used(n + 1), p(n + 1);
        for (int s = 1; s <= n; s++) {
            if (used[s])
                continue;
            int x = ask(s);
            used[x] = 1;
            vector<int> cycle = {x};
            while (1) {
                int y = ask(s);
                if (y == x)
                    break;
                cycle.push_back(y);
                used[y] = 1;
            }
            int sz = (int) cycle.size();
            for (int i = 0; i < sz; i++) {
                int j = (i + 1) % sz;
                p[cycle[i]] = cycle[j];
            }
        }
        p.erase(p.begin());
        return output{p};
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

void max_test() {
    input in;
    in.gen_max_test();
    input in_fs = in;
    output fs = in_fs.fast();
    fs.print();
}

int main() {

#ifdef DEBUG
//    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();
//    test();
//    max_test();

    return 0;
}