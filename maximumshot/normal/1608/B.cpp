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
            for (auto x : res)
                cout << x + 1 << " ";
            cout << "\n";
        } else {
            cout << "-1\n";
        }
    }

    bool operator == (const output& o) const {
        throw;
    }
};

pii calc(vector<int> p) {
    int n = (int) p.size();
    int a = 0, b = 0;
    for (int i = 1; i + 1 < n; i++) {
        if (p[i] > p[i - 1] && p[i] > p[i + 1]) a++;
        if (p[i] < p[i - 1] && p[i] < p[i + 1]) b++;
    }
    return {a, b};
}

struct input {
    int n, a, b;

    input() = default;

    void read() {
        cin >> n >> a >> b;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        if (a + b + 2 > n || abs(a - b) > 1)
            return output{0, {}};
        vector<int> res;
        if (a > b) {
            res.push_back(0);
            for (int l = 1, r = n - 1, i = 0; i < a; i++, l++, r--) {
                res.push_back(r);
                res.push_back(l);
            }
        } else if (a < b) {
            res.push_back(n - 1);
            for (int l = 0, r = n - 2, i = 0; i < b; i++, l++, r--) {
                res.push_back(l);
                res.push_back(r);
            }
        } else {
            for (int l = 0, r = n - 1, i = 0; i <= a; i++, l++, r--) {
                res.push_back(l);
                res.push_back(r);
            }
        }
        {
            vector<int> crd = res;
            sort(crd.begin(), crd.end());
            for (auto& x : res)
                x = lower_bound(crd.begin(), crd.end(), x) - crd.begin();
        }
        if (res.empty()) {
            res.assign(n, 0);
            iota(res.begin(), res.end(), 0);
        } else {
            int sz = (int) res.size();
            vector<int> used(n), rem;
            for (auto x : res) used[x] = 1;
            for (int i = 0; i < n; i++) {
                if (!used[i])
                    rem.push_back(i);
            }
            if (res[sz - 2] < res[sz - 1]) {
                for (auto x : rem) res.push_back(x);
            } else {
                for (auto& x : res) x += n - sz;
                for (auto& x : rem) x -= sz;
                reverse(rem.begin(), rem.end());
                for (auto x : rem) res.push_back(x);
            }
        }
#ifdef DEBUG
        if (auto tmp = calc(res); tmp != make_pair(a, b)) {
            cout << "WA\n";
            cout << "exp = " << a << " " << b << "\n";
            cout << "fnd = " << tmp.first << " " << tmp.second << "\n";
        }
#endif
        return output{1, res};
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

//    for (int n = 1; n <= 100; n++) {
//        for (int a = 0; a <= n; a++) {
//            for (int b = 0; b <= n; b++) {
//                input in;
//                in.n = n;
//                in.a = a;
//                in.b = b;
//                output res = in.fast();
//            }
//        }
//    }

    work();
//    test();
//    max_test();

    return 0;
}