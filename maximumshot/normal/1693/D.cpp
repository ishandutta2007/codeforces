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
    ll res;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        return res == o.res;
    }
};

struct input {
    int n;
    vector<int> p;

    input() = default;

    void read() {
        cin >> n;
        p.resize(n);
        for (auto& x : p)
            cin >> x, x--;
    }

    void print() {
        cout << n << "\n";
        for (auto x : p)
            cout << x + 1 << " ";
        cout << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 15;
        n = rnd() % MAXN + 1;
        p.assign(n, 0);
        iota(p.begin(), p.end(), 0);
        shuffle(p.begin(), p.end(), rnd);
    }

    void gen_max_test() {

    }

    output fast() {
        vector<int> pos(n);
        for (int i = 0; i < n; i++)
            pos[p[i]] = i;
        deque<pii> low, high;
        low.emplace_back(-inf, -1);
        low.emplace_back(p[0], 0);
        high.emplace_back(+inf, -1);
        high.emplace_back(p[0], 0);
        auto get = [&]() -> tuple<int, int, int> {
            return {
                low[(int) low.size() - 2].first,
                low[(int) low.size() - 1].first,
                high[(int) high.size() - 2].first
            };
        };
        auto add = [&](int x, int i) -> bool {
            auto [A, B, C] = get();
            int can = 0;
            if (A < x && x < B) {
                high.emplace_back(x, i);
                low.pop_back();
                low.emplace_back(x, i);
                can = 1;
            } else if (B < x && x < C) {
                low.emplace_back(x, i);
                high.pop_back();
                high.emplace_back(x, i);
                can = 1;
            }
            return can;
        };
        auto rem = [&](int x, int i) {
            if (low[1].first == x) {
                low.pop_front();
                low.pop_front();
                low.emplace_front(-inf, -1);
            }
            if (high[1].first == x) {
                high.pop_front();
                high.pop_front();
                high.emplace_front(+inf, -1);
            }
        };
        vector<vector<pii>> L(n), R(n);
        vector<int> l_link(n, -1), r_link(n, -1);
        for (int l = 0, r = 0; l < n; l++) {
            while (r + 1 < n && add(p[r + 1], r + 1)) {
                r++;
            }
            l_link[l] = r;
            auto [A, B, C] = get();
            L[l] = {{A, B}, {B, C}};
            if (l + 1 < n)
                rem(p[l], l);
        }

        high.clear();
        low.clear();

        high.emplace_back(+inf, -1);
        high.emplace_back(p[n - 1], n - 1);
        low.emplace_back(-inf, -1);
        low.emplace_back(p[n - 1], n - 1);
        for (int l = n - 1, r = n - 1; l >= 0; l--) {
            r_link[l] = r;
            auto [A, B, C] = get();
            R[l] = {{B, A}, {C, B}};

            if (l > 0) {
                while (!add(p[l - 1], l - 1)) {
                    rem(p[r], r);
                    r--;
                }
            }
        }

        vector<int> inc(n), dec(n);
        for (int i = n - 1; i >= 0; i--) {
            if (i + 1 < n && p[i] < p[i + 1]) inc[i] = inc[i + 1] + 1;
            else inc[i] = 1;
            if (i + 1 < n && p[i] > p[i + 1]) dec[i] = dec[i + 1] + 1;
            else dec[i] = 1;
        }

        ll res = 0;
        for (int l = 0; l < n; l++) {
            int r = l_link[l], rr = r;
            if (r + 1 < n) {
                int ok = 0;
                for (auto [a1, b1] : L[l]) {
                    for (auto [a2, b2] : R[r + 1]) {
                        if (a1 < a2 && b1 > b2)
                            ok = 1;
                    }
                }
                if (ok)
                    r = max(r, r_link[r + 1]);
            }
            r = max(r, r_link[l]);
            if (rr + 1 < n) {
                for (auto [a, b] : L[l]) {
                    if (a < p[rr + 1]) r = max(r, rr + inc[rr + 1]);
                    if (b > p[rr + 1]) r = max(r, rr + dec[rr + 1]);
                }
            }
            res += r - l + 1;
//            cout << l << " : " << r << "\n";
        }

        return output{res};
    }

#ifdef DEBUG
    output slow() {
        ll res = 0;
        auto check = [](vector<int> a) -> bool {
            int n = (int) a.size();
            for (int mask = 0; mask < (1 << n); mask++) {
                int ok = 1;
                int high = inf, low = -inf;
                for (int i = 0; i < n; i++) {
                    if ((1 << i) & mask) {
                        if (a[i] > low) {
                            low = a[i];
                        } else {
                            ok = 0;
                        }
                    } else {
                        if (a[i] < high) {
                            high = a[i];
                        } else {
                            ok = 0;
                        }
                    }
                }
                if (ok)
                    return true;
            }
            return false;
        };
        for (int l = 0; l < n; l++) {
            vector<int> a;
            int rr = l;
            for (int r = l; r < n; r++) {
                a.push_back(p[r]);
                if (check(a)) res++, rr = r;
            }
            cout << l << " : " << rr << "\n";
        }
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