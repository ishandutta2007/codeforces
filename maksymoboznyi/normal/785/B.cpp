#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int n;
int main()
{
    int rmin1 = 2000000000, rmin2 = 2000000000, lmax1 = -1, lmax2 = -1;
    cin >> n;
    int a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        rmin1 = min(b, rmin1);
        lmax1 = max(a, lmax1);
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        rmin2 = min(rmin2, b);
        lmax2 = max(lmax2, a);
    }
    int p = max(lmax2 - rmin1, lmax1 - rmin2);
    if (p <= 0)
        cout << 0;
    else
        cout << p;
    return 0;
}