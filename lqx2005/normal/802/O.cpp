#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define pr pair<int, int>
using namespace std;
const int N = 500000 + 10;
int n, k, a[N], b[N];
priority_queue<ll, vector<ll>, greater<ll> > hpa, hpb;
pair<ll, ll> check(ll x) {
    while(!hpa.empty()) hpa.pop();
    while(!hpb.empty()) hpb.pop();
    hpa.emplace(1e18), hpb.emplace(1e18);
    ll res = 0, cnt = 0;
    FOR(i, 1, n) {
        hpa.emplace(a[i] - x);
        if(hpa.top() <= hpb.top()) {
            if(hpa.top() + b[i] <= 0) {
                res += hpa.top() + b[i], cnt++;
                hpa.pop();
                hpb.emplace(-b[i]);
            }
        } else {
            if(hpb.top() + b[i] <= 0) {
                res += hpb.top() + b[i];
                hpb.pop();
                hpb.emplace(-b[i]);
            }
        }
    }
    return {res, cnt};
}
int main() {
    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];
    ll l = 0, r = 2e9 + 10, best = -1;
    while(l <= r) {
        ll mid = (l + r) / 2;
        if(check(mid).second >= k) best = mid, r = mid - 1;
        else l = mid + 1;
    }
    pair<ll, ll> ans = check(best);
    ll res = ans.first + k * best;
    cout << res << "\n";
    return 0;
}