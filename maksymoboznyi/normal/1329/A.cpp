#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 5e5 + 5;

int n, m;
int a[N], suff[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        if (a[i] + i  - 1 > n) {
            cout << -1;
            return 0;
        }
    }
    for (int i = m; i > 0; i--)
        suff[i] = suff[i + 1] + a[i];
    if (suff[1] < n) {
        cout << -1;
        return 0;
    }
    int cur = 1;
    vector<int> ans;
    for (int i = 1; i <= m; i++) {
        ans.pb(cur);
        if (n - suff[i + 1] <= cur)
            cur++;
        else {
            int lcur = cur;
            cur = n - suff[i + 1] + 1;
            if (cur - lcur > a[i]) {
                cout << -1;
                return 0;
            }
        }
    }
    for (auto u: ans)
        cout << u << ' ';

    return 0;
}