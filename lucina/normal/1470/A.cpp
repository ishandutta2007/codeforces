#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n, m;
int k[nax];
int a[nax];

void solve() {
    cin >> n >> m;
    for (int i = 1 ; i <= n ; ++ i)
        cin >> k[i];
    sort(k + 1, k + 1 + n);
    int64_t s = 0;
    for (int i = 1 ; i <= m ; ++ i) {
        cin >> a[i];
    }
    for (int i = 1 ; i <= n ; ++ i)
        s += a[k[i]];
    int carry = 0;
    int64_t ans = s;
    for (int i = n ; i >= 1 ; -- i) {
        carry += 1;
        if (carry > k[i]) break;
        s -= a[k[i]];
        s += a[n - i + 1];
        ans = min(ans, s);
    }
    cout << ans << '\n';
}

int main() {
   cin.tie(0)->sync_with_stdio(false);
   int T;
   for (cin >> T ; T -- ;) {
       solve();
   }
    
}