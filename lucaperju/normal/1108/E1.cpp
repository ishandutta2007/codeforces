#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int v[305];
int a[305],b[305];
int smn[305];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie();cout.tie();
    long long n,k,i,j=0,cnt=0,s=0,pzs=1,psj=1,cur=0,pz,m,val,mx=-1,cntc,cntf;
    cin>>n>>m;
    for(i=1;i<=n;++i)
        cin>>v[i];
    for(i=1;i<=m;++i)
        cin>>a[i]>>b[i];
    for(k=1;k<=n;++k)
    {
        for(i=1;i<=n;++i)
            smn[i]=0;
        cntc=0;
        for(j=1;j<=m;++j)
        {
            if(a[j]>k || b[j]<k)
            {
                --smn[a[j]];
                ++smn[b[j]+1];
                ++cntc;
            }
        }
        int mn=999999999;
        for(i=1;i<=n;++i)
        {
            smn[i]+=smn[i-1];
            if(smn[i]+v[i]<mn)
                mn=smn[i]+v[i];
        }
        if(v[k]-mn>mx)
        {
            mx=v[k]-mn;
            pz=k;
            cntf=cntc;
        }
    }
    cout<<mx<<'\n'<<cntf<<'\n';
    for(j=1;j<=m;++j)
    {
        if(a[j]>pz || b[j]<pz)
        {
            cout<<j<<' ';
        }
    }
    return 0;
}