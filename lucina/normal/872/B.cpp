#include<bits/stdc++.h>
using namespace std;
const int nax = 1e5 + 10;
int n, k;
int a[nax];
int mn[nax];

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1 ; i <= n ; ++ i)
        cin >> a[i];
    int ans;
    if (k == 1) {
        ans = *min_element(a + 1, a + 1 + n);
    } else if (k == 2) {
        mn[0] = ans = 1e9 + 7;
        ans = -ans;
        for (int i = 1 ; i <= n ; ++ i)
            mn[i] = min(mn[i - 1], a[i]);
        int smn = 1e9 + 7;
        for (int i = n ; i > 1 ; -- i)
            smn = min(smn, a[i]), ans = max(ans, max(smn, mn[i - 1]));
    } else {
        ans = *max_element(a + 1, a + 1 + n);
    }
    cout << ans << '\n';
}