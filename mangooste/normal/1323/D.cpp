#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstring>
#include <iomanip>

using ll = long long;
using namespace std;

//#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(a) a.begin(), a.end()

const int LOG = 26;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    vector<int> a(n);
    forn(i, n) cin >> a[i];
    vector<vector<int>> tw(n, vector<int>(LOG));
    forn(i, n) forn(j, LOG) tw[i][j] = (a[i] >> j) & 1;
    vector<vector<int>> val(n, vector<int>(LOG));
    forn(i, n) {
        val[i][0] = tw[i][0];
        forn(j, LOG) if (j != 0) val[i][j] = val[i][j - 1] + (1 << j) * tw[i][j];
    }
    int sum = 0;
    forn(i, n) sum += tw[i][0];
    int ans = (sum & 1) * (n - sum & 1);
    forn(bit, LOG) if (bit != 0) {
        vector<int> inZero, inOne;
        forn(i, n) {
            if (tw[i][bit]) inOne.push_back(val[i][bit - 1]);
            else inZero.push_back(val[i][bit - 1]);
        }
        sort(all(inOne));
        sort(all(inZero));
        int cnt = 0, need = (1 << bit);
        for (int cur : inZero) {
            cnt += inZero.end() - lower_bound(all(inZero), need - cur);
            cnt -= (cur >= need - cur);
            cnt += lower_bound(all(inOne), need - cur) - inOne.begin();
        }
        for (int cur : inOne) {
            cnt += inOne.end() - lower_bound(all(inOne), need - cur);
            cnt -= (cur >= need - cur);
            cnt += lower_bound(all(inZero), need - cur) - inZero.begin();
        }
        cnt >>= 1;
        if (cnt & 1) ans += need;
    }
    cout << ans << '\n';
}