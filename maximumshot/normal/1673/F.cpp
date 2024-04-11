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

    int N = 32;

    auto calc_sum_len = [&](vector<vector<pii>> A) -> int {
        int sm = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (j + 1 < N) sm += A[i][j].first;
                if (i + 1 < N) sm += A[i][j].second;
            }
        }
        return sm;
    };

    function<vector<vector<pii>>(int, int)> build = [&](int n, int bit) -> vector<vector<pii>> {
        if (n == 1) return {{{0, 0}}};
        vector<vector<pii>> ar = build(n / 2, bit - 2);
        vector<vector<pii>> res(n, vector<pii>(n));
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                res[i][j] = res[i + n / 2][j] = res[i][j + n / 2] = res[i + n / 2][j + n / 2] = ar[i][j];
            }
        }
        for (int i = 0; i < n; i++)
            res[i][n / 2 - 1].first ^= 1 << bit;
        for (int j = 0; j < n; j++)
            res[n / 2 - 1][j].second ^= 1 << (bit + 1);
        return res;
    };

    vector<vector<pii>> ar = build(32, 8);

#ifdef DEBUG
    cout << "total = " << calc_sum_len(ar) << "\n";
#endif

    int n, k;
    cin >> n >> k;

    int mn = inf;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j + 1 < n; j++)
            cout << ar[i][j].first << " ", mn = min(mn, ar[i][j].first);
        cout << endl;
    }
    for (int i = 0; i + 1 < n; i++) {
        for (int j = 0; j < n; j++)
            cout << ar[i][j].second << " ", mn = min(mn, ar[i][j].second);
        cout << endl;
    }

#ifdef DEBUG
    cout << "mn = " << mn << "\n";
#endif

    function<pii(int, int, int, int, int, int)> find = [&](int xr, int li, int ri, int lj, int rj, int bit) -> pii {
        if (li == ri && lj == rj)
            return {li, lj};
        int mi = (li + ri) / 2;
        int mj = (lj + rj) / 2;
        int si = 0, sj = 0;
        if (xr & (1 << bit)) {
            lj = mj + 1;
            sj = 1;
        } else {
            rj = mj;
        }
        if (xr & (1 << (bit + 1))) {
            li = mi + 1;
            si = 1;
        } else {
            ri = mi;
        }
        auto [i, j] = find(xr, li, ri, lj, rj, bit - 2);
        assert(li <= i && i <= ri);
        assert(lj <= j && j <= rj);
        if (si) i = ri - (i - li);
        if (sj) j = rj - (j - lj);
        return {i, j};
    };

    auto get_path_xor = [&](int i, int j) -> int {
        int ci = 0, cj = 0, xr = 0;
        while (cj < j) xr ^= ar[ci][cj++].first;
        while (ci < i) xr ^= ar[ci++][cj].second;
        return xr;
    };

//    for (int i = 0; i < 32; i++) {
//        for (int j = 0; j < 32; j++) {
//            int xr = get_path_xor(i, j);
//            auto [ci, cj] = find(xr, 0, 31, 0, 31, 8);
//            cout << i << " " << j << " | " << xr << " | " << ci << " " << cj << "\n";
//            assert(i == ci && j == cj);
//        }
//    }

    int xr = 0;
    for (int it = 0; it < k; it++) {
        int x;
        cin >> x;
        xr ^= x;
        auto [i, j] = find(xr, 0, 31, 0, 31, 8);
        cout << i + 1 << " " << j + 1 << endl;
    }

    return 0;
}