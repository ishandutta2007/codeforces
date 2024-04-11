#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    ll mx = 0;
    for (int i = 1; i <= n; i++) {
        ll b;
        cin >> b;
        cout << b + mx << " ";
        mx = max(mx, b + mx);
    }
    return 0;
}