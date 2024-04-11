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
        throw;
    }
};

struct input {
    string s;

    input() = default;

    void read() {
        cin >> s;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {
        int n = 2e5;
        s.resize(n, '0');
        static mt19937 rnd(42);
        for (char& c : s) c = rnd() % 2 + '0';
    }

    output fast() {
        int n = (int) s.size();
        int sq = 1;
        while (sq * sq <= n) sq++;
        sq = 800;
        ll res = 0;
        { // c <= sq
            for (int c = 1; c <= sq; c++) {
                for (int xl = 0, xr = 0, l = 0, r = 0, i = 0; i < n; i++) {
                    xl += s[i] == '1';
                    xr += s[i] == '1';
                    while (l <= i && xl > c) {
                        xl -= s[l] == '1';
                        l++;
                    }
                    while (r <= i && xr >= c) {
                        xr -= s[r] == '1';
                        r++;
                    }
                    if (l < r) {
                        // l + d = need
                        // [0, r - l)
                        int d = (i + 1 - l) % c;
                        // 0 <= d + c * k <= r - l - 1
                        // 0 <= k <= (r - l - 1 - d) / c
                        if (r - l - 1 >= d)
                            res += (r - l - d - 1) / c + 1;
                    }
                }
            }
        }
        { // c > sq, k <= sq
            vector<int> A(n);
            for (int i = 0; i < n; i++) {
                A[i] = (i > 0 ? A[i - 1] : 0) + int(s[i] == '1');
            }
            int maxk = n / sq;
            vector<int> ar, f(n + 1), where(n + 1), cnt;
            for (int i = -1; i < n; i++)
                f[i + 1] = -i;
            for (int k = 1; k <= maxk; k++) {
                for (int i = 0; i < n; i++)
                    f[i + 1] += A[i];
                ar = f;
                sort(ar.begin(), ar.end());
                ar.erase(unique(ar.begin(), ar.end()), ar.end());
                for (int i = -1; i < n; i++)
                    where[i + 1] = lower_bound(ar.begin(), ar.end(), f[i + 1]) - ar.begin();
                cnt.assign(ar.size(), 0);
                for (int r = -1, i = 0; i < n; i++) {
                    while (r < i && A[i] - (r >= 0 ? A[r] : 0) > sq) {
                        cnt[where[r + 1]]++;
                        r++;
                    }
                    assert(r <= i);
                    // A[j] < A[i] - sq
                    // A[i] * k - A[j] * k == i - j
                    // A[i] * k - i == A[j] * k - j
                    res += cnt[where[i + 1]];
//                    for (int j = -1; j < r; j++) {
//                        if ((j >= 0 ? A[j] : 0) * k - j == need)
//                            res++;
//                    }
                }
            }
        }
        return output{res};
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
    // max_test();

    return 0;
}