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
    int n, m;
    vector<int> a;
    vector<pii> b;

    input() = default;

    void read() {
        cin >> n >> m;
        a.resize(n);
        for (auto& x : a)
            cin >> x;
        b.resize(m);
        for (auto& [l, r] : b) {
            cin >> l >> r;
            l--, r--;
        }
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        vector<int> crd = a;
        sort(crd.begin(), crd.end());
        crd.erase(unique(crd.begin(), crd.end()), crd.end());
        int sz = (int) crd.size();
        for (auto& x : a)
            x = lower_bound(crd.begin(), crd.end(), x) - crd.begin();
        vector<int> prv(n, -1), last(sz, -1);
        for (int i = 0; i < n; i++) {
            prv[i] = last[a[i]];
            last[a[i]] = i;
        }
        int ql = inf, qr = -inf, cnt = 0;
        vector<int> f(n, -1);
        auto add_edge = [&](int l, int r) {
            cnt++;
            ql = min(ql, r);
            qr = max(qr, l);
            f[l] = max(f[l], r);
//            cout << "add " << l << " .. " << r << "\n";
        };
        {
            vector<int> g(n, -1);
            for (auto [l, r] : b) {
                g[l] = max(g[l], r);
            }
            for (int i = 1; i < n; i++)
                g[i] = max(g[i], g[i - 1]);
            vector<vector<int>> pos(sz);
            for (int i = 0; i < n; i++) {
                pos[a[i]].push_back(i);
            }
            int k = 300;
            for (int x = 0; x < sz; x++) {
                if ((int) pos[x].size() <= k) {
                    for (int l : pos[x]) {
                        for (int r : pos[x]) {
                            if (l < r && g[l] >= r) {
                                add_edge(l, r);
                            }
                        }
                    }
                } else {
                    for (auto [l, r] : b) {
                        int i = lower_bound(pos[x].begin(), pos[x].end(), l) - pos[x].begin();
                        if (i == (int) pos[x].size())
                            continue;
                        i = pos[x][i];
                        int j = upper_bound(pos[x].begin(), pos[x].end(), r) - pos[x].begin() - 1;
                        j = pos[x][j];
                        if (i < j && g[i] >= j) {
                            add_edge(i, j);
                        }
                    }
                }
            }
        }
        for (int i = 1; i < n; i++)
            f[i] = max(f[i], f[i - 1]);
        if (cnt == 0)
            return output{0};
        auto check = [&](int len) -> bool {
            for (int R = len - 1; R < n; R++) {
                int L = R - len + 1;
                if (R < qr || L > ql)
                    continue;
                if (L > 0 && f[L - 1] > R)
                    continue;
                return true;
            }
            return false;
        };
        check(1);
        int bl = 0, br = n, bm;
        while (br - bl > 1) {
            bm = bl + (br - bl) / 2;
            if (check(bm)) br = bm;
            else bl = bm;
        }
        return output{br};
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
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();
//    test();
//    max_test();

    return 0;
}