#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

void read(int& n, vector<int>& a) {
    cin >> n;
    string s;
    cin >> s;
    a.resize(n);
    for (int i = 0; i < n; i++)
        a[i] = s[i] - '0';
}

ll fast(int n, vector<int> a) {
    ll res = 0;
    vector<ll> f(n), g(n), F(n), G(n);
    std::function<void(ll, ll)> rec = [&](ll l, ll r) {
        if (l == r) {
            res += a[l];
            return;
        }
        ll m = (l + r) / 2;
        rec(l, m);
        rec(m + 1, r);
        ll xl = 0, xr = 0;
        while (m - xl >= l && a[m - xl]) xl++;
        while (m + 1 + xr <= r && a[m + 1 + xr]) xr++;

        for (ll mx = 0, cur = 0, i = m; i >= l; i--) {
            if (a[i] == 1) cur++;
            else cur = 0;
            mx = max(mx, cur);
            f[i] = mx;
        }

        for (ll mx = 0, cur = 0, i = m + 1; i <= r; i++) {
            if (a[i] == 1) cur++;
            else cur = 0;
            mx = max(mx, cur);
            g[i] = mx;
        }

        for (int i = r; i > m; i--) {
            G[i] = g[i];
            if (i < r)
                G[i] += G[i + 1];
        }

        ll hlp = 0;
        for (ll cur = m + xr + 1, ql = m; ql >= l; ql--) {
            if (ql > m - xl) {
//                for (int qr = m + 1; qr < m + 1 + xr; qr++) {
//                    res += qr - ql + 1;
//                }
                // [m + 1, m + xr]
                if (m + 1 <= m + xr) {
                    ll C = m + xr - (m + 1) + 1;
                    ll S = (m + 1 + m + xr) * C / 2;
                    res += S - C * (ql - 1);
                }
            } else {
                int y = min(m - l + 1, xl) - m;
//                for (int qr = m + 1; qr < m + 1 + xr; qr++) {
//                    res += max(f[ql], y + qr);
//                }
                ll M = max(m + 1ll, f[ql] - y);
                if (M <= m + xr) { // [M, m + xr]
                    ll C = m + xr - M + 1;
                    ll S = (M + m + xr) * C / 2;
                    res += C * y + S;
                    res += 1ll * (M - m - 1) * f[ql];
                } else {
                    res += 1ll * (m + xr - m) * f[ql];
                }
            }
            ll fl = max(f[ql], min(m - ql + 1, xl) + xr);
            while (cur <= r && g[cur] < fl) cur++;
            if (cur <= r)
                res += G[cur];
            res += (cur - (m + 1 + xr)) * 1ll * fl;
        }
    };
    rec(0, n - 1);
    return res;
}

void work() {
    int n;
    vector<int> a;
    read(n, a);
    cout << fast(n, a) << "\n";
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();

    return 0;
}