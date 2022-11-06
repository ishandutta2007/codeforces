#include <bits/stdc++.h>
#define pb push_back
using namespace std;
struct cell
{
    double x, v;
};
cell x[100000];
int n;
double ans;
bool cmp(cell a, cell b)
{
    return a.x < b.x;
}

bool check(double t)
{
    double ml = -10000000000, mr = 10000000000;
    for (int i = 0; i < n; i++)
    {
        ml = max(x[i].x - t*x[i].v, ml);
        mr = min(x[i].x + t*x[i].v, mr);
    }
    if (mr - ml > 0.0000000001)
        return true;
    return false;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i].x;
    for (int i = 0; i < n; i++)
        cin >> x[i].v;
    sort(x, x + n, cmp);
    //cout << x[0].x << ' ' << x[0].v << endl;
    double l= 0 , r = 1000000000;
    for (int i = 0; i < 500; i++)
    {
        double m = (r+l) / 2;
        if (check(m))
            r = m;
        else
            l = m;
      //      cout << l << ' ' << r << endl;
    }
    cout << fixed << setprecision(10) << r;
    return 0;
}