#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
double a,b,c,d,L,R=1e9,mid;
int main()
{
    cin>>a>>b>>c>>d;
    for(int Tms=1;Tms<=100;Tms++)
    {
        double Min1,Max1,Min2,Max2;
        Min1=1e20,Max1=-1e20,Min2=1e20,Max2=-1e20;
        mid=(L+R)/2;
        Min1=min(Min1,(a-mid)*(d-mid));
        Min1=min(Min1,(a-mid)*(d+mid));
        Min1=min(Min1,(a+mid)*(d-mid));
        Min1=min(Min1,(a+mid)*(d+mid));
        Max1=max(Max1,(a-mid)*(d-mid));
        Max1=max(Max1,(a-mid)*(d+mid));
        Max1=max(Max1,(a+mid)*(d-mid));
        Max1=max(Max1,(a+mid)*(d+mid));
        Min2=min(Min2,(b-mid)*(c-mid));
        Min2=min(Min2,(b-mid)*(c+mid));
        Min2=min(Min2,(b+mid)*(c-mid));
        Min2=min(Min2,(b+mid)*(c+mid));
        Max2=max(Max2,(b-mid)*(c-mid));
        Max2=max(Max2,(b-mid)*(c+mid));
        Max2=max(Max2,(b+mid)*(c-mid));
        Max2=max(Max2,(b+mid)*(c+mid));
        if(Min1>Min2) swap(Min1,Min2),swap(Max1,Max2);
        if(Min2>Max1) L=mid;
        else R=mid;
    }
    printf("%.016lf\n",L);
    return 0;
}