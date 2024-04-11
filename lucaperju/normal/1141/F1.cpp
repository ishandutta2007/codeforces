#include <bits/stdc++.h>
using namespace std;
int v[1503],sp[1503];
std::map< int,std::map<int,int> > d;
std::map< int,std::map<int,int> > aib;
int lsb (int x)
{
    return x&-x;
}
int sfa[1503],sfb[1503];
int main()
{
    long long h,n,i,j,m,mn=999999999,pz,s=0,y,k=0,mx=0,cnt=0,val=0,st,dr,nr0=0,nr1=0,put=1,idk=0,mxtot=-1,pzf,sf;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        sp[i]=sp[i-1]+v[i];
    }
    for(i=1;i<=n;++i)
    {
        for(j=i-1;j>=0;--j)
        {
            int sc=sp[i]-sp[j];
            mx=0;
            for(pz=j;pz>=1;pz-=lsb(pz))
                mx=max((int)mx,aib[pz][sc]);
            if(d[i][sc]>mx+1)
                continue;
            d[i][sc]=1+mx;
            if(mx+1>mxtot)
            {
                mxtot=mx+1;
                pzf=i;
                sf=sc;
            }
            for(pz=i;pz<=n;pz+=lsb(pz))
                aib[pz][sc]=max(aib[pz][sc],1+(int)mx);
        }
    }
    cout<<mxtot<<'\n';
    int cr=0;
    pz=pzf;
    int sc=sf;
    while(mxtot)
    {
        sfb[++cr]=pz;
        for(i=pz-1;i>=1;--i)
            if(sp[pz]-sp[i]==sc)
                break;
        sfa[cr]=i+1;
        --mxtot;
        if(mxtot==0)
            break;
        for(;i>=1;--i)
            if(d[i][sc]==mxtot)
            {
                pz=i;
                break;
            }
    }
    for(i=1;i<=cr;++i)
        cout<<sfa[i]<<' '<<sfb[i]<<'\n';
    return 0;
}