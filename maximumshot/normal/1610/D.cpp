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

const int mod = 1'000'000'007;

int mul(int x, int y) {
    return (1ll * x * y) % mod;
}

void add(int& x, int y) {
    if ((x += y) >= mod)
        x -= mod;
}

int sub(int x, int y) {
    return x >= y ? x - y : x - y + mod;
}

int binpow(int x, int pw) {
    int res = 1, tmp = x;
    while (pw > 0) {
        if (pw & 1) res = mul(res, tmp);
        tmp = mul(tmp, tmp);
        pw >>= 1;
    }
    return res;
}

struct output {
    int res;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

int gcd(int x, int y) {
    return !x ? y : gcd(y % x, x);
}

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
    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        vector<int> fact(n + 1), rfact(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++)
            fact[i] = mul(fact[i - 1], i);
        rfact[n] = binpow(fact[n], mod - 2);
        for (int i = n - 1; i >= 0; i--)
            rfact[i] = mul(rfact[i + 1], i + 1);
        auto CNK = [&](int nn, int kk) -> int {
            if (nn < kk || kk < 0) return 0;
            return mul(fact[nn], mul(rfact[kk], rfact[nn - kk]));
        };
        vector<int> pw2(n + 1);
        pw2[0] = 1;
        for (int i = 1; i <= n; i++)
            pw2[i] = mul(pw2[i - 1], 2);
        vector<int> cnt(30);
        for (int i = 0; i < n; i++) {
            int j = 0;
            while (a[i] % 2 == 0) a[i] /= 2, j++;
            a[i] = j;
            cnt[a[i]]++;
        }
        int res = 0;
        add(res, mul(pw2[n - cnt[0]], sub(pw2[cnt[0]], 1)));
        int total = n - cnt[0];
        for (int j = 1; j < (int) cnt.size(); j++) {
            total -= cnt[j];
            int sm = 0;
            for (int i = 2; i <= cnt[j]; i += 2)
                add(sm, CNK(cnt[j], i));
            add(res, mul(sm, pw2[total]));
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