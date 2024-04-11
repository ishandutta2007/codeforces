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
        int i_mn = -1, mn = 1001001001;
        rep(i, n) if (a[i] < mn) {
            mn = a[i], i_mn = i;
        }
        cout << n - 1 << '\n';
        rep(i, i_mn) {
            cout << i + 1 << ' ' << i_mn + 1 << ' ' << (i % 2 ? 1000000007 : 1000000009) << ' ' << mn << '\n';
        }
        for(int i = i_mn + 1; i < n; i++) {
            cout << i_mn + 1 << ' ' << i + 1 << ' ' << mn << ' ' << (i % 2 ? 1000000007 : 1000000009) << '\n';
        }
    }
}