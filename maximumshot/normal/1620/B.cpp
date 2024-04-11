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
    ll res = 0;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    ll w, h;
    vector<ll> xs[2], ys[2];

    input() = default;

    void read() {
        cin >> w >> h;
        for (int i = 0; i < 2; i++) {
            int sz;
            cin >> sz;
            xs[i].resize(sz);
            for (auto& x : xs[i])
                cin >> x;
            sort(xs[i].begin(), xs[i].end());
            xs[i] = {xs[i].front(), xs[i].back()};
        }
        for (int i = 0; i < 2; i++) {
            int sz;
            cin >> sz;
            ys[i].resize(sz);
            for (auto& y : ys[i])
                cin >> y;
            ys[i] = {ys[i].front(), ys[i].back()};
        }
    }

    void print() {

    }

    void gen() {
        // use static
    }

    output fast() {
        ll res = max({
             1ll * (xs[0].back() - xs[0].front()) * max(ys[0].back(), ys[1].back()),
             1ll * (xs[1].back() - xs[1].front()) * (h - min(ys[0].front(), ys[1].front())),
             1ll * (ys[0].back() - ys[0].front()) * max(xs[0].back(), xs[1].back()),
             1ll * (ys[0].back() - ys[0].front()) * (w - min(xs[0].front(), xs[1].front())),
             1ll * (xs[0].back() - xs[0].front()) * h,
             1ll * (xs[1].back() - xs[1].front()) * h,
             1ll * (ys[0].back() - ys[0].front()) * w,
             1ll * (ys[1].back() - ys[1].front()) * w,
        });
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

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();
//    test();

    return 0;
}