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
            cout << "YES\n";
            for (auto x : res)
                cout << x << " ";
            cout << "\n";
        } else {
            cout << "NO\n";
        }
    }

    bool operator == (const output& o) const {
        return can == o.can;
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
        cout << n << "\n";
        for (auto x : a)
            cout << x << " ";
        cout << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 8;
        n = rnd() % MAXN + 1;
        a.resize(n);
        for (auto& x : a)
            x = rnd() % n;
    }

    void gen_max_test() {

    }

    static bool check(vector<int> b) {
        int n = (int) b.size();
        for (int i = 0; i < n; i++) {
            int ni = (i + 1) % n;
            int pi = (i + n - 1) % n;
            if (b[i] > b[pi] && b[i] > b[ni]) {}
            else if (b[i] < b[pi] && b[i] < b[ni]) {}
            else return false;
        }
        return true;
    }

    output fast() {
        if (n % 2) return output{0, {}};
        sort(a.begin(), a.end());
        vector<int> b;
        for (int i = 0; i < n / 2; i++) {
            b.push_back(a[i]);
            b.push_back(a[i + n / 2]);
        }
        if (check(b)) return output{1, b};
        else return output{0, {}};
    }

#ifdef DEBUG
    output slow() {
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        do {
            vector<int> b(n);
            for (int i = 0; i < n; i++)
                b[p[i]] = a[i];
            if (check(b)) return output{1, b};
        } while (next_permutation(p.begin(), p.end()));
        return output{0, {}};
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