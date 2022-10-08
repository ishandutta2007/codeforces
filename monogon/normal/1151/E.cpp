
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

// new component for every edge a -> b where a outside range [l, r] and b inside range [l, r]
// first component also counted for every range [l, r] containing a[0]

const int N = 1e5 + 5;
int n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
    }
    ll ans = 1LL * a[0] * (n - a[0] + 1);
    rep(i, 1, n) {
        if(a[i - 1] < a[i]) {
            ans += 1LL * (a[i] - a[i - 1]) * (n - a[i] + 1);
        }else if(a[i - 1] > a[i]) {
            ans += 1LL * a[i] * (a[i - 1] - a[i]);
        }
    }
    cout << ans << '\n';
}