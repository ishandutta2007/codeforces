#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < int(n); ++i)
#define rrep(i,n) for(int i = int(n)-1; i >= 0; --i)
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
        VI a(n);
        rep(i, n) {
            char c;
            cin >> c;
            if (i & 1) c = 'L' + 'R' - c;
            a[i] = c == 'R';
        }
        VI all(n + 1), alr(n + 1), arl(n + 1), arr(n + 1);
        rep(i, n) {
            if (a[i] == 0) all[i+1] = all[i] + 1;
            else all[i+1] = 0;
        }
        rrep(i, n) {
            if (a[i] == 0) alr[i] = alr[i+1] + 1;
            else alr[i] = 0;
        }
        rep(i, n) {
            if (a[i] == 1) arl[i+1] = arl[i] + 1;
            else arl[i+1] = 0;
        }
        rrep(i, n) {
            if (a[i] == 1) arr[i] = arr[i+1] + 1;
            else arr[i] = 0;
        }
        rep(i, n + 1) {
            int ans;
            if (i % 2 == 0) {
                ans = arl[i] + arr[i] + 1;
            } else {
                ans = all[i] + alr[i] + 1;
            }
            cout << ans << " \n"[i == n];
        }
    }
}