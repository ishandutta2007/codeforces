#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        string a, b;
        cin >> n >> a >> b;
        vector<int> ans;
        int l = 0, r = n - 1, flipped = 0;
        for (int i = n - 1; i >= 0; --i) {
            char val = a[r];
            int dir = (l <= r) ? 1 : -1;
            if (flipped) val ^= 1;
            if (val == b[i]) {
                r -= dir;
                continue;
            }
            char val2 = a[l];
            if (flipped) val2 ^= 1;
            if (val2 == b[i]) {
                ans.push_back(1);
            }
            ans.push_back(i + 1);
            flipped ^= 1;
            int oldr = r;
            r = l + dir;
            l = oldr;
        }
        cout << ans.size() << ' ';
        for (auto x: ans) cout << x << ' '; cout << '\n';
    }
    return 0;
}