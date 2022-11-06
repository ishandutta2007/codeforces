#include <iostream>

using namespace std;

int main()
{
    int n,i,k,w[200000],h[200000],sumw=0,maxh=0,kol=0,maxh2=0,ma;
    long long r,t;
    cin>>n;
    for (k=0;k<n;k++)
    {
        cin>>w[k]>>h[k];
        sumw+=w[k];
        maxh=max(maxh,h[k]);
    }
    for (k=0;k<n;k++)
    kol+=h[k]/maxh;
    if (kol==1)
    for (k=0;k<n;k++)
    if (h[k]>maxh2&&h[k]<maxh) maxh2=h[k];
    if (kol!=1)
    for (k=0;k<n;k++)
    {
        r=maxh;
        t=sumw-w[k];
        cout<<r*t<<' ';
    }
    else
    for (k=0;k<n;k++)
    {
        if (h[k]!=maxh) ma=maxh; else ma=maxh2;
        r=ma;
        t=sumw-w[k];
        cout<<r*t<<' ';
    }
    return 0;
}