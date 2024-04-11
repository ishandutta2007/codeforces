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
    int n;
    cin >> n;
    VI a(n);
    int s = 0;
    rep(i, n) {
        cin >> a[i];
        s ^= a[i];
    }
    rep(i, n) a[i] ^= s;
    if (n % 2 == 0) {
        int s = 0;
        rep(i, n-1) s ^= a[i];
        if (s != a[n-1]) {
            cout << "NO" << endl;
            return 0;
        }
        a.pop_back();
        n -= 1;
    }
    vector<tuple<int,int,int>> ans;
    cout << "YES" << endl;
    for(int i = 1; i < n; i += 2) {
        ans.emplace_back(0, i, i + 1);
    }
    for(int i = 1; i < n - 2; i += 2) {
        ans.emplace_back(0, i, i + 1);
    }
    cout << ans.size() << '\n';
    for(auto [i, j, k]: ans) {
        ++i, ++j, ++k;
        cout << i << ' ' << j << ' ' << k << '\n';
    }
}