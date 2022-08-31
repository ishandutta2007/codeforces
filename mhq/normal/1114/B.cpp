#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, k;
const int maxN = 2 * (int)1e5 + 100;
int a[maxN];
bool need[maxN];
ll ans;
bool en[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    // [1 .. m], [m + 1, .. 2m]
    // [1 .. m],
    cin >> n >> m >> k;
    vector < pair < int, int > > all;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        all.emplace_back(a[i], i);
    }
    sort(all.begin(), all.end());
    reverse(all.begin(), all.end());
    for (int i = 0; i < m * k; i++) {
        ans += all[i].first;
        need[all[i].second] = true;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (need[i]) {
            cnt++;
            if ((cnt % m == 0) && (cnt != m * k) && (cnt > 0)) {
                en[i] = true;
            }
        }
    }
    cout << ans << '\n';
    for (int i = 1; i <= n; i++) {
        if (en[i]) cout << i << " ";
    }
}