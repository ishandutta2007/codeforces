#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[100005];
int b[100005];
vector <int> job[100005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    for (int i = 1; i <= n; ++i) job[a[i]].push_back(b[i]);
    int need = 0;
    vector <int> avail;
    for (int i = 1; i <= k; ++i) {
        if (job[i].empty()) {
            ++need;
            continue;
        }
        sort(job[i].begin(), job[i].end());
        for (int j = 0; j + 1 < job[i].size(); ++j) avail.push_back(job[i][j]);
    }
    sort(avail.begin(), avail.end());
    long long ans = 0;
    for (int i = 0; i < need; ++i) ans += avail[i];
    cout << ans << endl;
    return 0;
}