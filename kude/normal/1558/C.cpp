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

void solve() {
    int n;
    cin >> n;
    VI a(n);
    rep(i, n) cin >> a[i], a[i]--;
    rep(i, n) if (a[i] % 2 != i % 2) {
        cout << -1 << '\n';
        return;
    }
    VI ans;
    auto op = [&](int x) {
        if (x == 1) return;
        ans.push_back(x);
        reverse(a.begin(), a.begin() + x);
    };
    while(n > 1) {
        int p = n - 1, q = n - 2;
        int i = 0;
        for(;; i++) if (a[i] == p) break;
        op(i + 1);
        i = 0;
        int j = 0;
        for(;; j++) if (a[j] == q) break;
        op(j);
        i = j - 1;
        op(n);
        i = n - 1 - i, j = n - 1 - j;
        op(i + 1);
        op(n);
        n -= 2;
    }
    int sz = ans.size();
    cout << sz << '\n';
    rep(i, sz) cout << ans[i] << " \n"[i + 1 == sz];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        solve();
    }
}