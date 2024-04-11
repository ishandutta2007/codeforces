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

string s[510];
int rightmost[501][501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        int n, m;
        cin >> n >> m;
        rep(i, n) cin >> s[i];
        rep(i, n) {
            int now = m;
            rrep(j, m) {
                if (s[i][j] == '.') {
                    now = j;
                } else {
                    rightmost[i][j] = now;
                }
            }
        }
        int ans = 0;
        rep(i, n) rep(j, m) {
            for(int x = i; x < n; x++) {
                int left = j - (x - i);
                int right = left + 1 + (x - i) * 2;
                if (s[x][left] == '*' && right <= rightmost[x][left]) {
                    ans++;
                } else break;
            }
        }
        cout << ans << '\n';
    }
}