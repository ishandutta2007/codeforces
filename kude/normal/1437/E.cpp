#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for (int i = (n)-1; i >= 0; --i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;

const int inf = 1001001001;

int LNDS(std::vector<int>& x) {
    int n = x.size();
    vector<int> d;
    d.reserve(n);
    for(int xi: x) {
        auto it = upper_bound(d.begin(), d.end(), xi);
        if (it == d.end()) d.push_back(xi);
        else *it = xi;
    }
    return d.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    VI a(n+2), b(k+2);
    a[0] = -inf, a[n + 1] = inf;
    b[0] = 0, b[k + 1] = n + 1;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] -= i;
    }
    int pre = 0;
    for(int i = 1; i <= k; i++) {
        int bi;
        cin >> bi;
        b[i] = bi;
        if (a[pre] > a[bi]) {
            cout << -1 << endl;
            return 0;
        }
        pre = bi;
    }
    int ans = 0;
    rep(i, k+1) {
        int s = b[i], t = b[i+1];
        // LIS
        VI x;
        for(int i = s + 1; i < t; i++) if (a[s] <= a[i] && a[i] <= a[t]) x.push_back(a[i]);
        ans += t - s - 1 - LNDS(x);
    }
    cout << ans << endl;
}