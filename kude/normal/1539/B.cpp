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

int acc[100100][26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    rep(i, n) {
        rep(j, 26) acc[i + 1][j] = acc[i][j];
        int x = s[i] - 'a';
        acc[i + 1][x] += 1;
    }
    while(q--) {
        int l, r;
        cin >> l >> r;
        l--;
        int ans = 0;
        rep(j, 26) ans += (acc[r][j] - acc[l][j]) * (j + 1);
        cout << ans << '\n';
    }
}