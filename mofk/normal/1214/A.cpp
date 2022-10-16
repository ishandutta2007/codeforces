#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n, a, b;
    cin >> n >> a >> b;
    b *= 5;
    int ans = n;
    for (int i = 0; i <= n; i += b) ans = min(ans, (n - i) % a);
    cout << ans << endl;
    return 0;
}