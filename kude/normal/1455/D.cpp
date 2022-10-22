#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = (n)-1; i >= 0; --i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

int solve() {
    int n, x;
    cin >> n >> x;
    VI a(n);
    rep(i, n) cin >> a[i];
    int idx = 0;
    int ans = 0;
    for(int i = 1; i < n; ++i) if (a[i-1] > a[i]) {
        while(idx < n && a[idx] <= x) idx++;
        while(idx <= i - 1) {
            if (x != a[idx]) {
                ans++;
                swap(x, a[idx]);
            }
            idx++;
        }
        if (a[i-1] > a[i]) return -1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) cout << solve() << '\n';
}