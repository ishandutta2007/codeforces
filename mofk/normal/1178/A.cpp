#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n, a[105], s = 0, v = 0;
    cin >> n;
    vector <int> ans;
    for (int i = 1; i <= n; ++i) cin >> a[i], s += a[i];
    for (int i = 1; i <= n; ++i) if (i == 1 || a[i] * 2 <= a[1]) v += a[i], ans.push_back(i);
    if (2 * v <= s) cout << 0 << endl;
    else {
        cout << ans.size() << endl;
        for (auto x: ans) cout << x << ' '; cout << endl;
    }
    return 0;
}