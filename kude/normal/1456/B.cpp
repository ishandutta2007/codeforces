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

int msb(int x) {
    int k = 30;
    while((1 << k & x) == 0) k--;
    return k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    VI a(n);
    rep(i, n) cin >> a[i];
    VI d(n);
    rep(i, n) d[i] = msb(a[i]);
    for(int i = n - 1; i >= 0;) {
        int j = i;
        while(j >= 0 && d[j] == d[i]) --j;
        if (i - j >= 3) {
            cout << 1 << endl;
            return 0;
        }
        i = j;
    }
    constexpr int inf = 1001001001;
    int ans = inf;
    for(int i = 0; i < n; ++i) {
        for(int j = i+1; j < n; ++j) {
            for(int k = j + 1; k <= n; ++k) {
                // [i, j), [j, k)
                int x = 0, y = 0;
                for(int t = i; t < j; t++) x ^= a[t];
                for(int t = j; t < k; t++) y ^= a[t];
                if (x > y) chmin(ans, j - i - 1 + k - j - 1);
            }
        }
    }
    if (ans == inf) ans = -1;
    cout << ans << endl;
}