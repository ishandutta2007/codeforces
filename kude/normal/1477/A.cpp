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
        VL a(n);
        rep(i, n) cin >> a[i];
        if (n == 1) {
            cout << (a[0] == k ? "YES\n" : "NO\n");
            continue;
        }
        ll g = 0;
        for(int i = 1; i < n; ++i) {
            g = gcd(g, a[i] - a[0]);
        }
        if ((a[0] - k) % g == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}