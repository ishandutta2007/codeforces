
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 1e6 + 5;
int n;
ll r1, r2, r3, d;
ll cost1[N], cost2[N], dp1[N], dp2[N];
ll a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> r1 >> r2 >> r3 >> d;
    rep(i, 1, n + 1) {
        cin >> a[i];
        // pistol/AWP all 1's + AWP boss
        ll c1 = min(r1, r3) * a[i] + r3;
        // pistol/AWP all 1's + pistol boss twice (requires return)
        ll c2 = min(r1, r3) * a[i] + 2 * r1;
        // laser everyone + pistol/awp boss (requires return)
        ll c3 = r2 + min(r1, r3);
        // cost1 = returning is free
        cost1[i] = min({c1, c2, c3});
        // cost2 = returning costs 2d
        cost2[i] = min({c1, 2 * d + c2, 2 * d + c3});
        // if(i > 1) {
        //     cost2[i] = min(cost2[i], cost1[i - 1] + min(c2, c3) + 2 * d);
        // }
    }
    rep(i, 1, n + 1) {
        // cost2[i] = min(cost2[i] + cost2[i - 1], );
        // cost1[i] += cost1[i - 1];
        // cost2[i] += cost2[i - 1];
        dp2[i] = cost2[i] + dp2[i - 1];
        if(i > 1) {
            ll c2 = min(r1, r3) * a[i] + 2 * r1;
            // laser everyone + pistol/awp boss (requires return)
            ll c3 = r2 + min(r1, r3);
            dp2[i] = min(dp2[i], dp2[i - 2] + cost1[i - 1] + min(c2, c3) + 2 * d);
        }
        dp1[i] = cost1[i] + dp1[i - 1];
    }
    ll ans = d * (n - 1) + dp2[n];
    // ll ans = LLONG_MAX;
    rep(k, 1, n + 1) {
        ans = min(ans, d * (n - 1) + d * (k - 1) + cost2[n] + dp2[n - k] + dp1[n - 1] - dp1[n - k]);
    }
    cout << ans << '\n';
}