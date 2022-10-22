#include<bits/stdc++.h>
using namespace std;
#define rep(i,n)for (int i = 0; i < int(n); ++i)
#define rrep(i,n)for (int i = int(n)-1; i >= 0; --i)
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
using BS = bitset<512>;

BS dp[512];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    dp[0][0] = true;
    VI todo;
    rep(_, n) {
        int a;
        cin >> a;
        rep(x, 512) {
            if ((dp[x] << (512 - (a + 1))).any()) {
                dp[x ^ a].set(a + 1);
            }
        }
    }
    VI ans;
    rep(x, 512) {
        if (dp[x].any()) ans.push_back(x);
    }
    int sz = ans.size();
    cout << sz << '\n';
    rep(i, sz) cout << ans[i] << " \n"[i + 1 == sz];
}