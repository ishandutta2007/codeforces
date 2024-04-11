#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 5 * (int)1e5 + 10;
ll sum[maxN];
ll pref[maxN];
int d[maxN];
int n;
ll sum_big[maxN];
ll sum_small[maxN];
ll f[maxN];
ll g[maxN];
int main() {
    srand(239);
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    sort(d + 1, d + n + 1);
    reverse(d + 1, d + n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + d[i];
    }
    for (int i = 1; i <= n; i++) {
        sum_big[i] = pref[i - 1];
    }
    for (int i = 2; i <= n; i++) {
        if (d[i] >= (i - 1)) {
            f[1]++;
            f[i]--;
        }
        else {
            f[1]++;
            f[d[i] + 1]--;
            g[d[i] + 1] += d[i];
            g[i] -= d[i];
        }
    }
    ll cur_sumf = 0;
    ll cur_sumg = 0;
    for (int i = 1; i <= n; i++) {
        cur_sumf += f[i];
        sum_small[i] += cur_sumf * i;
        cur_sumg += g[i];
        sum_small[i] += cur_sumg;
    }
    ll l = 0;
    ll r = n;
    for (int i = 1; i <= n; i++) {
        //cout << sum_big[i] << " " << sum_small[i] << '\n';
        ll coef1 = sum_big[i];
        coef1 -= 1LL * i * (i - 1);
        coef1 -= min(d[i], i);
        coef1 -= sum_small[i];
        //cout << coef1 << endl;
        r = min(r, -coef1);
        ll coef2 = sum_big[i];
        coef2 += d[i];
        coef2 -= 1LL * i * (i - 1);
        coef2 -= sum_small[i];
        if (i < coef2) {
            l = max(l, (ll)d[i]);
        }
        else {
            l = max(l, coef2);
        }
    }
    int need = (2 - pref[n] % 2) % 2;
    while (need % 2 != l % 2) l++;
    while (need % 2 != r % 2) r--;
    vector < int > ans;
    for (int j = l; j <= r; j += 2) ans.push_back(j);
    if (ans.empty()) {
        cout << -1;
        return 0;
    }
    for (int v : ans) cout << v << " ";
    return 0;

}