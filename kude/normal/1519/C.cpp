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
        VI u(n), s(n);
        rep(i, n) cin >> u[i], u[i]--;
        rep(i, n) cin >> s[i];
        VL ans(n);
        VVI ss(n);
        rep(i, n) ss[u[i]].push_back(s[i]);
        for(auto t: ss) {
            sort(rall(t));
            int n = t.size();
            VL s(n + 1);
            rep(i, n) s[i + 1] = s[i] + t[i];
            for(int i = 1; i <= n; i++) {
                ll v = s[n / i * i];
                ans[i - 1] += v;
            }
        }
        rep(i, n) cout << ans[i] << " \n"[i + 1 == n];
    }
}