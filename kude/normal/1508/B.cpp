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
        ll k;
        cin >> n >> k;
        k--;
        VI ans;
        for(int i = 1; i <= n;) {
            int j = i;
            while(j < n && n - j - 1 <= 61 && (1LL << n - j - 1) <= k) {
                k -= 1LL << n - j - 1;
                j++;
            }
            for(int t = j; t >= i; t--) ans.push_back(t);
            i = j + 1;
        }
        if (k) cout << -1 << '\n';
        else {
            rep(i, n) cout << ans[i] << " \n"[i + 1 == n];
        }
    }
}