#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iomanip>
using namespace std;
char v[200005];
const int mod=998244353;
bool verif (long long val, double vall,long long i)
{
    double cr=vall,cntt=1;
    if(cr==val)
        return true;
    while(cr<val)
    {
        ++cntt;
        cr+=vall;
        if(cr==val && cntt<i-1)
            return true;
    }
    return false;
}
int main()
{
    long long t,n,i,j=0,k=0,s=1,okneg=0,cnt=0,mn=99999999999999LL,m,cur,pz,a,b,d,vl1=1,ok;
    cin>>t;
    while(t--)
    {
        long long x;
        cin>>x;
        ok=0;
        for(i=3;i<=360;++i)
        {
            double xx=(double)180/i;
            if(verif(x,xx,i))
            {
                cout<<i<<'\n';
                ok=1;
                break;
            }
        }
    }
}