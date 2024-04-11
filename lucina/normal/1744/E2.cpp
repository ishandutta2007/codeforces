#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;


vector <int64_t> fac(int64_t x) {
    vector <int64_t> f;
    for (int64_t i = 1 ; i * i <= x ; ++ i) {
        if (x % i) continue;
        if (i * i == x) {
            f.push_back(i);
        } else {
            f.push_back(i);
            f.push_back(x / i);
        }
    }
    return f;
}

int64_t ceil_div(int64_t u, int64_t v) {
    return (u + v - 1) / v;
}

void solve() {
    int64_t a, b, c, d;
    cin >> a >> b >> c >> d;

    vector <int64_t> fac_a = fac(a), fac_b = fac(b);

    for (auto u : fac_a)
    for (auto v : fac_b) {
        /**
            suppose that x is in the form u * q1
        */
        int64_t da = a / u, db = b / v;
        int64_t la = ceil_div(a + 1, u), ra= c / u;
        int64_t lb = ceil_div(b + 1, v), rb = d / v;

        auto ok = [](int64_t u, int64_t b, int64_t d) -> pair <bool, int64_t> {
            u = u * ((b + u - 1) / u);
            return make_pair(u >= b && u <= d, u);
        };
        if (ok(da, lb, rb).first && ok(db, la, ra).first) {
            cout << u * ok(db, la, ra).second << ' ' << v * ok(da, lb, rb).second << '\n';
            return;
        }
    }
    cout << "-1 -1\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}