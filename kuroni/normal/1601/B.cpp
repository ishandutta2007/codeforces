#include <bits/stdc++.h>
using namespace std;

const int N = 300005;

int n, a[N], b[N], dst[N][2], tr[N][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        dst[i][0] = dst[i][1] = 10 * N;
    }
    int pt = n - 1;
    queue<pair<int, int>> q;
    for (dst[n][0] = 0, q.push({n, 0}); !q.empty(); q.pop()) {
        auto [u, v] = q.front();
        int nv = v ^ 1;
        if (v == 0) {
            for (; pt >= u - a[u]; pt--) {
                tr[pt][nv] = u;
                dst[pt][nv] = dst[u][v] + 1;
                q.push({pt, nv});
            }
            if (pt == -1) {
                vector<int> ans;
                for (int i = 0, st = dst[0][1]; st > 0; st--, i = tr[tr[i][1]][0]) {
                    ans.push_back(i);
                }
                reverse(ans.begin(), ans.end());
                cout << ans.size() << '\n';
                for (int v : ans) {
                    cout << v << " ";
                }
                return 0;
            }
        } else {
            int nu = u + b[u];
            if (dst[nu][nv] > dst[u][v]) {
                tr[nu][nv] = u;
                dst[nu][nv] = dst[u][v];
                q.push({nu, nv});
            }
        }
    }
    cout << -1;
}