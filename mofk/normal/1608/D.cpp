#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;
int n;
int bb, ww, wb, bw, ff, b, w, bf, fb, wf, fw;
int ft[200005], in[200005];

int pw(int a, int b) {
    int r = 1;
    while (b) {
        if (b & 1) r = 1ll * r * a % mod;
        a = 1ll * a * a % mod;
        b >>= 1;
    }
    return r;
}
int inv(int x) { return pw(x, mod - 2); }

int comb(int n, int k) {
    if (k < 0 || k > n) return 0;
    return 1ll * ft[n] * in[k] % mod * in[n - k] % mod;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (s == "BB") ++bb;
        else if (s == "WW") ++ww;
        else if (s == "WB") ++wb;
        else if (s == "BW") ++bw;
        else if (s == "??") ++ff;
        else if (s == "B?") ++bf;
        else if (s == "?B") ++fb;
        else if (s == "W?") ++wf;
        else if (s == "?W") ++fw;
    }
    b = fb + bf; w = fw + wf;
    ft[0] = in[0] = 1;
    for (int i = 1; i <= 2 * n; ++i) ft[i] = 1ll * ft[i-1] * i % mod, in[i] = inv(ft[i]);
    int ans = 0;
    for (int i = -ff; i <= ff; ++i) {
        int way_ff = comb(2 * ff, ff + i);
        int dif = bb - ww + i;
        int way_bw = comb(b + w, b + dif);
        ans = (ans + 1ll * way_bw * way_ff) % mod;
    }
    if (bb + ww == 0) {
        ans = (ans + mod - pw(2, ff)) % mod;
        if (!wb && !fb && !wf) ans = (ans + 1) % mod;
        if (!bw && !fw && !bf) ans = (ans + 1) % mod;
    }

    cout << ans << endl;
    return 0;
}