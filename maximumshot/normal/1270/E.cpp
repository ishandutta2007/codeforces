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
            cout << x + 1 << " ";
        cout << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

ll sqr(ll x) {
    return 1ll * x * x;
}

struct pt {
    ll x = 0;
    ll y = 0;

    pt operator - (const pt& o) const {
        return {x - o.x, y - o.y};
    }

    ll scalar_mul(const pt& o) const {
        return x * o.x + y * o.y;
    }

    ll vector_mul(const pt& o) const {
        return x * o.y - o.x * y;
    }

    ll sqr_norm() const {
        return scalar_mul(*this);
    }
};

struct DSU {
    int n = 0; // [0, n)
    vector<int> p;

    DSU() = default;

    DSU(int nn) {
        n = nn;
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        p[y] = x;
    }
};

struct input {
    int n;
    vector<pt> a;

    input() = default;

    void read() {
        cin >> n;
        a.resize(n);
        for (auto& p : a)
            cin >> p.x >> p.y;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        for (auto& p : a) p.x += 1e7, p.y += 1e7;

        for (int it = 0; it < 20; it++) {
            vector<int> ar[2][2];
            for (int i = 0; i < n; i++) {
                auto p = a[i];
                ar[p.x % 2][p.y % 2].push_back(i);
            }
            int cnt = 0;
            for (int x = 0; x < 2; x++) {
                for (int y = 0; y < 2; y++) {
                    if (!ar[x][y].empty())
                        cnt++;
                }
            }
            if (cnt == 1) {
                for (auto& p : a) p.x /= 2, p.y /= 2;
                continue;
            }
            if ((int) ar[0][1].size() + (int) ar[1][0].size() > 0 &&
                (int) ar[0][0].size() + (int) ar[1][1].size() > 0) {
                vector<int> res;
                for (int i : ar[0][1]) res.push_back(i);
                for (int j : ar[1][0]) res.push_back(j);
                return output{res};
            } else {
                vector<int> res;
                for (int i : ar[0][0]) res.push_back(i);
                for (int j : ar[0][1]) res.push_back(j);
                return output{res};
            }
        }
        return output{{rand() % n}};
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
    int t = 1;
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