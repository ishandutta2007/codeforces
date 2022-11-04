#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, a[100100], b[100100], c[100100], cnt[100100];

void solve(){
    cin >> n >> m;
    for(int i=1;i<=m;i++) cin >> a[i] >> b[i] >> c[i];

    for(int i=1;i<=m;i++) cnt[b[i]]++;

    int u = 1;
    while(cnt[u]) u++;

    for(int i=1;i<=n;i++) cnt[i] = 0;

    for(int i=1;i<=n;i++) if(i != u) cout << i << " " << u << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int tc = 1; cin >> tc;
    while(tc--) solve();
}