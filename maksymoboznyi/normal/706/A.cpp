#include <bits/stdc++.h>

using namespace std;
double ma (double a, double b)
{
    if ((a-b)>0.000000001)
        return b;
    else
        return a;
}
double len(double x1, double y1, double x2, double y2)
{
    return(sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
}
double rez[10001],x[10001],y[1001],v[1001];
double a, b;
int main()
{
    cin >> a>>b;
    int n;
    cin >> n;
    double k = 9999999999;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i]>>y[i]>>v[i];
        rez[i] = len(a,b,x[i],y[i])/v[i];
        k = ma(k, rez[i]);
    }
    cout.precision(10);
    cout << k;
    return 0;
}