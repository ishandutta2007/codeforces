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
    vector<pii> res;

    void print() {
        for (auto [x, y] : res)
            cout << x + 1 << " " << y + 1 << "\n";
    }

    bool operator == (const output& o) const {
        return true;
    }
};

struct input {
    int n, k;
    vector<int> c;

    input() = default;

    void read() {
        cin >> n >> k;
        c.resize(n * k);
        for (auto& x : c) cin >> x, x--;
    }

    void print() {
        cout << n << " " << k << "\n";
        for (auto x : c)
            cout << x + 1 << " ";
        cout << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 25;
        const int MAXK = 25;
        n = rnd() % MAXN + 1;
        k = rnd() % (MAXK - 1) + 2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++)
                c.push_back(i);
        }
        shuffle(c.begin(), c.end(), rnd);
    }

    void gen_max_test() {

    }

    output fast() {
        vector<int> f(n * k, (n + k - 2) / (k - 1));
        vector<pii> segs;
        vector<int> last(n, -1), used(n);
        for (int i = 0; i < n * k; i++) {
            if (int j = last[c[i]]; j != -1) {
                segs.emplace_back(j, i);
            }
            last[c[i]] = i;
        }
        vector<pii> res;
        vector<int> S(n * k);
        for (int it = 0; it < n; it++) {
            for (int i = 0; i < n * k; i++) {
                S[i] = f[i] == 0;
                if (i) S[i] += S[i - 1];
            }
            int bl = -1, br = -1;
            for (auto [l, r] : segs) {
                if (used[c[l]]) continue;
                int tmp = S[r] - (l ? S[l - 1] : 0);
                if (tmp == 0 && (bl == -1 || br > r)) {
                    bl = l;
                    br = r;
                }
            }
            assert(bl != -1);
            used[c[bl]] = 1;
            res.emplace_back(bl, br);
            for (int i = bl; i <= br; i++)
                f[i]--;
        }
        sort(res.begin(), res.end(), [&](pii p1, pii p2) {
            return c[p1.first] < c[p2.first];
        });
        return output{res};
    }

#ifdef DEBUG
    output slow() {
        return fast();
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
        in.print();
        cout.flush();
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