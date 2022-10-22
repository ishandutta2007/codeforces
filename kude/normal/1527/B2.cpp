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

int memo[1010][1010][2][2];
bool valid[1010][1010][2][2];
int dfs(int c1, int c2, int c3, int k) {
    if (valid[c1][c2][c3][k]) return memo[c1][c2][c3][k];
    valid[c1][c2][c3][k] = true;
    if (c1 == 0 && c2 == 0 && c3 == 0) return memo[c1][c2][c3][k] = 0;
    int ret = -1001001001;
    if (k == 0 && c1 != 0) chmax(ret, -dfs(c1, c2, c3, 1));
    if (c1) chmax(ret, -1 - dfs(c1 - 1, c2, c3, 0));
    if (c2) chmax(ret, -1 - dfs(c1 + 1, c2 - 1, c3, 0));
    if (c3) chmax(ret, -1 - dfs(c1, c2, 0, 0));
    return memo[c1][c2][c3][k] = ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int x = 0, y = 0, z = 0;
        rep(i, n / 2) {
            if (s[i] == '0') {
                if (s[n - 1 - i] == '0') y++;
                else x++;
            } else if (s[n - 1 - i] == '0') x++;
        }
        if (n % 2 == 1 && s[n / 2] == '0') z++;
        int t = dfs(x, y, z, 0);
        if (t > 0) cout << "ALICE" << '\n';
        else if (t == 0) cout << "DRAW" << '\n';
        else cout << "BOB" << '\n';
    }
}