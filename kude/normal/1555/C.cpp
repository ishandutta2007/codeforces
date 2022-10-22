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
        --n;
        VI a1(n), a2(n);
        rep(i, n + 1) {
            int x;
            cin >> x;
            if (i) a1[i - 1] = x;
        }
        rep(i, n + 1) {
            int x;
            cin >> x;
            if (i < n) a2[i] = x;
        }
        VI s1(n + 1), s2(n + 1);
        rrep(i, n) s1[i] = s1[i + 1] + a1[i];
        rep(i, n) s2[i + 1] = s2[i] + a2[i];
        int ans = 1001001001;
        rep(i, n + 1) chmin(ans, max(s1[i], s2[i]));
        cout << ans << '\n';
    }
}