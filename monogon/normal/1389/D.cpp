
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        int n;
        ll k, l1, r1, l2, r2;
        cin >> n >> k >> l1 >> r1 >> l2 >> r2;
        ll ans = LLONG_MAX;
        ll init = 1LL * n * max(0LL, min(r1, r2) - max(l1, l2));
        if(init >= k) {
            cout << "0\n";
            continue;
        }
        k -= init;
        rep(i, 1, n + 1) {
            ll step = 0;
            // if not overlapping
            ll L1 = l1, R1 = r1, L2 = l2, R2 = r2;
            if(r1 < l2) {
                step += 1LL * i * (l2 - r1);
                R1 = l2;
            }else if(r2 < l1) {
                step += 1LL * i * (l1 - r2);
                R2 = l1;
            }
            // +1 per step from now on, until all segments coincide
            ll mx = max(R1, R2) - min(R1, R2) + max(L1, L2) - min(L1, L2);
            step += min(k, 1LL * i * mx);
            // +1 per two steps from now on
            step += 2 * max(0LL, k - 1LL * i * mx);
            ans = min(ans, step);
        }
        cout << ans << '\n';
    }
}