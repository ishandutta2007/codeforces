#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = (n)-1; i >= 0; --i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
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
        int n;
        cin >> n;
        VI d(2 * n);
        rep(i, n) {
            int b;
            cin >> b;
            d[b-1] = 1;
        }
        int now = 0;
        int mx = 0;
        rep(i, 2 * n) {
            if (d[i] == 1) now++;
            else if (now) now--, mx++;
        }
        now = 0;
        int mn = 0;
        rep(i, 2 * n) {
            if (d[i] == 0) now++;
            else if (now) now--;
            else mn++;
        }
        cout << mx - mn + 1 << '\n';
    }
}