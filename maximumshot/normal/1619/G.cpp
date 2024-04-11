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
    int res = 0;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct DSU {
    int n = 0; // [0, n)
    vector<int> t, p;

    DSU(const vector<int>& t_) {
        t = t_;
        n = (int) t_.size();
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }


    void merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y)
            return;
        p[y] = x;
        t[x] = min(t[x], t[y]);
    }
};

struct input {
    int n, k;

    struct Mine {
        int x = 0;
        int y = 0;
        int timer;
        int id = 0;

        pii xy() {
            return {x, y};
        }

        pii yx() {
            return {y, x};
        }
    };

    vector<Mine> a;

    input() = default;

    void read() {
        cin >> n >> k;
        a.resize(n);
        for (int i = 0; i < n; i++) {
            auto& mine = a[i];
            cin >> mine.x >> mine.y >> mine.timer;
            mine.id = i;
        }
    }

    void print() {

    }

    void gen() {
        // use static
    }

    output fast() {
        vector<int> t(n);
        for (int i = 0; i < n; i++)
            t[i] = a[i].timer;
        DSU dsu(t);
        sort(a.begin(), a.end(), [](Mine m1, Mine m2) {
            return m1.xy() < m2.xy();
        });
        for (int i = 0; i + 1 < n; i++) {
            if (a[i].x == a[i + 1].x && a[i].y + k >= a[i + 1].y)
                dsu.merge(a[i].id, a[i + 1].id);
        }
        sort(a.begin(), a.end(), [](Mine m1, Mine m2) {
            return m1.yx() < m2.yx();
        });
        for (int i = 0; i + 1 < n; i++) {
            if (a[i].y == a[i + 1].y && a[i].x + k >= a[i + 1].x)
                dsu.merge(a[i].id, a[i + 1].id);
        }
        vector<int> ar;
        for (int i = 0; i < n; i++) {
            if (i == dsu.p[i])
                ar.push_back(dsu.t[i]);
        }
        sort(ar.begin(), ar.end());
        int res = inf + 10;
        for (int c = 0; c <= (int) ar.size(); c++) {
            int i = (int) ar.size() - 1 - c;
            int x = i >= 0 ? ar[i] : 0;
            int y = max(0, c - 1);
            res = min(res, max(x, y));
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