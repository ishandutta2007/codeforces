#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const long long INF = 1E18 + 7;

int n, m, a[N], b[N];
long long sl = 0, sr = 0;
long long ans = INF;
vector<int> ve;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ve.push_back(a[i]);
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        ve.push_back(b[i]);
        sr += b[i];
    }
    sort(ve.begin(), ve.end());
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    int pl = 1, pr = 1;
    for (int &v : ve) {
        while (pl <= n && a[pl] <= v) {
            sl += a[pl++];
        }
        while (pr <= m && b[pr] <= v) {
            sr -= b[pr++];
        }
        long long cur = 1LL * v * (pl - 1) - sl;
        cur += sr - 1LL * v * (m - pr + 1);
        ans = min(ans, cur);
    }
    cout << ans;
}