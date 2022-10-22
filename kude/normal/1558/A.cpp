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
        int a, b;
        cin >> a >> b;
        vector<char> d(a + b + 1, false);
        rep(_, 2) {
            int tot = a + b;
            int p = tot / 2, q = tot - p;
            int mx = min(p, a) + min(q, b);
            int mn = max(0, p - b) + max(0, q - a);
            for(int i = mn; i <= mx; i += 2) d[i] = true;
            swap(a, b);
        }
        VI ans;
        rep(i, a + b + 1) if (d[i]) ans.push_back(i);
        int sz = ans.size();
        cout << sz << '\n';
        rep(i, sz) cout << ans[i] << " \n"[i + 1 == sz];
    }
}