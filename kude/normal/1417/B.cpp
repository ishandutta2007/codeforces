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
        int n, t;
        cin >> n >> t;
        VI a(n);
        rep(i, n) cin >> a[i];
        set<int> s;
        VI ans(n);
        int cnt = 0;
        rep(i, n) {
            if (a[i] * 2 == t) {
                if (cnt) {
                    ans[i] = 0;
                } else {
                    ans[i] = 1;
                }
                cnt ^= 1;
            } else if (s.count(t - a[i])) {
                ans[i] = 1;
            } else {
                ans[i] = 0;
                s.insert(a[i]);
            }
        }

        rep(i, n) cout << ans[i] << " \n"[i == n-1];
    }
}