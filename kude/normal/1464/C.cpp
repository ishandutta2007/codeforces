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
    ll t;
    cin >> n >> t;
    VI a(n);
    rep(i, n) {
        char c;
        cin >> c;
        a[i] = c - 'a';
    }
    // if all +
    ll b = 0;
    rep(i, n - 2) {
        b += 1 << a[i];
    }
    b -= 1 << a[n - 2];
    b += 1 << a[n - 1];
    t = t - b;
    t = -t;
    VI hist(30);
    rep(i, n - 2) {
        hist[a[i] + 1]++;
    }
    rrep(k, 30) {
        while(hist[k] && t >= (1 << k)) {
            hist[k]--;
            t -= 1 << k;
        }
    }
    cout << (t == 0 ? "Yes" : "No") << endl;
}