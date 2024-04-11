#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

ll n, a[100005], b[100005];
struct cell
{
    ll kol, val;
};
cell minl[100005], minr[100005];
vector<ll> v1, v2;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i]  = a[i];
    }
    sort(b+1, b+n+1);
    minl[1].kol = 1;
    minl[1].val = a[1];
    for (int i = 2; i <= n; i++)
        if (a[i] < minl[i-1].val)
        {
            minl[i].val = a[i];
            minl[i].kol = 1;
        }else
            if (a[i] == minl[i-1].val)
            {
                minl[i].kol = minl[i-1].kol + 1;
                minl[i].val = minl[i-1].val;
            }
            else
            {
                minl[i].kol = minl[i-1].kol;
                minl[i].val = minl[i-1].val;
            }

    minr[n].kol = 1;
    minr[n].val = a[n];
    for (int i = n-1; i >= 1; i--)
        if (a[i] < minr[i+1].val)
        {
            minr[i].val = a[i];
            minr[i].kol = 1;
        }else
            if (a[i] == minr[i+1].val)
            {
                minr[i].kol = minr[i+1].kol + 1;
                minr[i].val = minr[i+1].val;
            }
            else
            {
                minr[i].kol = minr[i+1].kol;
                minr[i].val = minr[i+1].val;
            }
    v1.pb(b[1]);
    v1.pb(b[2]);
    v1.pb(b[3]);
    ll ans = 0;
    for (int i = 2; i < n; i++)
    {
        v2.clear();
        v2.pb(minl[i-1].val);
        v2.pb(minr[i+1].val);
        v2.pb(a[i]);
        sort(v2.begin(), v2.end());
        if (v1 == v2)
            ans += minl[i-1].kol*minr[i+1].kol;
    }
    cout << ans << endl;
    return 0;
}