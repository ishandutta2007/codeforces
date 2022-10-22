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
    int n;
    ll k;
    vector<int> a;

    input() = default;

    void read() {
        cin >> n >> k;
        a.resize(n);
        for (auto& x : a)
            cin >> x;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    output fast() {
        if (n == 1)
            return output{max(0ll, a[0] - k)};
        sort(a.begin(), a.end());
        ll S = 0;
        for (auto x : a)
            S += x;
        if (S <= k)
            return output{0};
        ll res = S - k;
        S -= a[0];
        ll x = a[0];
        a.erase(a.begin());
        n--;
        reverse(a.begin(), a.end());
        for (int i = 0; i <= n; i++) {
            // y >= 0, y -> min
            // S + (i + 1) * (x - y) <= k
            // (i + 1) * (x - y) <= k - S
            // x - y <= (k - S) / (i + 1)
            // y >= x - (k - S) / (i + 1)
            ll y = (ll) ceil(x - ld(k - S) / ld(i + 1));
            y = max(0ll, y);
            res = min(res, y + i);
            if (i < n)
                S -= a[i];
        }
        return output{res};
    }

    output slow() {
        return output();
    }
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

    return 0;
}