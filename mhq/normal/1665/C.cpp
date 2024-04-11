#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2e5 + 10;
int deg[maxN];
int p[maxN];
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            deg[i] = 0;
        }
        for (int i = 2; i <= n; i++) {
            int p;
            cin >> p;
            deg[p]++;
        }
        vector<int> all;
        for (int i = 1; i <= n; i++) {
            if (deg[i] > 0) {
                all.emplace_back(deg[i]);
            }
        }
        sort(all.begin(), all.end());
        reverse(all.begin(), all.end());
        int l = 0;
        int r = n + 10;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            int cnt = all.size() + 1;
            for (int i = 0; i < all.size(); i++) {
                int sz = all[i];
                if ((mid - i - 1 + 1) < sz) {
                    cnt += (sz - (mid - i));
                }
            }
            if (cnt > mid) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        cout << r << '\n';
    }
    return 0;
}