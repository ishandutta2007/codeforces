#include <bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int cntm,cntM;
void bullshit(int st, int dr, int pz)
{
    if(st>=dr)
        return;
    int mid=(st+dr)/2;
    if(pz>=mid)
    {
        if(pz>mid)
            ++cntm;
        bullshit(mid+1,dr,pz);
    }
    else
    {
        ++cntM;
        bullshit(st,mid,pz);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int s=0,n,i,t,j;
    long long rz=1,k,pz;
    cin>>n>>k>>pz;
    bullshit(0,n,pz);
    for(i=0;i<cntm;++i)
        rz=(rz*1LL*(k-1-i))%mod;
    for(i=0;i<cntM;++i)
        rz=(rz*1LL*(n-k-i))%mod;
    for(i=n-cntm-cntM-1;i>=1;--i)
        rz=(rz*1LL*i)%mod;
    cout<<rz<<'\n';
    return 0;
}