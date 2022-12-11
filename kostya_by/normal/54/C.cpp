#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

long double pos[1111], f[1111][1111];
long long l, r, ll, rr, val;
vector< pair<long long, long long> > intervals;
int n, m, k;

int main()
{
    //freopen("in.txt", "r", stdin);
   // freopen("out.txt", "w", stdout);
    cin >> n;
    ll = 1;
    rr = 1;
    while (rr <= 1e18)
    {
        intervals.push_back( make_pair(ll, rr) );
        ll *= 10;
        rr *= 10;
        rr += 9;
    }
    intervals.push_back( make_pair(ll, rr) );
    for (int i = 1; i <= n; i++)
    {
        cin >> l >> r;
        val = 0;
        for (int j = 0; j < intervals.size(); j++)
        {
            ll = max(l, intervals[j].first);
            rr = min(r, intervals[j].second);
           // cout << ll << " " << rr << endl;
            if (ll > rr) continue;
            val += rr - ll + 1;
        }
      //  cout << val << endl;
        pos[i] = 1.0 * val / (r - l + 1);
    }
    cin >> k;
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= n; j++)
        {
            f[i][j] = f[i - 1][j] * (1 - pos[i]);
            if (j == 0) continue;
            f[i][j] += f[i - 1][j - 1] * pos[i];
        }
    long double ans = 0;
    for (int i = 0; i <= n; i++)
    {
        if (k * n <= 100 * i) ans += f[n][i];
    }
    cout << fixed << setprecision(10) << ans;
    return 0;
}