#include <bits/stdc++.h>
using namespace std;
int v[200005],st[200005],dr[200005],pz[200005],rz[200005],n;
void drpt (int pzi, int pz, int k, int vl)
{
    if(pz!=pzi)
        st[pz]=pzi;
    int i=pz;
    if(i==n)
    {
        if(!rz[pz])
            rz[pz]=vl;
        return;
    }
    if(rz[pz])
    {
        drpt(pzi,dr[i],k,vl);
        dr[i]=dr[dr[i]];
        return;
    }
    else
    {
        rz[pz]=vl;
        --k;
        if(k)
        {
            drpt(pzi,dr[i],k,vl);
            dr[i]=dr[dr[i]];
            return;
        }
        return;
    }
}
void stng (int pzi, int pz, int k, int vl)
{
    if(pz!=pzi)
        dr[pz]=pzi;
    int i=pz;
    if(i==1)
    {
        if(!rz[pz])
            rz[pz]=vl;
        return;
    }
    if(rz[pz])
    {
        stng(pzi,st[i],k,vl);
        st[i]=st[st[i]];
        return;
    }
    else
    {
        rz[pz]=vl;
        --k;
        if(k)
        {
            stng(pzi,st[i],k,vl);
            st[i]=st[st[i]];
            return;
        }
        return;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    long long p,add=1,t,h,i,j,mn=99999,k=0,mx=-999999999999LL,tot,m,obj,cnt=0,cnti=0,s=0,nri=0,b2,a3,b3;
    int a,b;
    cin>>n>>k;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        st[i]=i-1;
        dr[i]=i+1;
        pz[v[i]]=i;
    }
    dr[n]=n;
    st[1]=1;
    int jc=2;
    for(i=n;i>=1;--i)
    {
        if(!rz[pz[i]])
        {
            jc=3-jc;
            drpt(pz[i],pz[i],k+1,jc);
            stng(pz[i],pz[i],k,jc);
        }
    }
    for(i=1;i<=n;++i)
        cout<<rz[i];
    return 0;
}