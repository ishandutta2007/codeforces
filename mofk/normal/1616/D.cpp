#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n, x;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        cin >> x;
        for (int i = 0; i < n; ++i) a[i] -= x;
        a.push_back(100000000);
        a.push_back(100000000);
        int ans = 0;
        int cur = 0;
        while (cur < n) {
            if (a[cur] + a[cur + 1] < 0) {
                cur += 2;
                ++ans;
            }
            else if (a[cur] + a[cur + 1] + a[cur + 2] < 0) {
                cur += 3;
                ++ans;
            }
            else {
                ++cur;
            }
        }
        cout << n - ans << '\n';
    }
    return 0;
}