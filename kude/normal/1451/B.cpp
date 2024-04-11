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
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        while(q--) {
            int l, r;
            cin >> l >> r;
            --l, --r;
            int a = 0, b = n - 1;
            for(; a < n; ++a) {
                if (s[a] == s[l]) break;
            }
            for(; b >= 0; --b) {
                if (s[b] == s[r]) break;
            }
            if (l == a && r == b) cout << "NO\n";
            else cout << "YES\n";
        }
    }
}