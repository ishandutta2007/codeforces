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

struct DSU {
    int n = 0; // [1, n]
    vector<int> p, sz;
    multiset<int> szs;
    int cnt = 0;

    DSU() = default;

    DSU(int nn) {
        n = nn;
        p.resize(n + 1);
        iota(p.begin(), p.end(), 0);
        sz.assign(n + 1, 1);
        for (int i = 1; i <= n; i++)
            szs.insert(1);
        cnt = n;
    }

    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        if (sz[x] < sz[y])
            swap(x, y);
        cnt--;
        p[y] = x;
        szs.erase(szs.find(sz[x]));
        szs.erase(szs.find(sz[y]));
        sz[x] += sz[y];
        szs.insert(sz[x]);
    }

    int get_max_comp_size() {
        return *(--szs.end());
    }

    vector<int> get_szs() {
        vector<int> res(szs.begin(), szs.end());
        res.pop_back();
        return res;
    }

    int get_n_comps() {
        return cnt;
    }
};

struct input {
    int n, d;
    vector<pii> cond;

    input() = default;

    void read() {
        cin >> n >> d;
        cond.resize(d);
        for (auto& [u, v] : cond)
            cin >> u >> v;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    output fast() {
        DSU dsu(n);
        vector<int> res;
        for (int i = 0; i < d; i++) {
            auto [u, v] = cond[i];
            dsu.merge(u, v);
            int rem = i + 1 - (n - dsu.get_n_comps());
            int tot = dsu.get_max_comp_size() - 1;
            vector<int> ar = dsu.get_szs();
            reverse(ar.begin(), ar.end());
            for (auto x : ar) {
                if (rem > 0) {
                    rem--;
                    tot += x;
                }
            }
            tot += rem;
            tot = min(tot, n - 1);
            res.push_back(tot);
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

    work();
//    test();

    return 0;
}