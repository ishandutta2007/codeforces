#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define ll long long
#define db double
#define x first
#define y second
#define pi pair<ll, int>
#define vi vector<int>
using namespace std;
const int N = 2e5 + 10;
int n, m;
int tot = 0;
ll crd[N * 3], x[N], p[N], sumk[N * 3], sumb[N * 3];
int curtot = 0;
void solve() {
    cin >> n >> m;
    tot = curtot = 0;
    FOR(i, 1, n) {
        cin >> x[i] >> p[i];
        crd[++tot] = x[i] - p[i], crd[++tot] = x[i], crd[++tot] = x[i] + p[i];
    }
    sort(crd + 1, crd + tot + 1);
    tot = unique(crd + 1, crd + tot + 1) - (crd + 1);
    FOR(i, 1, tot) sumk[i] = sumb[i] = 0;
    FOR(i, 1, n) {
        int l = lower_bound(crd + 1, crd + tot + 1, x[i] - p[i]) - crd;
        int mid = lower_bound(crd + 1, crd + tot + 1, x[i]) - crd;
        int r = lower_bound(crd + 1, crd + tot + 1, x[i] + p[i]) - crd;
        sumk[l] += 1, sumk[mid] -= 1;
        sumb[l] += -crd[l], sumb[mid] += crd[l];
        sumk[mid] -= 1, sumk[r] += 1;
        sumb[mid] += p[i] + crd[mid];
        sumb[r] -= p[i] + crd[mid];
    }
    ll smx = -1e18, dmx = -1e18;
    FOR(i, 1, tot) {
        sumk[i] += sumk[i - 1], sumb[i] += sumb[i - 1];
        ll v = sumk[i] * crd[i] + sumb[i];
        // cout << crd[i] << " " << v << endl;
        if(v > m) {
            ll d = v - m;
            smx = max(smx, crd[i] + d);
            dmx = max(dmx, d - crd[i]);
        }
    }
    FOR(i, 1, n) {
        if(x[i] + p[i] >= smx && p[i] - x[i] >= dmx) {
            cout << 1;
        } else {
            cout << 0;
        }
    }
    cout << "\n";
    return;
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    for(cin >> t; t--; ) solve();
    return 0;
}