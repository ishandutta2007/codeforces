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
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        int ans = 0;
        char last = '_';
        rep(i, n) {
            if (a[i] != b[i]) {
                ans += 2;
                last = '_';
            } else if (a[i] == '0') {
                if (last == '1') {
                    ans += 2;
                    last = '_';
                } else {
                    ans += 1;
                    last= '0';
                }
            } else {
                if (last == '0') {
                    ans += 1;
                    last = '_';
                } else {
                    last = '1';
                }
            }
        }
        cout << ans << '\n';
    }
}