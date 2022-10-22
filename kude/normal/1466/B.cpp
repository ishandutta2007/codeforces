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
        VI hist(2 * n + 10);
        rep(_, n) {
            int x;
            cin >> x;
            hist[x+1]++;
        }
        int ans = 0;
        for(int i = 1; i < 2 * n + 5; i++) {
            if (hist[i-1]) {
                ans++;
                hist[i-1]--;
            } else if (hist[i]) {
                ans++;
                hist[i]--;
            }
        }
        cout << ans << '\n';
    }
}