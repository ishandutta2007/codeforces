#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;

const int MAXN = 100001;

ll t[MAXN];
ll n, m, d, a;

const ll INF = 1ll << 61;

int main() {
#ifdef PAUNSVOKNO
    freopen("in", "r", stdin); cout.tie(nullptr);
    cout.setf(ios::fixed); cout.precision(20); ios_base::sync_with_stdio(false);
#endif

    cin >> n >> m >> a >> d;
    ll cur_e = 1;
    for (int i = 0; i < m; i++) {
        cin >> t[i];
    }

    sort(t, t + m);
    t[m] = INF;

    ll cur_c = 0;
    ll ans = 0;

    while (cur_e <= n || cur_c < m) {
        ll et = (cur_e <= n) ? cur_e * a : INF;
        ll ct = min(et, t[cur_c]);
        ll dt = ct + d;

        ll new_c = static_cast<ll>(upper_bound(t, t + m, dt) - t);
        ll new_e = min(ll(n + 1), (dt / a) + 1);

        ans++;

        if (new_c == cur_c) {
            ll df = (new_e - cur_e);
            ll mv = (t[cur_c] / a);
            ll cnt = max(0ll, min(mv, n + 1) - new_e - df) / df;
            ans += cnt;
            new_e += df * cnt;
        }

        cur_c = new_c;
        cur_e = new_e;
    }

    cout << ans << "\n";
}