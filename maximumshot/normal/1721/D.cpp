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
        return res == o.res;
    }
};

struct input {
    int n;
    vector<int> a, b;

    input() = default;

    void read() {
        cin >> n;
        a.resize(n);
        b.resize(n);
        for (auto& x : a) cin >> x;
        for (auto& x : b) cin >> x;
    }

    void print() {
        cout << n << "\n";
        for (auto x : a) cout << x << " "; cout << "\n";
        for (auto x : b) cout << x << " "; cout << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAX_BIT = 3;
        const int MAXN = 5;
        n = rnd() % MAXN + 1;
        a.resize(n);
        b.resize(n);
        for (auto& x : a) x = rnd() % (1 << MAX_BIT);
        for (auto& x : b) x = rnd() % (1 << MAX_BIT);
    }

    void gen_max_test() {

    }

    bool check(int mask) {
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++)
            cnt[a[i] & mask]++;
        for (int i = 0; i < n; i++) {
            int need = (b[i] & mask) ^ mask;
            if (cnt[need] == 0) return false;
            cnt[need]--;
        }
        return true;
    }

    output fast() {
        int mask = 0;
        for (int bit = 29; bit >= 0; bit--) {
            if (check(mask | (1 << bit)))
                mask |= 1 << bit;
        }
        return output{mask};
    }

#ifdef DEBUG
    output slow() {
        sort(b.begin(), b.end());
        int res = 0;
        do {
            int tmp = ((1 << 30) - 1);
            for (int i = 0; i < n; i++)
                tmp &= (a[i] ^ b[i]);
            res = max(res, tmp);
        } while (next_permutation(b.begin(), b.end()));
        return output{res};
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
    // test();
//    max_test();

    return 0;
}