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
        int hist[26] = {};
        string s;
        cin >> s;
        for(char c: s) hist[c - 'a']++;
        int c1 = 0, c2 = 0;
        rep(i, 26) {
            if (hist[i] == 1) c1++;
            else if (hist[i] >= 2) c2++;
        }
        int ans = c2 + c1 / 2;
        cout << ans << '\n';
    }
}