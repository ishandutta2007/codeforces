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
int a[N], b[N], sa, sb;
int la[N], lb[N], pos[N];
ll sumb[N], cnt[N];
int check(int x) {
    if(a[sa] + b[sb] <= x) return 1;
    // FOR(i, 1, n) {
    //     FOR(j, 1, m) cout << (a[i] + b[j] > x);
    //     cout << endl;
    // }
    int lst = m;
    FOR(i, 1, n) {
        while(lst >= 1 && b[lst] + a[i] > x) lst--;
        la[i] = lst;
    }
    lst = n;
    FOR(i, 1, m) {
        while(lst >= 1 && a[lst] + b[i] > x) lst--;
        lb[i] = lst;
    }
    // FOR(i, 1, n) cout << la[i] << " ";
    // cout << endl;
    // FOR(i, 1, m) cout << lb[i] << " ";
    // cout << endl;
    int pa = sa, pb = sb;
    FOR(i, 1, m) sumb[i] = sumb[i - 1] + lb[i];
    FOR(i, 1, n) {
        // x + i - n
        // x < n - i
        int p = lower_bound(lb + 1, lb + m + 1, n - i, [&](int x, int y) { return x >= y; }) - lb;
        p--;
        pos[i] = p;
        ll now = (ll)p * (i - n) + sumb[p];
        p = lower_bound(lb + 1, lb + m + 1, i, [&](int x, int y) { return x >= y; }) - lb;
        now -= (ll)(m - p + 1) * i - (sumb[m] - sumb[p - 1]);
        cnt[i] = now;
    }
    ll mx = 0;
    FOR(i, 1, n) mx = max(mx, cnt[i]);
    FOR(i, 1, n) if(mx == cnt[i]) {
        if(pa <= i || pb <= pos[i]) {
            return 1;
        }
    }
    return 0;
}
int main() {
    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, m) cin >> b[i];
    sa = a[1], sb = b[1];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    FOR(i, 1, n) if(a[i] == sa) {
        sa = i;
        break;
    }
    FOR(i, 1, m) if(b[i] == sb) {
        sb = i;
        break;
    }
    // cout << check(4) << endl;
    int l = 0, r = 1e9, best = r;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(mid)) best = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << best << endl;
    return 0;
}