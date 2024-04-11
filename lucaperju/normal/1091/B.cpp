#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iomanip>
using namespace std;
int main()
{
    long long n,t,i,j=0,k=0,s1=0,s2=0,okneg=0,cnt=0,mx=-99999999999999LL,m,cur=0,xcr,ycr,c,a,b,vl1=1,ok=0,sus=1,jos=1;
    cin>>n;
    for(i=1;i<=2*n;++i)
    {
        long long x,y;
        cin>>x>>y;
        s1+=x;
        s2+=y;
    }
    s1/=n;
    s2/=n;
    cout<<s1<<' '<<s2<<' ';
}