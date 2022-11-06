#include <bits/stdc++.h>
using namespace std;
double ans=-100000000;
int main()
{
    int n;
    double a, d;
    double v, t;
    scanf("%d%lf%lf", &n, &a, &d);
    for(int i = 0; i < n; i ++)
    {
        scanf("%lf%lf", &t, &v);
        if((v * v) / (2 * a) >= d) t += sqrt((2 * d) / a);
        else t += (v / a) + (d - (v * v) / (2 * a)) / v;
        if(ans > t) t = ans;
        printf("%.10lf\n",t);
        ans = t;
    }
    return 0;
}