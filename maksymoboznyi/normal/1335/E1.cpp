#include <bits/stdc++.h>
#define pb push_back

using namespace std;

const int N = 2e5 + 5;
const int M = 201;
const int INF = 1e18;

int n, A[N], ans, kol[N];
vector<int> p[M];

void go(int a) {

    ans = max(ans, int(p[a].size()));
    if (p[a].size() < 2)
        return;
    //if (p[a].size() % 2 == 0) {
        int sz = p[a].size();
        for (int i = 1; i <= 200; i++)
            kol[i] = 0;
        int mx = 0;
        int l = sz / 2 - 1, r = sz - 1 - l;
        for (int i = p[a][l] + 1; i < p[a][r]; i++)
            kol[A[i]]++, mx = max(mx, kol[A[i]]);
        ans = max(ans, 2 * (l + 1) + mx);

        l--;
        r++;
        while (l >= 0) {
            for (int i = p[a][l + 1] - 1; i > p[a][l]; i--)
                kol[A[i]]++, mx = max(mx, kol[A[i]]);
            for (int i = p[a][r - 1] + 1; i < p[a][r]; i++)
                kol[A[i]]++, mx = max(mx, kol[A[i]]);
            ans = max(ans, 2 * (l + 1) + mx);
            l--;
            r++;
        }
    //}
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= 200; i++)
            p[i].clear();
        for (int i = 1; i <= n; i++)
            cin >> A[i], p[A[i]].pb(i);
        ans = 0;
        for (int i = 1; i <= 200; i++)
            go(i);
        cout << ans << "\n";
    }
    return 0;
}