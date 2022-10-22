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
        int n, k;
        cin >> n >> k;
        VI h(n);
        rep(i, n) cin >> h[i];
        while(k) {
            k--;
            int i = 0;
            for(; i < n - 1; ++i) {
                if (h[i] >= h[i+1]) continue;
                h[i] += 1;
                break;
            }
            if (i == n - 1) {
                cout << -1 << '\n';
                break;
            }
            if (k == 0) {
                cout << i + 1 << '\n';
            }
        }
    }
}