#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        vector<int> cntA(101);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cntA[x]++;
        }
        vector<int> cntB(101);
        for (int i = 0; i < n; i++) {
            int y;
            cin >> y;
            cntB[y]++;
        }
        int l = -1;
        int r = 10 * n;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            vector<int> startA = cntA;
            vector<int> startB = cntB;
            int tot = (n + mid);
            int good = (tot - (tot / 4));
            startA[100] += mid;
            startB[0] += mid;
            ll X = 0;
            ll Y = 0;
            int ngood = good;
            for (int z = 100; z >= 0; z--) {
                int take = min(ngood, startA[z]);
                X += (ll)take * z;
                ngood -= take;
            }
            ngood = good;
            for (int z = 100; z >= 0; z--) {
                int take = min(ngood, startB[z]);
                Y += (ll)take * z;
                ngood -= take;
            }
            if (X >= Y) r = mid;
            else l = mid;
        }
        cout << r << '\n';
    }
    return 0;
}