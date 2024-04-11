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
    int u, v;
    cin >> u >> v;
    if (u == v) return true;
    if (u > v) return false;
    int diff = __builtin_popcount(u) - __builtin_popcount(v);
    if (diff < 0) return false;
    int j = 0;
    rep(i, 30) if (v >> i & 1) {
        while(!(u >> j & 1)) j++;
        if (j > i) return false;
        j++;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) cout << (solve() ? "YES\n" : "NO\n");
}