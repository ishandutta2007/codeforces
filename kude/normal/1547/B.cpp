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

bool solve() {
    string s;
    cin >> s;
    int l = -1, r = -1;
    const int n = s.size();
    rep(i, n) if (s[i] == 'a') {
        l = i, r = i + 1;
        break;
    }
    if (l == -1) return false;
    for(char c = 'b'; c < 'a' + n; c++) {
        if (l && s[l-1] == c) l--;
        else if (r < n && s[r] == c) r++;
        else return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }
}