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
        int x;
        cin >> x;
        if (x > 45) {
            cout << -1 << '\n';
            continue;
        }
        VI a(11);
        a[10] = 10;
        int i = 9;
        while(x) {
            if (a[i] + 1 == a[i + 1]) --i;
            a[i] += 1;
            x -= 1;
        }
        string ans;
        for(; i < 10; ++i) ans += '0' + a[i];
        cout << ans << '\n';
    }
}