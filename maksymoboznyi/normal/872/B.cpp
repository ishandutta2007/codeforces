#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e5+5;
ll n, k, a[N], minpref[N], minsuf[N];
int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (k == 1)
    {
        int mi = 1;
        for (int i = 1; i <= n; i++)
            if (a[i] < a[mi])
                mi = i;
        cout << a[mi];
        return 0;
    }
    int pma = 1;
    for (int i = 1; i <= n; i++)
        if (a[pma] < a[i])
            pma = i;
    if (k == 2)
        if (a[1] == a[pma] || a[n] == a[pma])
        {
            cout << a[pma];
            return 0;
        }else
        {
            minsuf[n] = a[n];
            minpref[1] = a[1];
            for (int i = 2; i <= n; i++)
                minpref[i] = min(minpref[i-1], a[i]);
            for (int i = n-1; i > 0; i--)
                minsuf[i] = min(minsuf[i+1], a[i]);
            ll an = -2e9;
            for (int i = 1; i < n; i++)
                an = max(an, max(minpref[i], minsuf[i+1]));
            cout << an;
            return 0;
        }
    cout << a[pma];
    return 0;
}