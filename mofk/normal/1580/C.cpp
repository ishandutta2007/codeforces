#include <bits/stdc++.h>

using namespace std;

const int mgc = 400;
int n, m;
int a[200005], b[200005];
vector<int> evt[200005];
vector<int> small, large;
int ans[200005], lzy[200005];
int lzy2[mgc + 5][200005];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
        a[i] = min(a[i], m + 1);
        b[i] = min(b[i], m + 1);
        if (a[i] + b[i] > mgc) large.push_back(i); else small.push_back(i);
    }
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        evt[v].push_back(i);
    }
    for (auto v: large) {
        if (evt[v].size() & 1) evt[v].push_back(m + 1);
        for (int i = 0; i < evt[v].size(); i += 2) {
            int l = evt[v][i] + a[v], r = evt[v][i+1];
            while (l < r) {
                int rr = min(l + b[v], r);
                if (l <= m) ++lzy[l];
                if (rr <= m) --lzy[rr];
                l += a[v] + b[v];
            }
        }
    }
    for (int i = 1; i <= m; ++i) {
        lzy[i] += lzy[i-1];
        ans[i] += lzy[i];
    }

    for (auto v: small) {
        if (evt[v].size() & 1) evt[v].push_back(m + 1);
        for (int i = 0; i < evt[v].size(); i += 2) {
            int l = evt[v][i] + a[v], r = evt[v][i+1];
            for (int ll = l; ll < l + b[v]; ++ll) {
                if (ll >= r) break;
                int rr = ll + ((r - ll - 1) / (a[v] + b[v]) + 1) * (a[v] + b[v]);
                if (ll <= m) ++lzy2[a[v] + b[v]][ll];
                if (rr <= m) --lzy2[a[v] + b[v]][rr];
            }
        }
    }
    for (int i = 1; i <= mgc; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (j >= i) lzy2[i][j] += lzy2[i][j-i];
            ans[j] += lzy2[i][j];
        }
    }

    for (int i = 1; i <= m; ++i) cout << ans[i] << '\n';
    return 0;
}