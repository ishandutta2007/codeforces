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
        int s, n;
        cin >> s >> n;
        VI d;
        while(s) {
            d.push_back(s % 10);
            s /= 10;
        }
        int sz = d.size();
        auto check = [&]{
            return accumulate(all(d), 0) >= n;
        };
        while(!check()) {
            for(int i = 1; i < sz; i++) if (d[i]) {
                d[i]--;
                d[i - 1] += 10;
                break;
            }
        }
        VI ans(n);
        int p = 0;
        ll now = 1;
        rep(i, sz) {
            rep(_, d[i]) {
                ans[p++] += now;
                if (p == n) p = 0;
            }
            now *= 10;
        }
        rep(i, n) cout << ans[i] << " \n"[i + 1 == n];
    }
}