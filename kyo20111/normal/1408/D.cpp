#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, k, a[2020], b[2020], c[2020], d[2020], mx[4004004], INF = 1e7;
pair<int, int> v[4004004];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i] >> b[i];
    for(int i=1;i<=m;i++) cin >> c[i] >> d[i];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            v[++k] = {max(0, c[j] - a[i] + 1), max(0, d[j] - b[i] + 1)};
        }
    }

    sort(v+1, v+1+k);
    for(int i=k;i>=1;i--) mx[i] = max(mx[i+1], v[i].second);

    int ans = 1e9;
    for(int i=0;i<=v[k].first;i++){
        int val = upper_bound(v+1, v+k+1, make_pair(i, INF)) - v;
        ans = min(ans, i + mx[val]);
    }

    cout << ans;
}