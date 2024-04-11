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

struct input {
    int n, k;
    vector<int> p;

    input() = default;

    void read() {
        cin >> n >> k;
        p.resize(n);
        for (auto& x : p) cin >> x, x--;
    }

    void print() {
        cout << n << " " << k << "\n";
        for (auto x : p)
            cout << x + 1 << " ";
        cout << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 15;
        const int MAXK = 8;
        n = rnd() % MAXN + 1;
        k = rnd() % MAXK + 1;
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        shuffle(p.begin(), p.end(), rnd);
    }

    void gen_max_test() {

    }

    output fast() {
        vector<int> rp(n);
        for (int i = 0; i < n; i++)
            rp[p[i]] = i;
        vector<vector<int>> cur(2 * k + 1, vector<int>(1 << k, inf)), nxt;
        for (int delta = -k; delta <= k; delta++) {
            int x = 0 + delta;
            if (x < 0 || x >= n) continue;
            cur[delta + k][0] = 0;
        }
        auto validate_state = [&](int i, int j) -> bool {
            return 0 <= i && i <= 2 * k + 1 && 0 <= j && j < (1 << k);
        };
        vector<vector<int>> F(n, vector<int>(n));
        for (int nx = 0; nx < n; nx++) {
            for (int j = 0; j < n; j++) {
                if (j) F[nx][j] = F[nx][j - 1];
                if (rp[nx] < rp[j]) F[nx][j]++;
            }
        }
        for (int i = 1; i < n; i++) {
            nxt.assign(2 * k + 1, vector<int>(1 << k, inf));
//            cout << i << "\n";
            for (int delta = -k; delta <= k; delta++) {
                int x = i - 1 + delta;
                if (x < 0 || x >= n) continue;
                for (int mask = 0; mask < (1 << k); mask++) {
                    if (cur[delta + k][mask] == inf)
                        continue;
                    int min_unused = x + 1;
                    int ok = 1;
                    for (int j = 0; j < k; j++) {
                        if ((1 << j) & mask) {
                            if (x - 1 - j < 0) ok = 0;
                            continue;
                        }
                        if (x - 1 - j >= 0)
                            min_unused = x - 1 - j;
                    }
                    if (!ok) continue;
                    for (int nx = max(0, x - k); nx < min({n, max(i, x) + k + 1}); nx++) {
                        if (nx < x - k || nx == x || min_unused < nx - k) continue;
                        if (nx < x && ((1 << (x - nx - 1)) & mask)) continue;
                        int nxt_x = max(x, nx);
                        int nxt_delta = nxt_x - i;
                        if (nxt_delta < -k || nxt_delta > k) continue;
                        int add = 0;
                        if (rp[nx] < rp[x]) add++;
                        for (int j = 0; j < k; j++) {
                            if ((1 << j) & mask) {
                                int val = x - 1 - j;
                                if (rp[nx] < rp[val]) add++;
                            }
                        }
                        if (x - k - 1 >= 0)
                            add += F[nx][x - k - 1];
//                        for (int j = 0; j < x - k; j++) {
//                            if (rp[nx] < rp[j]) add++;
//                        }
                        int nxt_mask = 0;
                        auto add_val = [&](int val) {
                            if (val < nxt_x - k || val >= nxt_x) return;
                            nxt_mask |= (1 << (nxt_x - val - 1));
                        };
                        add_val(x);
                        add_val(nx);
                        for (int j = 0; j < k; j++) {
                            if ((1 << j) & mask) {
                                int val = x - 1 - j;
                                add_val(val);
                            }
                        }
                        assert(validate_state(nxt_delta + k, nxt_mask));
                        assert(validate_state(delta + k, mask));
//                        cout << i << " x = " << x << " mask = " << bitset<1>(mask) << ", nx = " << nx << ", add = " << add << ", next_mask = " << nxt_mask << ", nxt_x = " << nxt_x << ", nxt_delta = " << nxt_delta << "\n";
                        nxt[nxt_delta + k][nxt_mask] = min(
                            nxt[nxt_delta + k][nxt_mask],
                            cur[delta + k][mask] + add
                        );
                    }
                }
            }
            swap(nxt, cur);
        }
        int res = inf;
        for (int delta = -k; delta <= k; delta++) {
            for (int mask = 0; mask < (1 << k); mask++)
                res = min(res, cur[delta + k][mask]);
        }
        return output{res};
    }

#ifdef DEBUG
    output slow() {
        vector<vector<int>> dp(n, vector<int>(1 << n, inf));
        for (int x = 0; x < n; x++) {
            dp[0][1 << x] = 0;
        }
        for (int i = 1; i < n; i++) {
            for (int mask = 0; mask < (1 << n); mask++) {
                for (int x = 0; x < n; x++) {
                    if ((1 << x) & mask)
                        continue;
                    int add = 0, ok = 1;
                    for (int y = 0; y < n; y++) {
                        if ((1 << y) & mask) {
                            if (p[y] > p[x] + k) ok = 0;
                            if (y > x) add++;
                        }
                    }
                    if (ok) {
                        dp[i][mask | (1 << x)] = min(dp[i][mask | (1 << x)], dp[i - 1][mask] + add);
                    }
                }
            }
        }
        int res = dp[n - 1][(1 << n) - 1];
        return output{res};
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
#ifdef DEBUG
    cin >> t;
#endif
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