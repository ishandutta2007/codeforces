#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, p, a[100100];
vector<ll> ans;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> p;
    for(ll i=1;i<=n;i++) cin >> a[i];
    sort(a+1, a+1+n);
    ll mx = 0;
    for(int i=1;i<=n;i++) mx = max(mx, a[i] - i + 1);
    ll mn = a[n] + 1;
    for(int i=p;i<=n;i++) mn = min(mn, a[i] - (i - p));
    for(int i=mx;i<mn;i++) ans.push_back(i);
    cout << ans.size() << '\n';
    for(auto x : ans) cout << x << ' ';
}