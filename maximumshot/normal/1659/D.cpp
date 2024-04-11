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
            cout << x << " ";
        cout << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int n;
    vector<int> c;

    input() = default;

    void read() {
        cin >> n;
        c.resize(n);
        for (auto& x : c)
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
        vector<int> res(n);
        ll sm = 0;
        for (int i = 0; i < n; i++) sm += c[i];
        int total = sm / n;
        auto mem_c = c;
        vector<int> f(n);
        auto upd = [&](int i, int x) {
            for (int cur = i; cur < n; cur |= (cur + 1))
                f[cur] += x;
        };
        auto upd_seg = [&](int l, int r, int x) {
            if (l <= r) {
                upd(l, x);
                upd(r + 1, -x);
            }
        };
        auto get = [&](int i) -> int {
            int sm = 0;
            for (int cur = i; cur >= 0; cur = (cur & (cur + 1)) - 1)
                sm += f[cur];
            return sm;
        };
        for (int i = n - 1; i >= 0; i--) {
            if (c[i] + get(i) == i + 1) {
                res[i] = 1;
//                for (int j = i - total + 1; j <= i; j++)
//                    c[j]--;
                if (total > 0) upd_seg(i - total + 1, i, -1);
                total--;
            } else {
                res[i] = 0;
                if (total > 0) upd_seg(i - total + 1, i, -1);
//                for (int j = i - total + 1; j <= i; j++)
//                    c[j]--;
            }
        }
//        c = mem_c;
//
//        {
//            vector<int> cc(n), ar;
//            for (int i = 1; i <= n; i++) {
//                ar = res;
//                sort(ar.begin(), ar.begin() + i);
//                for (int j = 0; j < n; j++)
//                    cc[j] += ar[j];
//            }
//            cout << "exp = "; for (auto x : c) cout << x << " "; cout << "\n";
//            cout << "fnd = "; for (auto x : cc) cout << x << " "; cout << "\n";
//        }

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