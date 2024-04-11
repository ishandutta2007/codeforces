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
        vector<int> a(n + 1, 0);
        vector<int> b(n + 1, 0);
        vector<int> rb(n + 1, 0);
        int ans = 0;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) {
            if (!rb[a[i]]) {
                b[i] = a[i];
                rb[a[i]] = i;
                ++ans;
            }
        }
        vector<int> spa, spb;
        for (int i = 1; i <= n; ++i) if (!b[i]) spa.push_back(i);
        for (int i = 1; i <= n; ++i) if (!rb[i]) spb.push_back(i);

        while (spa.size() > 1) {
            int x = spa.back();
            spa.pop_back();
            for (int i = spb.size() - 1; i >= 0; --i) if (spb[i] != x) {
                b[x] = spb[i];
                rb[spb[i]] = x;
                spb.erase(spb.begin() + i);
                break;
            }
        }

        if (spa.size() == 1) {
            if (spa[0] == spb[0]) {
                int x = spa[0];
                b[x] = a[x];
                int y = rb[a[x]];
                rb[a[x]] = x;
                spa[0] = y;
            }

            b[spa[0]] = spb[0];
            rb[spb[0]] = spa[0];
        }

        cout << ans << endl;
        for (int i = 1; i <= n; ++i) cout << b[i] << ' ';
        cout << endl;
    }
    return 0;
}