#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
int n;
int64_t b[nax];
int64_t a[nax];

void solve() {
    cin >> n;

    for (int i = 0 ; i < n ; ++ i)
        cin >> b[i];
    int64_t c = b[0];
    for (int i = 0 ; i < n ; ++ i) {
        int nxt = (i + 1) % n;
        a[nxt] = b[nxt] - b[i];
    }
    if (accumulate(a, a + n, 0LL) != 0) {
        cout << "NO\n";
        return;
    }
    for (int i = 0 ; i < n ; ++ i) {
        int nxt = (i + 1) % n;
        b[i] = a[nxt] - a[i];
        if (b[i] % n) return cout << "NO\n", void();
        b[i] /= n;
    }
    int64_t s = 0;
    int64_t coeff = 1;
    for (int i = 1 ; i < n ; ++ i) {
        s += b[i - 1];
        int m = n - i + 1;
        coeff += m;
        c += m * s;
       /// number in the form x - s
        /**
        */
    }
    if (c % coeff || c <= 0) {
        cout << "NO\n";
        return;
    }
    int64_t ans = c / coeff;
    s = 0;
    vector <int64_t> res;
    res.push_back(ans);
    for (int i = 1 ; i < n ; ++ i) {
        s += b[i - 1];
        res.push_back(ans - s);
        if (res.back() <= 0) return cout << "NO\n", void();
    }
    cout << "YES\n";
    for (int64_t i : res)
        cout << i << ' ';
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ;) {
        solve();
    }
}