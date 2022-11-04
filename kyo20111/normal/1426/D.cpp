#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, cnt;
ll a[200200], m;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i], a[i] += a[i-1];

    set<ll> s;
    for(int i=1;i<=n;i++){
        if(a[i] == m || s.count(a[i])) cnt++, s.clear(), m = a[i-1];
        s.insert(a[i]);
    }

    cout << cnt;
}