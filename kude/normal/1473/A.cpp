#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = (n)-1; i >= 0; --i)
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
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
        int n, d;
        cin >> n >> d;
        VI a(n);
        rep(i, n) cin >> a[i];
        bool ok = true;
        rep(i, n) if (a[i] > d) {
            ok = false;
            break;
        }
        if (!ok) {
            sort(all(a));
            int t = a[0] + a[1];
            ok = t <= d;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}