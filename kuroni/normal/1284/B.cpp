#include <bits/stdc++.h>
using namespace std;

const int N = 1E5 + 5, INF = 1E9 + 7;

int n, cnt = 0, ok = 0;
long long ans = 0;
vector<pair<int, int>> ve;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int l;
        cin >> l;
        int mi = INF, mx = 0, prv = INF, cur = 0;
        bool chk = false;
        for (int j = 1; j <= l; j++) {
            cin >> cur;
            if (cur > prv) {
                chk = true;
            }
            mi = min(mi, cur);
            mx = max(mx, cur);
            prv = cur;
        }
        if (chk) {
            ok++;
        } else {
            ve.push_back({mi + 1, 0});
            ve.push_back({mx, 1});
        }
    }
    sort(ve.begin(), ve.end());
    for (pair<int, int> &v : ve) {
        if (v.second) {
            ans += cnt;
        } else {
            cnt++;
        }
    }
    ans += 1LL * ok * ok + 2LL * ok * cnt;
    cout << ans;
}