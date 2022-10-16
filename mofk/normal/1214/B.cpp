#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int b, g, n;
    cin >> b >> g >> n;
    int ans = 0;
    for (int i = 0; i <= n; ++i) if (i <= b && n - i <= g) ++ans;
    cout << ans << endl;
    return 0;
}