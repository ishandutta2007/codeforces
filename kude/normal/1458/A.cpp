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
    int n, m;
    cin >> n >> m;
    VL a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    ll g = 0;
    for(int i = 1; i < n; ++i) {
        g = gcd(g, a[i] - a[0]);
    }
    rep(j, m) {
        cout << gcd(g, a[0] + b[j]) << '\n';
    }
}