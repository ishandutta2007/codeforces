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
        int n, m;
        cin >> n >> m;
        VI row(n, -1);
        int ans = 0;
        rep(_, m) {
            int x, y;
            cin >> x >> y;
            --x, --y;
            row[x] = y;
            ans += x != y;
        }
        VI visited(n, false);
        rep(i, n) if (!visited[i] && row[i] != i) {
            bool ok = true;
            visited[i] = true;
            for(int j = row[i]; j != i; j = row[j]) {
                if (j == -1) {
                    ok = false;
                    break;
                }
                visited[j] = true;
            }
            ans += ok;
        }
        cout << ans << '\n';
    }
}