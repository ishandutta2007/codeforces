#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <iomanip>
using namespace std;
long double mi(long double a,long double b)
{
    if (a<b) return a; else return b;
}
int main()
{
    int n,w,i[200000],k,p;
    long double otv;
    cin>>n>>w;
    p=2*n;
    for (k=0;k<p;k++)
    cin>>i[k];
    sort(i,i+p);
    otv=mi(i[0],(long double)i[n]/2);
    otv*=3*n;
    cout<<setprecision(45)<<mi(otv,w);
    return 0;
}