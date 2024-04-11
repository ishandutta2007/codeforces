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
            cout << x << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int n;
    struct Segment {
        int l, r, c;
    };
    vector<Segment> a;

    input() = default;

    void read() {
        cin >> n;
        a.resize(n);
        for (auto& seg : a)
            cin >> seg.l >> seg.r >> seg.c;
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
        int largest_seg_len = 0;
        int largest_seg_cost = 0;
        int L = inf + 10, R = -inf - 10;
        int Lc = 0, Rc = 0;
        for (int i = 0; i < n; i++) {
            auto s = a[i];
            int len = s.r - s.l + 1;
            if (largest_seg_len < len) {
                largest_seg_len = len;
                largest_seg_cost = s.c;
            } else if (largest_seg_len == len && largest_seg_cost > s.c) {
                largest_seg_cost = s.c;
            }
            if (s.l < L) {
                L = s.l;
                Lc = s.c;
            } else if (s.l == L && Lc > s.c) {
                Lc = s.c;
            }
            if (s.r > R) {
                R = s.r;
                Rc = s.c;
            } else if (s.r == R && Rc > s.c) {
                Rc = s.c;
            }
            int best_len = R - L + 1;
            int best_cost = Rc + Lc;
            if (best_len == largest_seg_len && best_cost > largest_seg_cost)
                best_cost = largest_seg_cost;
            res[i] = best_cost;
        }
        return output{res};
    }

    output slow() {
        return output();
    }
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