#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()
typedef long long lld;

lld A, B, C, D;

void calc(double s1, double e1, double s2, double e2, double &s3, double &e3)
{
    vector <double> arr = {s1*s2, s1*e2, e1*s2, e1*e2};
    sort(all(arr));
    s3 = arr[0]; e3 = arr[3];
}

int main()
{
    double s = 0, e = 1e10;
    cin >> A >> B >> C >> D;
    for (int it=10000;it--;){
        double m = (s+e) / 2;
        double sp, ep, sq, eq;
        calc(A-m, A+m, D-m, D+m, sp, ep);
        calc(B-m, B+m, C-m, C+m, sq, eq);
//      printf("%.9lf %.9lf\n%.9lf %.9lf\n", sp, ep, sq, eq);
        if (sp > eq || sq > ep) s = m;
        else e = m;
    }
    printf("%.13lf\n", (s+e) / 2);
}