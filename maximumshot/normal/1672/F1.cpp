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
            cout << x + 1 << " ";
        cout << "\n";
    }

    bool operator == (const output& o) const {
        throw;
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
            cin >> x, x--;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        vector<int> b(n);
        vector<vector<int>> pos(n);
        set<int> non_empty;
        for (int i = 0; i < n; i++)
            pos[a[i]].push_back(i);
        for (int x = 0; x < n; x++) {
            if (!pos[x].empty())
                non_empty.insert(x);
        }
        while (!non_empty.empty()) {
            vector<int> perm, to_del;
            for (int x : non_empty) {
                int i = pos[x].back();
                pos[x].pop_back();
                perm.push_back(i);
                if (pos[x].empty())
                    to_del.push_back(x);
            }
            int sz = (int) perm.size();
            for (int i = 0; i < sz; i++) {
                int j = (i + 1) % sz;
                b[perm[i]] = a[perm[j]];
            }
            for (int x : to_del)
                non_empty.erase(x);
        }
        return output{b};
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