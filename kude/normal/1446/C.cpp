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

int n;
VI a;

int dfs(int l, int r) {
    if (r - l == 1) return 0;
    int mn = a[l], mx = a[r-1];
    int k = mn ^ mx;
    int t = 1;
    while((t << 1) <= k) t = t << 1;
    int left = l, right = r-1;
    while(right - left > 1) {
        int c = (left + right) / 2;
        if (a[c] & t) {
            right = c;
        } else {
            left = c;
        }
    }
    int c = right; // [l, c), [c, r)
    int ans = min(dfs(c, r) + c - l - 1, dfs(l, c) + r - c - 1);
    //cout << l << ' ' << r << ' ' << ans << endl;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    rep(i, n) cin >> a[i];
    sort(all(a));
    int ans = dfs(0, n);
    cout << ans << '\n';
}