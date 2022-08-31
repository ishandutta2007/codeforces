#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int tst;
    cin >> tst;
    while (tst--) {
        int n, m;
        cin >> n >> m;
        vector<int> cnt(n);
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            cnt[x - 1]++;
        }
        int l = 0;
        int r = 2 * m + 2;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            ll free = 0;
            ll need = 0;
            for (int i = 0; i < n; i++) {
                if (cnt[i] <= mid) {
                    free += (mid - cnt[i]) / 2;
                }
                else {
                    need += (cnt[i] - mid);
                }
            }
            if (free >= need) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        cout << r << '\n';
    }
    return 0;
}