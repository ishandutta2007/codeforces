#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = (n)-1; i >= 0; --i)
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
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
        string s, t;
        cin >> s >> t;
        int n = s.size(), m = t.size();
        int len = n * m / gcd(n, m);
        string ans1, ans2;
        rep(i, len / n) ans1 += s;
        rep(i, len / m) ans2 += t;
        if (ans1 == ans2) {
            cout << ans1 << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}