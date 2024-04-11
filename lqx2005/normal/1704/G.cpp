#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define ll long long
#define ull unsigned long long
#define db double
#define x first
#define y second
#define vi vector<int>
#define lll __int128
using namespace std;
int n, m, cnt[400010];
ll a[200010], b[200010], c[200010], difa[200010], rema[200010], reaa[200010], remb[200010], vis[200010];
bitset<200010> val, S;
ll calc(ll a, ll b, ll c, ll x) {
    return a * x * x + b * x + c;
}
void valid(ll &al, ll &ar, ll a, ll b, ll c) {
    if(al > ar) return;
    ll l = al, r = ar - 1, best = ar;
    while(l <= r) {
        ll mid = (l + r) / 2;
        if(calc(a, b, c, mid) < calc(a, b, c, mid + 1)) {
            best = mid, r = mid - 1;
        } else l = mid + 1;
    }
    if(calc(a, b, c, best) > 0) {
        al = 1e18, ar = -1e18;
        return;
    }
    ll x = best;
    l = al, r = x, best = x;
    while(l <= r) {
        ll mid = (l + r) / 2;
        if(calc(a, b, c, mid) <= 0) best = mid, r = mid - 1;
        else l = mid + 1;
    }
    al = best;
    l = x, r = ar, best = x;
    while(l <= r) {
        ll mid = (l + r) / 2;
        if(calc(a, b, c, mid) <= 0) best = mid, l = mid + 1;
        else r = mid - 1;
    }
    ar = best;
}
ll arr[400010];
int atot = 0;
vector<int> pos[400010], qry[400010];
int check() {
    FOR(i, 1, n) if(vis[i]) {
        int cnt = 0, opt = -1;
        FOR(j, i, n) {
            cnt++, opt = -opt;
            reaa[j] += cnt * opt;
        }
    }
    FOR(i, 1, n - m + 1) {
        int flag = 1;
        FOR(j, 0, m - 1) if(remb[j + 1] != reaa[j + i]) flag = 0;
        if(flag) return 1;
    }
    return 0;
}
void solve() {
    FOR(i, 1, atot) pos[i].clear(), qry[i].clear();
    atot = 0;
    cin >> n;
    // cout << "????" << endl;
    FOR(i, 1, n) c[i] = (i & 1) ? 1 : -1;
    FOR(i, 1, n) {
        vis[i] = 0;
        cin >> a[i], reaa[i] = a[i];
        if((i - 1) & 1) a[i] = -a[i];
    }
    cin >> m;
    FOR(i, 1, m) {
        cin >> b[i];
        remb[i] = b[i];
        if((i - 1) & 1) b[i] = -b[i];
    }
    FOR(i, 1, n) rema[i] = a[i];
    ROF(i, n, 1) a[i] -= a[i - 1];
    FOR(i, 1, n) difa[i] = a[i];
    ROF(i, n, 1) a[i] -= a[i - 1];
    ROF(i, m, 2) b[i] -= b[i - 1];
    ROF(i, m, 3) b[i] -= b[i - 1];
    FOR(i, 1, n) if((i - 1) & 1) a[i] = -a[i];
    FOR(i, 1, n) arr[++atot] = a[i], arr[++atot] = a[i] + 1;
    sort(arr + 1, arr + atot + 1);
    atot = unique(arr + 1, arr + atot + 1) - (arr + 1);
    FOR(i, 1, n) {
        ll x = a[i] + 1;
        int p = lower_bound(arr + 1, arr + atot + 1, x) - arr;
        qry[p].emplace_back(i);
    }
    FOR(i, 1, n) if((i - 1) & 1) a[i] = -a[i];
    FOR(i, 1, m) if((i - 1) & 1) b[i] = -b[i];
    FOR(i, 1, atot) pos[i].clear();
    val.reset();
    FOR(i, 3, m) {
        int p = lower_bound(arr + 1, arr + atot + 1, b[i]) - arr;
        if(p <= atot && arr[p] == b[i]) pos[p].emplace_back(i);
    }
    S.reset();
    FOR(j, 3, m) S[n + 1 - j] = 1;
    FOR(i, 1, atot) {
        // FOR(j, 1, n)  cout << val[j] << " ";
        // cout << "\n";
        if(i > 1 && arr[i] == arr[i - 1] + 1) {
            for(auto x : pos[i]) if(3 <= x) S[n + 1 - x] = 0;
            for(auto x : pos[i - 1]) if(3 <= x) S[n + 1 - x] = 0;
            for(auto x : qry[i]) {
                // x -> y
                // x - y + 1  -> 1
                val |= (S >> (n - x));
            }
            for(auto x : pos[i]) if(3 <= x) S[n + 1 - x] = 1;
            for(auto x : pos[i - 1]) if(3 <= x) S[n + 1 - x] = 1;
        }
    }
    FOR(i, 1, m) if((i - 1) & 1) b[i] = -b[i];
    FOR(par, 0, 1) {
        // cout << "\n";
        for(int p = par + 1; p <= n - m + 1; p += 2) {
            // int flag = 1;
            // FOR(j, 2, m - 1) {
            //     if(!(b[j + 1] == a[p + j] || b[j + 1] == a[p + j] + c[p + j])) {
            //         flag = 0;
            //         break;
            //     }
            // }
            if(val[p]) continue;
            ll d2 = b[2] - difa[p + 1], d1 = b[1] - rema[p];
            if(par) d2 = -d2, d1 = -d1;
            // cout << "d2 " << d2 << " ";
            // cout << "d1 " << d1 << " ";
            ll odd = (p + 1) / 2, even = p + 1 - odd;
            ll sume = (ll)even * (even - 1);
            ll sumo = (ll)odd * odd;
            ll l = max(-d2, 0ll), r = min(even, odd - d2);
            if(l > r) continue;
            // cout << l <<" " << r << endl;
            // sume + (even - x) * (even - x - 1) + (x + d2) * (x + d2)
            // -sume + (even - x) * (even - x - 1) + (x + d2) * (x + d2) + d1 <= 0
            // x * (x - 1) - sumo + (-odd + x + d2) * (-odd + x + d2) - d1 <= 0
            ll a1 = 2, b1 = - even * 2 + 1 + d2 * 2, c1 = d2 * d2 - d1;
            ll a2 = 2, b2 = -1 + (d2 - odd) * 2, c2 = d2 * d2 - odd * d2 * 2 + d1;
            valid(l, r, a1, b1, c1);
            valid(l, r, a2, b2, c2);
            if(l > r) continue;
            if(calc(a1, b1, c1, l) & 1) l++;
            if(calc(-a2, -b2, -c2, r) & 1) r--;
            if(l > r) continue;
            FOR(j, 2, m - 1) if(b[j + 1] == a[p + j] + c[p + j]) vis[p + j] = 1;
            ll d = calc(a1, b1, c1, l);
            even = l, odd = even + d2;
            vector<int> po, pe;
            FOR(k, 1, p + 1) if((p + 1 - k) & 1) po.emplace_back(k); else pe.emplace_back(k);
            d = -d;
            // assert(d % 2 == 0);
            ROF(i, even - 1, 0) {
                if(d >= (sz(pe) - 1 - i) * 2) {
                    d -= (sz(pe) - 1 - i) * 2;
                    vis[pe.back()] = 1;
                    pe.pop_back();
                } else {
                    vis[pe[i + d / 2]] = 1;
                    d = 0;
                }
            }
            reverse(po.begin(), po.end());
            ROF(i, odd - 1, 0) {
                if(d >= (sz(po) - 1 - i) * 2) {
                    d -= (sz(po) - 1 - i) * 2;
                    vis[po.back()] = 1;
                    po.pop_back();
                } else {
                    vis[po[i + d / 2]] = 1;
                    d = 0;
                }
            }
            int cnt = 0;
            FOR(k, 1, n) cnt += vis[k];
            cout << cnt << "\n";
            FOR(k, 1, n) if(vis[k]) cout << k <<" ";
            cout << "\n";
            return;
        }
        FOR(i, 1, m) b[i] = -b[i];
    }
    // assert(0);
    cout << "-1\n";
    return;
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    for(cin >> t; t--; ) solve();
    return 0;
}