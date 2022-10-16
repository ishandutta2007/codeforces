#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    int ans = 0, last = 0, cnt = 0;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        if (x != last) ++cnt;
        else cnt = 1;
        ans = max(ans, cnt);
        last = x;
    }
    cout << ans << endl;
    return 0;
}