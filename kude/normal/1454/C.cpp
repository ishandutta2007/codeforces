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
        VI a(n);
        VI last(n, 0), sum(n, 0);
        VVI d(n);
        rep(i, n) {
            int a;
            cin >> a;
            a--;
            if (last[a] < i) sum[a]++;
            last[a] = i + 1;
        }
        int ans = n + 10;
        rep(a, n) {
            if (last[a]) chmin(ans, sum[a] + (last[a] < n));
        }
        cout << ans << '\n';
    }
}