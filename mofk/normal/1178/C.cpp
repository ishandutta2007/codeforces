#include <bits/stdc++.h>

using namespace std;
const int mod = 998244353;
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int a, b, ans = 1;
    cin >> a >> b;
    for (int i = 0; i < a + b; ++i) ans = 2LL * ans % mod;
    cout << ans << endl;
    return 0;
}