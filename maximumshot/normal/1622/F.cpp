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
            cout << x << " ";
        cout << "\n";
    }

    bool operator == (const output& o) const {
        return res.size() == o.res.size();
    }
};

const int MAXX = 1e6 + 5;

mt19937_64 GEN(42);
ll rad[MAXX], val[MAXX], fact_rad[MAXX];
int pr[MAXX];

void precalc() {
    iota(pr, pr + MAXX, 0);
    for (int p = 2; p * p < MAXX; p++) {
        if (pr[p] != p)
            continue;
        for (int x = 2 * p; x < MAXX; x += p)
            pr[x] = p;
    }
    for (int i = 2; i < MAXX; i++) {
        if (pr[i] == i)
            val[i] = GEN();
    }
    for (int i = 2; i < MAXX; i++) {
        rad[i] = rad[i / pr[i]] ^ val[pr[i]];
    }
    for (int i = 1; i < MAXX; i++) {
        fact_rad[i] = fact_rad[i - 1] ^ rad[i];
    }
}

struct input {
    int n;

    input() = default;

    void read() {
        cin >> n;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    vector<int> get_res(vector<int> a) {
        vector<int> used(n + 1), res;
        for (auto x : a)
            used[x] = 1;
        for (int i = 1; i <= n; i++) {
            if (!used[i])
                res.push_back(i);
        }
        return res;
    }

    output fast() {
        ll total = 0;
        for (int i = 1; i <= n; i++)
            total ^= fact_rad[i];
        if (total == 0)
            return output{get_res({})};
        for (int i = 1; i <= n; i++) {
            if ((total ^ fact_rad[i]) == 0) {
                return output{get_res({i})};
            }
        }
        unordered_map<ll, int> where;
        for (int i = 1; i <= n; i++)
            where[fact_rad[i]] = i;
        for (int i = 1; i <= n; i++) {
            auto fnd = where.find(total ^ fact_rad[i]);
            if (fnd != where.end()) {
                return output{get_res({i, fnd->second})};
            }
        }

        total ^= fact_rad[n];
        where.clear();
        for (int i = 1; i < n; i++)
            where[fact_rad[i]] = i;
        for (int i = 1; i < n; i++) {
            auto fnd = where.find(total ^ fact_rad[i]);
            if (fnd != where.end()) {
                return output{get_res({i, fnd->second, n})};
            }
        }
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
    int t = 1;
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

    precalc();
    work();
//    test();

    return 0;
}