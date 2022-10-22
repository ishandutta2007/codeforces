#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll Inf = 1000000000000000LL;
const int Maxn = 51, Maxl = 5000, Maxm = 250000;

ll n, m, len, el[Maxl], bs[Maxn], bm[Maxn], be[Maxn], sm[Maxn], ans;
ll ind[Maxm];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> len;
        for (int j = 0; j < len; j++) cin >> el[j];
        ll sum = 0; bs[i] = -Inf;
        for (int j = 0; j < len; j++) {
            sum += el[j];
            if (sum > bs[i]) bs[i] = sum;
        }
        sm[i] = sum;
        sum = 0; be[i] = -Inf;
        for (int j = len - 1; j >= 0; j--) {
            sum += el[j];
            if (sum > be[i]) be[i] = sum;
        }
        sum = 0; bm[i] = -Inf;
        for (int j = 0; j < len; j++) {
            if (sum < 0) sum = 0;
            sum += el[j];
            if (sum > bm[i]) bm[i] = sum;
        }
    }
    for (int i = 0; i < m; i++) cin >> ind[i];
    ll sum = 0; ans = -Inf;
    for (int i = 0; i < m; i++) {
        if (sum + bs[ind[i]] > ans) ans = sum + bs[ind[i]];
        if (bm[ind[i]] > ans) ans = bm[ind[i]];
        sum = max(be[ind[i]], sum + sm[ind[i]]);
        if (sum > ans) ans = sum;
    }
    cout << ans << endl;
    return 0;
}