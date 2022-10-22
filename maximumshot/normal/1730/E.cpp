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
    vector<int> a;

    input() = default;

    void read() {
        cin >> n;
        a.resize(n);
        for (auto& x : a)
            cin >> x;
    }

    void print() {
        cout << n << "\n";
        for (auto x : a)
            cout << x << " ";
        cout << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 50;
        const int MAXX = 100;
        n = rnd() % MAXN + 1;
        a.resize(n);
        for (auto& x : a)
            x = rnd() % MAXX + 1;
    }

    void gen_max_test() {

    }

    output fast() {
        int X = *max_element(a.begin(), a.end()) + 1;
        ll res = 0;
        vector<int> LE(n), RI(n), le(n), ri(n);
        {
            vector<int> st;
            for (int i = 0; i < n; i++) {
                while (!st.empty() && a[i] > a[st.back()]) st.pop_back();
                LE[i] = st.empty() ? 0 : st.back() + 1;
                st.push_back(i);
            }
        }
        {
            vector<int> st;
            for (int i = n - 1; i >= 0; i--) {
                while (!st.empty() && a[i] >= a[st.back()]) st.pop_back();
                RI[i] = st.empty() ? n - 1 : st.back() - 1;
                st.push_back(i);
            }
        }
        {
            vector<int> st;
            for (int i = 0; i < n; i++) {
                while (!st.empty() && a[i] <= a[st.back()]) st.pop_back();
                le[i] = st.empty() ? 0 : st.back() + 1;
                st.push_back(i);
            }
        }
        {
            vector<int> st;
            for (int i = n - 1; i >= 0; i--) {
                while (!st.empty() && a[i] <= a[st.back()]) st.pop_back();
                ri[i] = st.empty() ? n - 1 : st.back() - 1;
                st.push_back(i);
            }
        }
        vector<vector<int>> pos(X);
        for (int i = 0; i < n; i++) {
            pos[a[i]].push_back(i);
        }
        vector<ll> F(X);
        for (int mn = 1; mn < X; mn++) {
            if (pos[mn].empty()) continue;
            for (int mx = mn; mx < X; mx += mn) {
                ll T = 0;
                for (int i : pos[mx]) {
                    int min_l = LE[i], max_l = i;
                    int min_r = i, max_r = RI[i];
                    int ql = upper_bound(pos[mn].begin(), pos[mn].end(), i) - pos[mn].begin() - 1;
                    int cc = 0;
                    if (ql >= 0) {
                        int j = pos[mn][ql];
                        int tmp_min_l = max(min_l, le[j]);
                        int tmp_max_l = min(max_l, j);
                        int tmp_min_r = max(min_r, j);
                        int tmp_max_r = min(max_r, ri[j]);
                        ll tmp = 1ll * max(0, tmp_max_l - tmp_min_l + 1) * max(0, tmp_max_r - tmp_min_r + 1);
                        T += tmp;
                        res += tmp;
                        cc++;
                    }
                    if (mn == mx) {
                        continue;
                    }
                    int qr = ql + 1;
                    if (qr < (int) pos[mn].size()) {
                        int j = pos[mn][qr];
                        int tmp_min_l = max(min_l, le[j]);
                        int tmp_max_l = min(max_l, j);
                        int tmp_min_r = max(min_r, j);
                        int tmp_max_r = min(max_r, ri[j]);
                        ll tmp = 1ll * max(0, tmp_max_l - tmp_min_l + 1) * max(0, tmp_max_r - tmp_min_r + 1);
                        T += tmp;
                        res += tmp;
                        cc++;
                    }
                    if (cc == 2) {
                        int j1 = pos[mn][ql];
                        int j2 = pos[mn][qr];
                        int tmp_min_l = max({min_l, le[j1], le[j2]});
                        int tmp_max_l = min(max_l, j1);
                        int tmp_min_r = max(min_r, j2);
                        int tmp_max_r = min({max_r, ri[j1], ri[j2]});
                        ll tmp = 1ll * max(0, tmp_max_l - tmp_min_l + 1) * max(0, tmp_max_r - tmp_min_r + 1);
                        T -= tmp;
                        res -= tmp;
                    }
                }
//                cout << mn << " .. " << mx << " : " << T << "\n";
            }
        }
        return output{res};
    }

#ifdef DEBUG
    output slow() {
        ll res = 0;
        for (int l = 0; l < n; l++) {
            int mn = a[l], mx = a[l];
            for (int r = l; r < n; r++) {
                mn = min(mn, a[r]);
                mx = max(mx, a[r]);
                if (mx % mn == 0)
                    res++;
            }
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
//#ifdef DEBUG
    cin >> t;
//#endif
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