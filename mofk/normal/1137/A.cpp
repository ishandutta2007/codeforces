#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[1005][1005];
int r[1005][1005], c[1005][1005];
int p[1005][1005], q[1005][1005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) cin >> a[i][j];
    for (int i = 1; i <= n; ++i) {
        vector <int> v;
        for (int j = 1; j <= m; ++j) v.push_back(a[i][j]);
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());
        int sz = v.size();
        for (int j = 1; j <= m; ++j) {
            int id = lower_bound(v.begin(), v.end(), a[i][j]) - v.begin();
            r[i][j] = id + 1;
            p[i][j] = sz - r[i][j];
        }
    }
    for (int j = 1; j <= m; ++j) {
        vector <int> v;
        for (int i = 1; i <= n; ++i) v.push_back(a[i][j]);
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());
        int sz = v.size();
        for (int i = 1; i <= n; ++i) {
            int id = lower_bound(v.begin(), v.end(), a[i][j]) - v.begin();
            c[i][j] = id + 1;
            q[i][j] = sz - c[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int ans = max(r[i][j], c[i][j]) + max(p[i][j], q[i][j]);
            cout << ans << ' ';
        }
        cout << '\n';
    }
    return 0;
}