#include <iostream>
#define int long long
using namespace std;

const int inf = -1e9;
const int N = 2e5 + 5;

int n, a[N], b[N], ans = 0, pref[N];

void solve(int q) {
    for (int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + a[i];
    int p = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, pref[i] - pref[p] - q);
        if (pref[i] < pref[p])
            p = i;
    }

}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int q = -30; q <= 30; q++) {
        //cout << q << endl;
        for (int i = 1; i <= n; i++)
            if (b[i] <= q)
                a[i] = b[i];
            else
                a[i] = inf;
        solve(q);
    }
    cout << ans;
    return 0;
}