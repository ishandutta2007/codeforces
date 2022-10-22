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

//    vector<int> ls = {5, 2, 7, 3, 5, 6};
//
//    auto ask = [&](int w) {
//        if (*max_element(ls.begin(), ls.end()) > w) return 0;
//        int have = 0;
//        int h = 0;
//        for (auto l : ls) {
//            int will = have > 0 ? have + 1 + l : l;
//            if (will <= w) {
//                have = will;
//            } else {
//                h++;
//                have = l;
//            }
//        }
//        if (have > 0) h++;
//        return h;
//    };

    int n;
    cin >> n;

    unordered_map<int, int> mem;
    int total = 0;
    int limit = n + 30;

    auto ask = [&](int w) {
        if (mem.count(w)) return mem[w];
        total++;
        if (total > limit) return 0;
        cout << "? " << w << endl;
        int h;
        cin >> h;
        return mem[w] = h;
    };

//    n = (int) ls.size();

    int ql = 0, qr = 2005, qm;
    while (qr - ql > 1) {
        qm = (ql + qr) >> 1;
        if (ask(qm) == 0) ql = qm;
        else qr = qm;
    }
    int mx = qr;

    int bl = mx - 1, br = (n + 1) * 2005 + 123, bm;
    while (br - bl > 1) {
        bm = (bl + br) >> 1;
        if (ask(bm) == 1) br = bm;
        else bl = bm;
    }
    int W = br;
//    cout << "W = " << W << "\n";

    int res = W;

    for (int h = 2; h <= n; h++) {
        int w = W / h;
        int hh = ask(w);
        if (hh > 0)
            res = min(res, w * hh);
    }

    cout << "! " << res << endl;

    return 0;
}