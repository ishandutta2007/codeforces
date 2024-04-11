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
        VL a(n);
        rep(i, n) cin >> a[i];
        VI ord(n);
        iota(all(ord), 0);
        sort(all(ord), [&](int x, int y){return a[x] < a[y];});
        int s = -1;
        ll now = 0;
        int i = 0;
        while(i < n) {
            if (now < a[ord[i]]) {
                s = i;
            }
            ll x = a[ord[i]];
            do {
                now += x;
                i++;
            } while(i < n && a[ord[i]] == x);
        }
        VI ans;
        for(int i = s; i < n; ++i) ans.push_back(ord[i] + 1);
        sort(all(ans));
        int sz = ans.size();
        cout << sz << '\n';
        rep(i, sz) cout << ans[i] << " \n"[i + 1 == sz];
    }
}