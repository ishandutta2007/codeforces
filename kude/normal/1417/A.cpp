#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;
        VI a(n);
        rep(i, n) cin >> a[i];
        sort(all(a));
        int mn = a[0];
        int ans = 0;
        for(int i = 1; i < n; i++) {
            int r = k - a[i];
            ans += r / mn;
        }
        cout << ans << '\n';
    }
}