#include <bits/stdc++.h>

using namespace std;

int n;
int a[1005], h[1005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) h[i] = a[i] - a[i-1];
    vector <int> ans;
    for (int i = 1; i <= n; ++i) {
        int flag = 1;
        for (int j = 1; j + i <= n; ++j) if (h[j] != h[j + i]) flag = 0;
        if (flag) ans.push_back(i);
    }
    cout << ans.size() << endl;
    for (auto x: ans) cout << x << ' '; cout << endl;
    return 0;
}