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
        int d[3];
        rep(i, 3) cin >> d[i];
        sort(d, d + 3);
        int m;
        cin >> m;
        int mn = max(0, d[2] - d[1] - d[0] - 1);
        int mx = 0;
        rep(i, 3) mx += d[i] - 1;
        cout << (mn <= m && m <= mx ? "YES\n" : "NO\n");
    }
}