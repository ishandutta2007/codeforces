#include <iostream>
#include <algorithm>
using namespace std;
int n,v[200005];
bool cautbin (long long val)
{
    long long pas=1LL<<17,k=0;
    while(pas)
    {
        if(k+pas<=n && v[k+pas]<=val)
            k+=pas;
        pas>>=1;
    }
    if(v[k]==val)
        return true;
    return false;
}
int main()
{
    long long i,put=1,mx=1,a1,a2;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
    }
    sort(v+1,v+n+1);
    for(put=1;put<=1LL<<30;put=put*1LL*2)
    {
        for(i=1;i<=n;++i)
        {
            if(cautbin(v[i]+put))
            {
                mx=2;
                a1=v[i];
                a2=v[i]+put;
                if(cautbin(v[i]+put*1LL*2)){
                    cout<<3<<'\n'<<v[i]<<' '<<v[i]+put<<' '<<v[i]+put*1LL*2;
                    mx=3;
                    put=1LL<<31;
                    break;
                }
            }
        }
    }
    if(mx==2)
        cout<<2<<'\n'<<a1<<' '<<a2;
    if(mx==1)
        cout<<1<<'\n'<<v[1];
    return 0;
}