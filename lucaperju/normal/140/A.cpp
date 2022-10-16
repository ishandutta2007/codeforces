#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    double n,r1,r2;
    cin>>n>>r1>>r2;
    if(n==1)
    {
        if(r1>=r2)
            cout<<"YES";
        else
            cout<<"NO";
        return 0;
    }
    else if(n==2)
    {
        if(r1>=2*r2)
            cout<<"YES";
        else
            cout<<"NO";
        return 0;
    }
    double s=r2*2.0;
    double apothem=s/(2.0*tan ( 180/n * PI / 180.0 ));
    double val=sqrt(apothem*apothem+r2*r2);
    if(val+r2-0.000001<=r1)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}