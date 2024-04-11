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
        int n, x;
        cin >> n >> x;
        VI w(n);
        rep(i, n) cin >> w[i];
        int now = 0;
        bool ok = true;
        rep(i, n) {
            if (now + w[i] == x) {
                if (i == n - 1) {
                    ok = false;
                    break;
                }
                swap(w[i], w[i + 1]);
            }
            now += w[i];
        }
        if (!ok) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            rep(i, n) cout << w[i] << " \n"[i + 1 == n];
        }
    }
}