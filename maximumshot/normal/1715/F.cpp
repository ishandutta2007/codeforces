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

struct pt {
    ld x = 0;
    ld y = 0;
};

const ld eps = 1e-9;

int sgn(ld x) {
    return abs(x) < eps ? 0 : x < 0 ? -1 : +1;
}

int main() {

#ifdef DEBUG
//    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout.precision(15);
    cout << fixed;

    ld n, m;
    cin >> n >> m;

    auto ask = [&](vector<pt> P) -> ld {
        cout << "? " << (int) P.size() << "\n";
        for (auto p : P) {
            cout << p.x << " " << p.y << "\n";
        }
        cout.flush();
        ld res;
        cin >> res;
        return res;
    };

    vector<pt> Pa = {pt{0, 0}};
    for (int i = 0; i < n; i++) {
        Pa.push_back(pt{ld(i), m});
        Pa.push_back(pt{ld(i + 1), 0});
    }
    Pa.push_back(pt{n, -1});
    Pa.push_back(pt{0, -1});
    ld A = ask(Pa);

    vector<pt> Pb = {pt{0, 0}};
    for (int i = 0; i < m; i++) {
        Pb.push_back(pt{ld(n), ld(i)});
        Pb.push_back(pt{ld(0), ld(i + 1)});
    }
    Pb.push_back(pt{ld(-1), ld(m)});
    Pb.push_back(pt{ld(-1), ld(0)});
    ld B = ask(Pb);

    ld y = m - (A * m - ld(1) / ld(2)) - 1;
    ld x = n - (B * n - ld(1) / ld(2)) - 1;

    cout << "! " << x << " " << y << endl;

    return 0;
}