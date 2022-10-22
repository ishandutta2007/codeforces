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

const ll X = 1e18 + 100;

struct output {
    ll res = 0;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        return res == o.res;
    }
};

int cnt_bit(ll x) {
    int res = 0;
    while (x > 0) {
        if (x & 1) res++;
        x >>= 1;
    }
    return res;
}

const int LOG = 70;
int CNT_MN[LOG];
int CNT_MX[LOG];

struct input {
    int n;
    vector<ll> a;

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

    void gen_max_test() {
        static mt19937_64 rnd(42);
        const int MAXN = 1e6;
        const ll MAXX = 1ll << 60;
        n = MAXN;
        a.resize(n);
        for (auto& x : a)
            x = rnd() % MAXX;
    }

    void gen() {
        static mt19937_64 rnd(42);
        const int MAXN = 100;
        const ll MAXX = 1ll << 10;
        n = rnd() % MAXN + 1;
        a.resize(n);
        for (auto& x : a)
            x = rnd() % MAXX;
    }


    output fast() {
        vector<int> cn(n);
        for (int i = 0; i < n; i++)
            cn[i] = cnt_bit(a[i]);

        ll res = n;

        vector<int> mn(n + 1), mx(n + 1);

        function<void(int, int)> rec = [&](int L, int R) {
            if (L == R)
                return;
            int M = (L + R) >> 1;
            rec(L, M);
            rec(M + 1, R);

            {
                int mn_pos = -1, mx_pos = -1;
                for (int i = M + 1; i <= R; i++) {
                    if (mn_pos == -1 || a[i] < a[mn_pos]) mn_pos = i;
                    if (mx_pos == -1 || a[i] > a[mx_pos]) mx_pos = i;
                    mn[i] = mn_pos;
                    mx[i] = mx_pos;
                }
            }
            {
                int mn_pos = -1, mx_pos = -1;
                for (int i = M; i >= L; i--) {
                    if (mn_pos == -1 || a[i] < a[mn_pos]) mn_pos = i;
                    if (mx_pos == -1 || a[i] > a[mx_pos]) mx_pos = i;
                    mn[i] = mn_pos;
                    mx[i] = mx_pos;
                }
            }

            {
                int mn_pos = -1, mx_pos = -1;
                int mx_ptr = M;
                int mn_ptr = M;

//                vector<int> CNT_MN(70), CNT_MX(70);
                fill(CNT_MN, CNT_MN + LOG, 0);
                fill(CNT_MX, CNT_MX + LOG, 0);

                for (int i = M; i >= L; i--) {
                    if (mn_pos == -1 || a[i] < a[mn_pos]) mn_pos = i;
                    if (mx_pos == -1 || a[i] > a[mx_pos]) mx_pos = i;

                    while (mx_ptr < R && a[mx_ptr + 1] <= a[mx_pos]) {
                        mx_ptr++;
                        CNT_MX[cn[mn[mx_ptr]]]++;
                    }
                    while (mn_ptr < R && a[mn_ptr + 1] >= a[mn_pos]) {
                        mn_ptr++;
                        CNT_MN[cn[mn[mn_ptr]]]++;
                    }

                    if (mn_ptr <= mx_ptr) {
                        if (cn[mn_pos] == cn[mx_pos])
                            res += max(0, mn_ptr - M);
//                        for (int j = M + 1; j <= mn_ptr; j++) {
//                            if (cn[mn_pos] == cn[mx_pos])
//                                res++;
//                        }
                        res += CNT_MX[cn[mx_pos]] - CNT_MN[cn[mx_pos]];
//                        for (int j = mn_ptr + 1; j <= mx_ptr; j++) {
//                            if (cn[mx_pos] == cn[mn[j]])
//                                res++;
//                        }
                    } else {
                        if (cn[mn_pos] == cn[mx_pos])
                            res += max(0, mx_ptr - M);
//                        for (int j = M + 1; j <= mx_ptr; j++) {
//                            if (cn[mn_pos] == cn[mx_pos])
//                                res++;
//                        }
                    }
                }
            }
            {
                int mn_pos = -1, mx_pos = -1;
                int mx_ptr = M + 1;
                int mn_ptr = M + 1;

                fill(CNT_MN, CNT_MN + LOG, 0);
                fill(CNT_MX, CNT_MX + LOG, 0);

                for (int i = M + 1; i <= R; i++) {
                    if (mn_pos == -1 || a[i] < a[mn_pos]) mn_pos = i;
                    if (mx_pos == -1 || a[i] > a[mx_pos]) mx_pos = i;

                    while (mx_ptr > L && a[mx_ptr - 1] < a[mx_pos]) {
                        mx_ptr--;
                        CNT_MX[cn[mn[mx_ptr]]]++;
                    }
                    while (mn_ptr > L && a[mn_ptr - 1] >= a[mn_pos]) {
                        mn_ptr--;
                        CNT_MN[cn[mn[mn_ptr]]]++;
                    }

                    if (mn_ptr >= mx_ptr) {
                        if (cn[mn_pos] == cn[mx_pos])
                            res += max(0, M - mn_ptr + 1);
//                        for (int j = M; j >= mn_ptr; j--) {
//                            if (cn[mn_pos] == cn[mx_pos])
//                                res++;
//                        }
                        res += CNT_MX[cn[mx_pos]] - CNT_MN[cn[mx_pos]];
//                        for (int j = mn_ptr - 1; j >= mx_ptr; j--) {
//                            if (cn[mx_pos] == cn[mn[j]])
//                                res++;
//                        }
                    } else {
                        if (cn[mn_pos] == cn[mx_pos])
                            res += max(0, M - mx_ptr + 1);
//                        for (int j = M; j >= mx_ptr; j--) {
//                            if (cn[mn_pos] == cn[mx_pos])
//                                res++;
//                        }
                    }
                }
            }
//            {
//                for (int r = M + 1; r <= R; r++) {
//                    for (int l = M; l >= L; l--) {
//                        int mn_pos = a[mn[l]] < a[mn[r]] ? mn[l] : mn[r];
//                        int mx_pos = a[mx[l]] > a[mx[r]] ? mx[l] : mx[r];
//                        if (cn[mn_pos] == cn[mx_pos] && a[mx[r]] > a[mx[l]])
//                            res++;
//                    }
//                }
//            }
        };

        rec(0, n - 1);

        return output{res};
    }

    output slow() {
        ll res = 0;
        for (int l = 0; l < n; l++) {
            ll mn = inf64 + 100, mx = -inf64 - 100;
            for (int r = l; r < n; r++) {
                mn = min(mn, a[r]);
                mx = max(mx, a[r]);
                if (cnt_bit(mn) == cnt_bit(mx))
                    res++;
            }
        }
        return output{res};
    }
};

void max_test() {
    input in;
    in.gen_max_test();
    output res = in.fast();
    res.print();
}

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
//    max_test();

    return 0;
}