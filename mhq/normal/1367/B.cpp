#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;

struct Fenwick {
    vector<ll> f;
    int n;

    Fenwick(int _n) {
        n = _n;
        f.resize(_n + 1);
    }

    void upd(int pos, int v) {
        while (pos <= n) {
            f[pos] += v;
            pos = (pos | (pos - 1)) + 1;
        }
    }

    ll get(int r) {
        ll ans = 0;
        while (r > 0) {
            ans += f[r];
            r &= (r - 1);
        }
        return ans;
    }

    ll get(int l, int r) {
        return get(r) - get(l - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int cnt[2][2] = {{0, 0}, {0, 0}};
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x % 2 != i % 2) {
                cnt[i % 2][x % 2]++;
            }
        }
        if (cnt[0][1] != cnt[1][0]) {
            cout << -1 << '\n';
        }
        else {
            cout << cnt[0][1] << '\n';
        }
    }
    return 0;
}