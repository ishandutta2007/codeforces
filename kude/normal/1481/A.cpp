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
        int x, y;
        cin >> x >> y;
        string s;
        cin >> s;
        int u = 0, d = 0, r = 0, l = 0;
        for(char c: s) {
            if (c == 'U') u++;
            else if (c == 'D') d++;
            else if (c == 'R') r++;
            else l++;
        }
        bool ok = -l <= x && x <= r && -d <= y && y <= u;
        cout << (ok ? "YES\n" : "NO\n");
    }
}