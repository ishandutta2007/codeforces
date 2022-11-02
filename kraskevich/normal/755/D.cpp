#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


struct Bit {
    vector<ll> f;

    Bit(int n): f(n) {}

    ll get(int i) const {
        ll res = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1)
            res += f[i];
        return res;
    }

    ll get(int l, int r) const {
        return get(r) - get(l - 1);    
    }

    void upd(int i, int d) {
        for (; i < f.size(); i = (i | (i + 1)))
            f[i] += d;    
    }
};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    k = min(k, n - k);
    Bit t(2 * n);
    ll res = 1;
    int x = 0;
    for (int i = 0; i < n; i++) {
        int y = (x + k) % n;
        res += 1 + t.get(x + 1, x + k - 1);
        cout << res << " ";
        if (y == 0)
            break;
        t.upd(y, 1);
        t.upd(y + n, 1);
        t.upd(x, 1);
        t.upd(x + n, 1);
        x = y;
    }
    cout << endl;
}