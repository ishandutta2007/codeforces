#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define double long double
const int maxn = 1e5 + 20;
double charge , a[maxn] , p[maxn] , p1[maxn];
int n;
bool check(double x)
{
    double y = 0;
    for(int i = 0; i < n; i++)
    {
        p1[i] = p[i] - x * a[i];
        if(p1[i] < 0)
        {
            y -= p1[i];
        }
    }
    if(y / charge <= x)
        return 1;
    return 0;
}
double bs(double l , double r)
{
    if(r - l < 1e-8)
    {
        if(check(l) && !check(r))
            return l;
        return r;
    }
    double mid = (r + l) / 2;
    if(check(mid))
        return bs(mid , r);
    else
        return bs(l , mid);
}
int main()
{
    cin >> n >> charge;
    for(int i = 0; i < n; i++)
        cin >> a[i] >> p[i];
    if(check(1e12 + 1))
    {
        cout << -1;
        return 0;
    }
    cout << fixed << setprecision(20);
    cout << bs(0 , 1e12);
}