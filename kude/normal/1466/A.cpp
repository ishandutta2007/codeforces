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
        bool e[52] = {};
        rep(_, n) {
            int x;
            cin >> x;
            --x;
            e[x] = true;
        }
        int ans = 0;
        for(int i = 1; i < 52; ++i) {
            for(int j = 0; j + i < 52; ++j) {
                if (e[j] && e[j+i]) {
                    ans++;
                    break;
                }
            }
        }
        cout << ans <<'\n';
    }
}