#include <bits/stdc++.h>

using namespace std;

int n;
int a[205];
int l[105], r[105];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= 2 * n; ++i) {
        cin >> a[i];
        if (l[a[i]]) r[a[i]] = i;
        else l[a[i]] = i;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) if (l[i] < l[j]) {
        if (r[i] < l[j]) continue;
        if (r[i] < r[j]) ans += 1;
        else ans += 2;
    }
    cout << ans << endl;
    return 0;
}