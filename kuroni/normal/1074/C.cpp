#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 300005, INF = 1E9;

int n;
int ans = -INF, per = 0;
int ly = -INF, hxy = -INF, lxy = -INF;
int fh = -INF, fl = -INF;
pair<int, int> a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].fi >> a[i].se;
    for (int i = 0; i < n; i++)
        per += abs(a[i].fi - a[(i + 1) % n].fi) + abs(a[i].se - a[(i + 1) % n].se);
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        // third point
        ans = max(ans, a[i].fi + hxy - a[i].se);
        ans = max(ans, a[i].fi + lxy + a[i].se);

        // second point
        if (i < n - 1)
        {
            ans = max(ans, a[n - 1].fi + fh - a[i].se);
            ans = max(ans, a[n - 1].fi + fl + a[i].se);
            hxy = max(hxy, a[i].se + ly);
            lxy = max(lxy, -a[i].se + ly);
        }

        // first point
        if (i < n - 2)
        {
            ly = max(ly, -a[i].fi);
            fh = max(fh, a[i].se - a[i].fi);
            fl = max(fl, -a[i].se - a[i].fi);
            hxy = max(hxy, fh);
            lxy = max(lxy, fl);
        }
    }
    cout << 2 * ans << " ";
    for (int i = 4; i <= n; i++)
        cout << per << " ";
}