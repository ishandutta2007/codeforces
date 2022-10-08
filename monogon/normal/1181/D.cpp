
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include <bits/stdc++.h>

#define ll long long
using namespace std;

using namespace __gnu_pbds; 

typedef tree<int, null_type, less<int>, rb_tree_tag, 
             tree_order_statistics_node_update> ord; 

const int N = 5e5 + 5;
int n, m, q, a[N], cnt[N], ans[N];
ll k, t[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    vector<pair<int, int>> ve;
    for(int i = 1; i <= m; i++) {
        ve.emplace_back(cnt[i], i);
    }
    sort(ve.begin(), ve.end());
    vector<pair<ll, int>> quer;
    for(int i = 0; i < q; i++) {
        cin >> k;
        quer.emplace_back(k, i);
    }
    sort(quer.begin(), quer.end());
    int qidx = 0;
    t[1] = n + 1;
    ord se;
    se.insert(ve[0].second);
    for(int i = 2; i <= m; i++) {
        t[i] = t[i - 1] + 1LL * (i - 1) * (ve[i - 1].first - ve[i - 2].first);
        while(qidx < q && quer[qidx].first < t[i]) {
            ans[quer[qidx].second] = *se.find_by_order(((quer[qidx].first - t[i - 1]) % (i - 1) + i - 1) % (i - 1));
            qidx++;
        }
        se.insert(ve[i - 1].second);
    }
    while(qidx < q) {
        ans[quer[qidx].second] = *se.find_by_order(((quer[qidx].first - t[m]) % m + m) % m);
        qidx++;
    }
    for(int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }
}