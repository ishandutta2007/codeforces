#include <bits/stdc++.h>
using namespace std;
typedef long long LL;



int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<LL> a(n);
    vector<LL> b(n);
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    LL ans = 0;
    for(int i = 0; i < n; i++){
        ans += 1 + max(a[i], b[i]);
    }
    cout << ans << '\n';
}