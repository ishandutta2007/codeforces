#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        map<int, int> a;
        while (n--) {
            int x;
            cin >> x;
            ++a[abs(x)];
        }
        int ans = 0;
        for (auto x: a) if (x.first == 0) ans += min(x.second, 1); else ans += min(x.second, 2);
        cout << ans << '\n';
    }
    return 0;
}