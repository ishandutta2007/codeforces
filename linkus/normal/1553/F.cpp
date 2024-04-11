// chrono::system_clock::now().time_since_epoch().count()
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<int N> struct Fenw {
    ll t[N + 1];

    Fenw() {
        fill(t + 1, t + N + 1, 0ll);
    }

    void update(int p, ll x) {
        for (; p <= N; p |= (p + 1)) {
            t[p] += x;
        }
    }

    ll get(int p) {
        ll ret = 0;

        for (; p > 0; --p) {
            ret += t[p];
            p &= (p + 1);
        }

        return ret;
    }

    ll get(int l, int r) {
        return get(r) - get(l - 1);
    }
};

const int M = (int)3e5;

void solve() {
    int n;
    cin >> n;
    Fenw<M> A, B;
    ll pref = 0, ans = 0;

    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        ans += x * (i - 1ll);
        ans += A.get(x);
        ans += pref;
        pref += x;
        
        for (int j = x; j <= M; j += x) {
            int l = j, r = min(M, j + x - 1);
            ans -= B.get(l, r) * j;
            A.update(l, -x);
        }

        B.update(x, 1);
        cout << ans << " \n"[i == n];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;

    for (int i = 1; i <= tt; ++i) {
        solve();
    }

    return 0;
}