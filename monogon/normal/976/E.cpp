
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

// is it best to only apply spells of type 1 to one creature only?
// sometimes h > d, so we should be careful
// it might also be best not to apply any spells of type 1
// suppose we only use spells of type 1 on i
// max(2^a h[i], d[i]) + best way to use b spells on remaining creatures
// sort creatures decreasing by h[j] - d[j]
// we apply spells to prefix of length at most b, and only on positive values
// change h value => how does optimal prefix change?
// create prefix sum array
// if we change value of h, find where it belongs in h-d array with binary search
// find prefix sum of default length. Consider expanding by 1

const int N = 2e5 + 5;
int n, a, b;
ll h[N], d[N], hd[N], pref[N], ind[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> a >> b;
    b = min(b, n);
    vector<pii> ve;
    ll sumd = 0;
    rep(i, 1, n + 1) {
        cin >> h[i] >> d[i];
        ve.emplace_back(h[i] - d[i], i);
        sumd += d[i];
    }
    sort(ve.rbegin(), ve.rend());
    rep(i, 1, n + 1) {
        hd[i] = ve[i - 1].fi;
        pref[i] = pref[i - 1] + hd[i];
        ind[ve[i - 1].se] = i;
    }
    int L = min(b, (int) (lower_bound(hd + 1, hd + n + 1, 0, greater<ll>()) - hd - 1));
    // rep(i, 1, n + 1) {
    //     cout << hd[i] << ' ';
    // }
    // cout << "L = " << L << endl;
    ll ans = pref[L];
    rep(i, 1, n + 1) {
        ll hdi = h[i] * (1LL << a) - d[i];
        int j = lower_bound(hd + 1, hd + n + 1, hdi, greater<ll>()) - hd;
        if(hdi > 0 && j <= b) {
            if(L < b) {
                if(ind[i] <= L) {
                    ans = max(ans, pref[L] + hdi - (h[i] - d[i]));
                }else {
                    ans = max(ans, pref[L] + hdi);
                }
            }else if(ind[i] <= b) {
                // cout << "a" << endl;
                ans = max(ans, pref[b] + hdi - (h[i] - d[i]));
            }else {
                // cout << "b" << endl;
                ans = max(ans, pref[b - 1] + hdi);
            }
        }
    }
    cout << sumd + ans << '\n';
}