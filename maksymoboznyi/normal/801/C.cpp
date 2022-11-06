#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define N 200000
using namespace std;
double a[N], b[N], p;
int n;
int main()
{
    cin >> n >> p;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    double l = 0, r = 1e19;
    for (int i = 0; i < 200; i++)
    {
        double m = (r+l)/2;
        double want = 0, can = p*m;
        for (int j = 0; j < n; j++)
        {
            can += b[j];
            want += a[j]*m;
        }
        double x = 0;
        for (int j = 0; j < n; j++)
        {
            x += max(double(0), (a[j]*m-b[j])/p);
           // cout << x << endl;
        }
       // cout << fixed << setprecision(7)<< x<<' ' << m << ' ' << l << ' ' << r << endl;
        if (x - m > 0.00000001)
            r = m;
        else
            l = m;
    }
    if (l - 1e18 >= 0.000000000000001)
        cout << -1;
    else
        cout << fixed << setprecision(7) << l;
    return 0;
}