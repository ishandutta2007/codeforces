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
    int n;
    cin >> n;
    VI A(n);
    rep(i, n) cin >> A[i];
    VI a(n);
    int ans = 0;
    rrep(k, 20) {
        rep(i, n) a[i] = (a[i] << 1) | (A[i] >> k & 1);
        map<int, int> mp{{0, 0}};
        int x = 0;
        rep(i, n) {
            if ((a[i] & 1) == 0) {
                mp.clear();
                x = 0;
                mp[x] = i + 1;
                continue;
            }
            x ^= a[i];
            if (mp.count(x)) chmax(ans, i + 1 - mp[x]);
            else mp[x] = i + 1;
        }
    }
    cout << ans << endl;
}