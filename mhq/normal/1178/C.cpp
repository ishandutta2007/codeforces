#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int w, h;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> w >> h;
    int ans = 1;
    for (int i = 1; i <= w + h; i++) {
        ans = (1LL * ans * 2) % 998244353;
    }
    cout << ans;
    return 0;
}