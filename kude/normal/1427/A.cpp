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
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        VI a(n);
        rep(i, n) cin >> a[i];
        VI neg, pos;
        int zero = 0;
        int ps = 0, ns = 0;
        rep(i, n) {
            if (a[i] < 0) {
                neg.push_back(a[i]);
                ns += a[i];
            } else if (a[i] > 0) {
                pos.push_back(a[i]);
                ps += a[i];
            }
            else zero++;
        }
        if (ps + ns == 0) {
            cout << "NO" << endl;
        } else {
            VI ans;
            if (ps + ns > 0) {
                for(int x: pos) ans.push_back(x);
                for(int x: neg) ans.push_back(x);
            } else {
                for(int x: neg) ans.push_back(x);
                for(int x: pos) ans.push_back(x);
            }
            rep(i, zero) ans.push_back(0);
            cout << "YES" << endl;
            rep(i, n) cout << ans[i] << " \n"[i == n-1];
        }
    }
}