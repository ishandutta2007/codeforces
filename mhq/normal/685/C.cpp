#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int tst;
const int maxN = (int)1e5 + 10;
ll x[maxN][3];
ll optx, opty, optz;
int n;
ll val[maxN][12];
ll total[12];
ll cur[12];
ll cur2[12];
ll cur3[12];
// getDown(a)
// 2 * t <= a
ll getDown(ll a) {
    ll t = a / 2 + 2;
    while (2 * t > a) t--;
    return t;
}
ll getUp(ll a) {
    ll t = a / 2 - 2;
    while (2 * t < a) t++;
    return t;
}
bool check(ll r) {
    for (int i = 0; i < 8; i++) {
        cur[i] = total[i] - r;
    }
    ll lim_l = cur[7];
    ll lim_r = -cur[0];
    ll lim_xl = cur[6];
    ll lim_xr = -cur[1];
    ll lim_yl = cur[5];
    ll lim_yr = -cur[2];
    ll lim_zl = cur[3];
    ll lim_zr = -cur[4];
    // 2 2 0 -> 1 1 2
  //  cout << lim_l << " " << lim_r << " " << lim_xl << " " << lim_xr << " " << lim_yl << " " << lim_yr << " " << lim_zl << " " << lim_zr << endl;
    //cout << cur[7] << " " << cur[0] << " " << lim_xl << " " << lim_xr << " gg" << endl;
    for (int t = 0; t < 2; t++) {
        ll n_l = getUp(lim_l - 3 * t);
        ll n_r = getDown(lim_r - 3 * t);
        ll n_xl = getUp(lim_xl - t);
        ll n_xr = getDown(lim_xr - t);
        ll n_yl = getUp(lim_yl - t);
        ll n_yr = getDown(lim_yr - t);
        ll n_zl = getUp(lim_zl - t);
        ll n_zr = getDown(lim_zr - t);
        if (n_l > n_r || n_xl > n_xr || n_yl > n_yr || n_zl > n_zr) continue;
        //cout << n_l << " " <<
        optx = n_xl;
        opty = n_yl;
        optz = n_zl;
      //  cout << n_l << " " << n_r << " " << n_xl << " " << n_xr << " " << n_yl << " " << n_yr << " " << n_zl << " " << n_zr << endl;
      //  cout << optx << " " << opty << " " << optz << endl;
        if (optx + opty + optz > n_r) continue;
        if (optx + opty + optz >= n_l) {
            optx = 2 * optx + t;
            opty = 2 * opty + t;
            optz = 2 * optz + t;
            return true;
        }
        ll s = n_l - optx - opty - optz;
        ll d = min(s, n_xr - optx);
        s -= d;
        optx += d;
       // cout << "after first" << optx << " " << opty << " " << optz << endl;
        if (s <= 0) {
            optx = 2 * optx + t;
            opty = 2 * opty + t;
            optz = 2 * optz + t;
       //     cout << optx << " " << opty << " " << optz << endl;
            return true;
        }
        d = min(s, n_yr - opty);
        s -= d;
        opty += d;
        if (s <= 0) {
            optx = 2 * optx + t;
            opty = 2 * opty + t;
            optz = 2 * optz + t;
            return true;
        }
        d = min(s, n_zr - optz);
        s -= d;
        optz += d;
        if (s <= 0) {
            optx = 2 * optx + t;
            opty = 2 * opty + t;
            optz = 2 * optz + t;
            return true;
        }
    }
    return false;
}
void solve() {
    for (int i = 0; i < 8; i++) {
        total[i] = -4 * (ll)1e18;
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> x[i][j];
        }
        for (int mask = 0; mask < 8; mask++) {
            //cout << total[mask] << endl;
            val[i][mask] = 0;
            for (int bit = 0; bit < 3; bit++) {
                if (mask & (1 << bit)) {
                    val[i][mask] += x[i][bit];
                }
                else {
                    val[i][mask] -= x[i][bit];
                }
            }
            total[mask] = max(total[mask], val[i][mask]);
        }
    }
    ll l = 0;
    if (check(l)) {
        cout << (opty + optz) / 2 << " " << (optx + optz) / 2 << " " << (optx + opty) / 2 << '\n';
    }
    else {
        ll r = 3 * (ll)1e18 + 100;
        while (r - l > 1) {
            ll mid = (l + r) / 2;
            if (check(mid)) r = mid;
            else l = mid;
        }
        check(r);
        cout << (opty + optz) / 2 << " " << (optx + optz) / 2 << " " << (optx + opty) / 2 << '\n';
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}