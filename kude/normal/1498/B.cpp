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

int hist[20];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        int n, w;
        cin >> n >> w;
        rep(i, 20) hist[i] = 0;
        rep(_, n) {
            int x;
            cin >> x;
            hist[__builtin_ctz(x)]++;
        }
        int rest = n;
        int h = 0;
        while(rest) {
            h++;
            int now = w;
            rrep(k, 20) {
                int wk = 1 << k;
                int t = min(hist[k], now / wk);
                hist[k] -= t;
                rest -= t;
                now -= t * wk;
            }
        }
        cout << h << '\n';
    }
}