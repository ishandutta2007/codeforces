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
    string res;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int n, k;
    vector<int> b;

    input() = default;

    void read() {
        cin >> n >> k;
        b.resize(n);
        for (auto& x : b)
            cin >> x;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        vector<int> f(n + 1);
        for (int i = 1; i <= n; i++) {
            int x = i;
            while (x % 2 == 0) {
                f[i]++;
                x /= 2;
            }
            f[i] += f[i - 1];
        }
        auto binom = [&](int nn, int kk) -> int {
            if (nn < kk || kk < 0) return 0;
            int res = f[nn] - f[nn - kk] - f[kk];
            return res == 0 ? 1 : 0;
        };
        vector<vector<int>> C(30, vector<int>(n + 2));
        for (int i = 0; i < (int) C.size(); i++) {
            int N = n - i;
            for (int j = N; j >= 0; j--) {
                C[i][j] = (C[i][j + 1] + binom(N, j)) % 2;
            }
        }
        string res(1 << 20, '0');
        char delta = '0' ^ '1';
        for (int l = 0; l < n; l++) {
            int sm = 0;
            for (int r = l; r < n; r++) {
                if (r > l) sm += b[r];
                if (sm > 20 || 1ll * b[l] * (1ll << sm) >= (1ll << 20))
                    break;
                int pos = b[l] * (1 << sm);
                int N = n - 1 - (r - l);
                int K = k;
                if (l > 0) N--, K--;
                if (r + 1 < n) N--, K--;
//                cout << "pos = " << pos << " C(" << N << ", " << K << ") = " << binom(N, K) << ", [" << l << " .. " << r << "]\n";
                if (C[n - N][max(0, K)])
                    res[pos] ^= delta;
            }
        }
        while ((int) res.size() > 1 && res.back() == '0') res.pop_back();
        reverse(res.begin(), res.end());
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