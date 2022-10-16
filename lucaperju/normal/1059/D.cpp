#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
long double a[100005],b[100005];
int n;
bool verif (long double val)
{
    long double dr=1000000000000;
    long double st=-dr;
    for(int i=1;i<=n;++i)
    {
        long double x=a[i],y=b[i];
        if(abs(val-y)>val)
            return false;
        long double cur=abs((y-val));
        long double cat =sqrt(val-cur)*sqrt(val+cur);
        dr=min(dr,x+cat);
        st=max(st,x-cat);
    }
    if(st<=dr)
        return true;
    return false;
}
int main()
{
    int i,j;
    cin>>n;
    long double k=0.0000000001,pas=1LL<<55LL;
    for(i=1;i<=n;++i)
    {
        cin>>a[i]>>b[i];
        if(b[i]<0 && b[i-1]>0 || b[i]>0 && b[i-1]<0)
        {
            cout<<-1;
            return 0;
        }
    }
    for(i=1;i<=n;++i)
        if(b[i]<0)
            b[i]=-b[i];
    for(i=1;i<=n;++i)
        k=max(k,(long double)b[i]/2);
    while(pas>=0.0000000001)
    {
        if(!verif(k+pas))
            k+=pas;
        pas/=2LL;
    }
 //   k+=0.0000001;
    cout<<setprecision(7)<<fixed<<k;
}