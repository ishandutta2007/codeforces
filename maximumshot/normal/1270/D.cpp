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

    void print() {

    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {

    input() = default;

    void read() {

    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        return output();
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
#undef DEBUG
#ifdef DEBUG
//    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, m = -1;
#ifndef DEBUG
    cin >> n >> k;
#else
    const int MAXN = 100;
    static mt19937 rnd(time(NULL));
    n = rnd() % MAXN + 2;
    k = rnd() % (n - 1) + 1;
    m = rnd() % k + 1;
    vector<int> perm(n);
    iota(perm.begin(), perm.end(), 0);
    shuffle(perm.begin(), perm.end(), rnd);
    cout << n << " " << k << "\n";
    for (auto x : perm)
        cout << x << " ";
    cout << endl;
    cout << "res = " << m << "\n";
    cout.flush();
#endif

    auto ask = [&](vector<int> xs) -> pii {
#ifdef DEBUG
        sort(xs.begin(), xs.end(), [&](int i, int j) {
            return perm[i] < perm[j];
        });
        int pos = xs[m - 1];
        return {pos, perm[pos]};
#else
        cout << "? "; for (auto x : xs) cout << x + 1 << " "; cout << endl;
        int pos, val;
        cin >> pos >> val;
        return {pos - 1, val};
#endif
    };

    int res = -1;

    vector<int> a(k + 1, -1);
    static mt19937 gen(42);
    vector<int> f(k + 1);
    for (int i = 0; i <= k; i++) {
        vector<int> xs;
        for (int j = 0; j <= k; j++) {
            if (i == j) continue;
            xs.push_back(j);
        }
        auto [where, val] = ask(xs);
        a[where] = val;
        f[where]++;
//        cout << where << " !" << endl;
    }

    int pos = max_element(a.begin(), a.begin() + k + 1) - a.begin();
    res = f[pos];

#ifdef DEBUG
    cout << "found = " << res << "\n";
    assert(res == m);
#else
    cout << "! " << res << endl;
#endif

    return 0;
}