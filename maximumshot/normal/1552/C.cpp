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
        throw;
    }
};

struct input {
    int n, k;
    vector<pii> es;

    input() = default;

    void read() {
        cin >> n >> k;
        es.resize(k);
        for (auto& [u, v] : es) {
            cin >> u >> v;
            u--, v--;
        }
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        int res = 0;
        vector<int> used(2 * n);
        for (auto [u, v] : es) used[u] = used[v] = 1;
        vector<int> ar;
        for (int i = 0; i < 2 * n; i++) {
            if (!used[i])
                ar.push_back(i);
        }
        for (int sh = 0; sh <= n - k; sh++) {
            vector<pii> total = es;
            for (int i = 0; i < n - k; i++) {
                int u = (i + sh) % (int) ar.size();
                int v = (i + sh + n - k) % (int) ar.size();
                u = ar[u];
                v = ar[v];
                total.emplace_back(u, v);
            }
            for (auto& [u, v] : total) if (u > v) swap(u, v);
            sort(total.begin(), total.end());
            int tmp = 0;
            for (auto [u1, v1] : total) {
                for (auto [u2, v2] : total) {
                    if (u2 >= u1) break;
                    if (u1 < v2 && v2 < v1) tmp++;
                }
            }
            res = max(res, tmp);
        }
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