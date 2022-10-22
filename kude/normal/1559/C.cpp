#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < int(n); ++i)
#define rrep(i,n) for(int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
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
        int n;
        cin >> n;
        VI a(n);
        rep(i, n) cin >> a[i];
        VI ans;
        ans.reserve(n + 1);
        if (a[0] == 1) {
            ans.push_back(n);
            rep(i, n) ans.push_back(i);
        } else {
            int p = -1;
            rep(i, n) if (a[i] == 1) {
                p = i;
                break;
            }
            if (p == -1) {
                rep(i, n) ans.push_back(i);
                ans.push_back(n);
            } else {
                rep(i, p) ans.push_back(i);
                ans.push_back(n);
                for(int i = p; i < n; i++) ans.push_back(i);
            }
        }
        rep(i, n + 1) cout << ans[i] + 1 << " \n"[i == n];
    }
}