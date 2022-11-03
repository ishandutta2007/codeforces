#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,x[1005],y[1005],v[1005];
    double d,c;
    cin>>a>>b;
    long long k;
    cin>>k;
    for(long long i=0;i<k;i++)
    {
        cin>>x[i]>>y[i]>>v[i];
        x[i]-=a;
        y[i]-=b;
        c=sqrt(x[i]*x[i]+y[i]*y[i])/v[i];
        if(i==0)
        d=c;
        if(c<d)
        d=c;
    }
    printf("%.17f", d);
}