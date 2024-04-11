#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iomanip>
using namespace std;
long long rez[200005];
long long vall (long long n, long long pas)
{
    long long s=n/pas;
    long long cat=s-1LL;
    cat=cat*1LL*(cat+1LL);
    cat/=2LL;
    cat=cat*1LL*pas;
    s+=cat;
    return s;
}
int main()
{
    long long n,t,i,j=0,k=0,s1=0,s2=0,okneg=0,cnt=0,mx=-99999999999999LL,m,cur=0,xcr,ycr,c,a,b,vl1=1,ok=0,sus=1,jos=1;
    cin>>n;
    a=n;
    for(i=1;i*i<=n;++i)
    {
        if(n%i==0)
        {
            rez[++k]=vall(n,i);
            if(n!=i*1LL*i)
                rez[++k]=vall(n,n/i);
        }
    }
    sort(rez+1,rez+k+1);
    for(i=1;i<=k;++i)
        cout<<rez[i]<<" ";
}