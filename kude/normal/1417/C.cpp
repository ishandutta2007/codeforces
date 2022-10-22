#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        VI a(n);
        rep(i, n) cin >> a[i];
        VVI d(n+1);
        rep(i, n) {
            d[a[i]].push_back(i);
        }
        VI q(n + 1, -1);
        rep(i, n+1) {
            if (d[i].empty()) continue;
            int interval = d[i][0] + 1;
            for(int j = 0; j + 1 < d[i].size(); j++) {
                chmax(interval, d[i][j+1] - d[i][j]);
            }
            chmax(interval, n - d[i].back());
            if (q[interval] < 0) q[interval] = i;
        }
        int now = -1;
        for(int i = 1; i <= n; i++) {
            if (q[i] >= 0 && (now < 0 || q[i] < now)) {
                now = q[i];
            }
            cout << now << " \n"[i == n];
        }
    }
}