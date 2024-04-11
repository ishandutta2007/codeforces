#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, a[303], b[303], c[303];
pair<int, int> p[303];

void solve(){
    cin >> n >> m;
    for(int i=1;i<=m;i++) cin >> a[i];

    for(int i=1;i<=m;i++) p[i] = {a[i], -i};
    sort(p+1, p+1+m);

    for(int i=1;i<=m;i++) c[i] = 0, b[-p[i].second] = i;
    
    int ans = 0;
    for(int i=1;i<=m;i++){
        int x = b[i];
        for(int j=1;j<x;j++) ans += c[j];
        c[x] = 1;
    }
    cout << ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int tc = 1; cin >> tc;
    while(tc--) solve(), cout << "\n";
}