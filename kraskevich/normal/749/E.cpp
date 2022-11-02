#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct Bit {
    vector<ll> f;

    Bit(int n): f(n) {}

    ll get(int x) {
        ll res = 0;
        for (; x >= 0; x = (x & (x + 1)) - 1)
            res += f[x];
        return res;
    }

    ll get(int l, int r) {
        return get(r) - get(l - 1);
    }

    void upd(int x, ll d) {
        for (; x < f.size(); x = (x | (x + 1)))
            f[x] += d; 
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    double res = 0.0;
    Bit cnt(n + 1);
    Bit lin(n + 1);
    for (int i = 1; i <= n; i++) {
        ll mul = n - i + 1;
        int x;
        cin >> x;
        res += lin.get(1, x) * 1.0 * mul / n / (n + 1);
        res += cnt.get(x, n) - lin.get(x, n) * 1.0 * mul / n / (n + 1);
        cnt.upd(x, 1);
        lin.upd(x, i);      
    }
    cout.setf(ios::fixed);
    cout.precision(20);
    cout << res << endl;
}