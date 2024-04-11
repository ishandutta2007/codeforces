#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
long long n, mm;
int main()
{
    cin >> n>> mm;
    if (mm >= n)
    {
        cout << n;
        return 0;
    }
    ll l = 0, r = n;
    while (l < r - 1)
    {
        ll m = (r+l) / 2;
        if ((1+m) < ((n-mm)*2-1)/m + 1)
            l = m;
        else
            r = m;
    }
    cout << min(mm + r, n);
    return 0;
}