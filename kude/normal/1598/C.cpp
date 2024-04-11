#include<bits/stdc++.h>
using namespace std;
#define rep(i,n)for (int i = 0; i < int(n); ++i)
#define rrep(i,n)for (int i = int(n)-1; i >= 0; --i)
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
        map<int, int> hist;
        VI a(n);
        rep(i, n) cin >> a[i];
        ll s2 = accumulate(all(a), 0LL) * 2;
        if (s2 % n) {
            cout << 0 << '\n';
            continue;
        }
        s2 /= n;
        ll ans = 0;
        for(int x: a) {
            ans += hist[s2 - x];
            hist[x]++;
        }
        cout << ans << '\n';
    }
}