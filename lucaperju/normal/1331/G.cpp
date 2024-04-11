#include <bits/stdc++.h>

using namespace std;
const int mod=1000000007;
double rzf[15];
int va[15];
int main ()
{
    ios::sync_with_stdio (false);
    cin.tie (0); cout.tie (0);
    int i,j,n;
    for(i=1;i<=11;++i)
    {
        double a;
        cin>>a;
        double ca;
        if(a<0)
            ca=-a;
        else
            ca=a;
        double rz=sqrt(ca);
        rz+=(a*a*a*5);
        rzf[i]=rz;
        va[i]=a;
    }
    for(i=11;i>=1;--i)
    {
        if(rzf[i]<400)
            cout<<"f("<<va[i]<<") = "<<fixed<<setprecision(2)<<rzf[i]<<'\n';
        else
            cout<<"f("<<va[i]<<") = "<<"MAGNA NIMIS!"<<'\n';
    }
}