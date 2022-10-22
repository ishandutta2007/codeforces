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
        cout << (int) res.size() << "\n";
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    }

    bool operator == (const output& o) const {
        return true;
    }
};

struct input {
    int n;
    vector<int> a;

    input() = default;

    void read() {
        cin >> n;
        a.resize(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
    }

    void print() {
        cout << n << "\n";
        for (int i = 1; i <= n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 5;
        n = rnd() % MAXN + 1;
        a.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            int l = i - n;
            int r = i - 1;
            a[i] = l + int(rnd() % (r - l + 1));
        }
    };

    void gen_max_test() {

    }

    output fast() {
        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++) {
            p[i] = i - a[i];
        }
        vector<int> seq, used(n + 1);
        int x = 1;
        for (x = 1; !used[x]; x = p[x]) {
            used[x] = 1;
            seq.push_back(x);
        }
        reverse(seq.begin(), seq.end());
        while (seq.back() != x) seq.pop_back();
        ll s = 0;
        for (auto i : seq)
            s += a[i];
        assert(s == 0);
        return output{seq};
    }

#ifdef DEBUG
    output slow() {
        return fast();
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
        in.print();
        cout.flush();
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