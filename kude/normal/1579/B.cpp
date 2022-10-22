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
        VI a(n);
        rep(i, n) cin >> a[i];
        vector<tuple<int, int, int>> ans;
        rep(i, n) {
            int j = min_element(a.begin() + i, a.end()) - a.begin();
            if (i == j) continue;
            ans.emplace_back(i, j, j - i);
            rotate(a.begin() + i, a.begin() + j, a.begin() + j + 1);
        }
        cout << ans.size() << '\n';
        for(auto [l, r, d]: ans) {
            cout << l + 1 << ' ' << r + 1 << ' ' << d << '\n';
        }
    }
}