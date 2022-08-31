#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 2 * (int)1e5 + 10;
ll ans[maxN];
int n;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    vector < pair < ll, int > > q;
    for (int i = 1; i <= n; i++) {
        ll l, r;
        cin >> l >> r;
        q.push_back(make_pair(l, 1));
        q.push_back(make_pair(r + 1, -1));
    }
    sort(q.begin(), q.end());
    int bal = 0;
    for (int i = 0; i + 1 < q.size(); i++) {
        bal += q[i].second;
        if (bal > 0) ans[bal] += q[i + 1].first - q[i].first;
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    return 0;
}