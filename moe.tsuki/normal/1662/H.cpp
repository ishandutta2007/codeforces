#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        int h, l; cin >> h >> l;
        vector<int> ans;
        auto upd = [&](int x) {
            if ((h - 1) % x == 0 and (l - 1) % x == 0)
                ans.push_back(x);
            else if ((h - 2) % x == 0 and l % x == 0)
                ans.push_back(x);
            else if (h % x == 0 and (l - 2) % x == 0)
                ans.push_back(x);
            else if ((h - 2) % x == 0 and h % x == 0 and (l - 1) % x ==0)
                ans.push_back(x);
            else if ((l - 2) % x == 0 and l % x == 0 and (h - 1) % x ==0)
                ans.push_back(x);

        };
        auto chk = [&](int x){
            for (int d = 1; d * d <= x; ++d) {
                if (x % d == 0) {
                    upd(d);
                    upd(x / d);
                }
                if (x - 1 >= 1 and (x - 1) % d == 0) {
                    upd(d);
                    upd((x - 1) / d);
                }
                if (x - 2 >= 1 and (x - 2) % d == 0) {
                    upd(d);
                    upd((x - 2) / d);
                }
            }
        };
        chk(h);
        chk(l);
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        cout << ans.size();
        for (int x : ans) cout << ' ' << x;
        cout << '\n';
    }
    return 0;
}