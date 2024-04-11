#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = (int)1e5 + 100;
int a[maxN];

void solve()
{
    cin >> n;
    ll S = 0;
    ll xr = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        S += a[i];
        xr ^= a[i];
    }
    ll P = (ll)1e18 - (S % 2);
    xr ^= P;
    S += P;
    assert(2 * xr >= S);
    ll t = (2 * xr - S) / 2;
    cout << 3 << " " << t << " " << t << " " << P<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    
    int t;
    cin>>t;
    for (int i = 0; i<t; i++) solve();

}