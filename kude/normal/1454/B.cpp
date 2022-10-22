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
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector<P> a(n);
        rep(i, n) cin >> a[i].first, a[i].second = i + 1;
        sort(all(a));
        bool ok = false;
        rep(i, n) {
            if (
                (0 <= i - 1 && a[i-1].first == a[i].first) ||
                (i + 1 < n && a[i].first == a[i+1].first)) continue;
            ok = true;
            cout << a[i].second << '\n';
            break;
        }
        if (!ok) cout << "-1\n";
    }
}