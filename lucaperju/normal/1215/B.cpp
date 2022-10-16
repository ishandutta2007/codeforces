#include <bits/stdc++.h>
using namespace std;
int v[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    long long n,i,j,m,k=0,t,s=0,rz=0;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        int a;
        cin>>a;
        if(a>0)
            v[i]=0;
        else
            v[i]=1;
    }
    long long nrp=1,nri=0;
    for(i=1;i<=n;++i)
    {
        s+=v[i];
        if(s&1)
            rz+=nrp,++nri;
        else
            rz+=nri,++nrp;
    }
    cout<<rz<<' '<<n*1LL*(n+1LL)/2LL-rz;
    return 0;
}