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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        ll n;
        cin >> n;
        VL ans;
        for(ll p = 2; p * p <= n; p++) {
            int cnt = 0;
            while(n % p == 0) {
                cnt++;
                n /= p;
            }
            rep(i, cnt) {
                if (i < ans.size()) ans[i] *= p;
                else ans.push_back(p);
            }
        }
        if (n != 1) {
            if (ans.size() == 0) ans.push_back(n);
            else ans[0] *= n;
        }
        cout << ans.size() << '\n';
        rrep(i, ans.size()) cout << ans[i] << " \n"[i == 0];
    }
}