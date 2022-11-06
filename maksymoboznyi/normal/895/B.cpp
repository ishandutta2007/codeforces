#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int N = 1e6+6;

int pf[N], n, k, a[N], x;

int get(int q)
{
    q = q - q%x;
    return q / x;
}

signed main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    int ans = 0;
    cin >> n >> x >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+n+1);
    pf[1] = 1;
    for (int i = 2; i <= n; i++)
        if (a[i] == a[i-1])
            pf[i] = pf[i-1];
        else
            pf[i] = i;
    for (int i = 1; i <= n; i++)
    {
        int l = pf[i], r = n;
        while (l < r - 1)
        {
            int m = (l+r)/2;
            if (get(a[m]) - get(a[i]-1) > k)
                r = m;
            else
                l = m;
        }
        if (get(a[r])- get(a[i]-1) == k)
            l = r;
        //c//out << a[r]/x - a[i]/x << endl;
        int rr = l;

        l = pf[i], r = n;
        while (l < r-1)
        {
            int m = (l+r)/2;
            if (get(a[m]) - get(a[i]-1) >= k)
                r = m;
            else
                l = m;
        }
        if (get(a[l]) - get(a[i]-1) == k)
            r = l;
        //cout << r << ' '<< rr << ' ' << i << ' ' << get(a[r])  << ' ' << k << endl;
        if (get(a[r])-get(a[i]-1) == k && get(a[rr]) - get(a[i]-1) == k && a[r] > a[i]-1 && a[rr] > a[i]-1)
        ans += rr-r+1;
    //    cout << ans << ' '<< r << ' '<< rr << endl;
    }
    cout << ans;
    return 0;
}