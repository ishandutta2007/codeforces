#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
    int x,y,x1,y1,n,l,k,be=2e9,su;
    double o[1000],f;
    cin>>n>>x>>y;
    for (l=0;l<n;l++)
    {
        cin>>x1>>y1;
        x1-=x;
        y1-=y;
        if (x1==0) o[l]=be; else o[l]=(double)y1/x1;
    }
    sort(o,o+n);
    f=o[0];
    su=1;
    for (l=1;l<n;l++)
    if (o[l]-f<1e-9&&o[l]-f>-1e-9) f=o[l]; else {f=o[l]; su++;}
    cout<<su;
    return 0;
}