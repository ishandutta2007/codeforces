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
        int h, w;
        cin >> h >> w;
        vector<string> s(h);
        rep(i, h) s[i] = string(w, '0');
        s[0][0] = s[h-1][0] = s[0][w-1] = s[h-1][w-1] = '1';
        for(int i = 2; i <= h - 1 - 2; i += 2) s[i][0] = s[i][w-1] = '1';
        for(int j = 2; j <= w - 1 - 2; j += 2) s[0][j] = s[h-1][j] = '1';
        rep(i, h) cout << s[i] << '\n';
        cout << '\n';
    }
}