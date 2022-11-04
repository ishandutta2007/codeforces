#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, a[100100], b[100100];

void solve(){
    cin.tie(0)->sync_with_stdio(0);
    map<pair<int, int>, int> mp;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i], b[i] = a[i];
    sort(b+1, b+1+n);

    for(int i=1;i<=n;i++) mp[{a[i], i%2}]++;
    for(int i=1;i<=n;i++) mp[{b[i], i%2}]--;

    int ans = 1;
    for(auto [x, y] : mp) if(y) ans = 0;
    cout << (ans ? "YES" : "NO");
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int tc = 1; cin >> tc;
    while(tc--) solve(), cout << "\n";
}