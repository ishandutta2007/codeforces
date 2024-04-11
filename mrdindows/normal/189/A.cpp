#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
    int n,a,b,c,x,y,z;
    long k=0,s,smax=0;
    cin>>n;
    cin>>a>>b>>c;
    x=min(min(a,b),c);
    z=max(max(a,b),c);
    y=a+b+c-x-z;
    for (int i=0; i*z<=n;i++)
        for (int j=0; i*z+j*y<=n;j++)
            if ((n-i*z-j*y)%x==0)
            {
                k=(n-i*z-j*y)/x;
                s=i+j+k;
                if (s>smax) smax=s;
            }
            cout<<smax;
    return 0;
}