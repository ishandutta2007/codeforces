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

vector<pii> compress(vector<pii> a) {
    sort(a.begin(), a.end());
    vector<pii> res;
    for (int i = 0; i < (int) a.size(); i++) {
        int j = i, sm = 0;
        while (j < (int) a.size() && a[i].first == a[j].first) {
            sm += a[j].second;
            j++;
        }
        i = j - 1;
        res.emplace_back(a[i].first, sm);
    }
    return res;
}

struct input {
    int n;
    vector<int> a;

    input() = default;

    void read() {
        cin >> n;
        a.resize(n);
        for (auto& x : a) cin >> x;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        vector<pii> ar;
        for (int i = 0; i < n; i++) {
            ar.emplace_back(a[i], 1);
        }
        for (int it = 0; it < n - 1; it++) {
            ar = compress(ar);
            vector<pii> nx;
            for (int i = 0; i < (int) ar.size(); i++) {
                if (ar[i].second > 1) {
                    nx.emplace_back(0, ar[i].second - 1);
                }
                if (i + 1 < (int) ar.size())
                    nx.emplace_back(ar[i + 1].first - ar[i].first, 1);
            }
            swap(ar, nx);
        }
        int res = ar.front().first;
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