
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
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

// for each suffix of a, how many x's can we tolerate?
// then we take intersection of all intervals
// if non-empty, we found k. Otherwise, no solution

const int N = 5e5 + 5;
int n;
ll a[N], x;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, (n + 1) / 2) cin >> a[i];
    cin >> x;
    ll sum = 0, mn = n / 2 + 1, mx = n;
    vector<pair<ll, ll>> ve;
    for(int i = (n + 1) / 2 - 1; i >= 0; i--) {
        sum += a[i];
        // sum + k x > 0
        // k x > -sum
        // if x > 0: k > -sum / x => k >= floor((-sum + x) / x)
        // if x < 0: k < sum / -x => k <= floor((sum - x - 1) / -x) - 1
        // if x = 0: all suffixes should be positive
        // 0 <= ((n + 1) / 2 - i + 1 + k) <= n / 2
        if(x > 0) {
            if(sum <= 0) {
                mn = max(mn, min((ll) n - i + 1, (-sum + x) / x + (n + 1) / 2 - i));
            }
        }else if(x < 0) {
            if(sum > 0) {
                ll val = (sum - x - 1) / -x - 1 + (n + 1) / 2 - i;
                // >= n - i + 1 OR <= val.
                if(n - i + 1 > val) {
                    // mx = min(mx, val);
                    ve.emplace_back(val + 1, n - i);
                }
            }else {
                mn = max(mn, (ll) n - i + 1);
            }
        }else if(sum <= 0) {
            mn = max(mn, (ll) n - i + 1);
        }
    }
    reverse(all(ve));
    for(auto &p : ve) {
        if(p.first <= mx && mx <= p.second) {
            mx = p.first - 1;
        }
    }
    if(mn <= mx) {
        cout << mx << '\n';
    }else {
        cout << "-1\n";
    }
}