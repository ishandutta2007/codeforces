#include <bits/stdc++.h>
using namespace std;
int v[200003],mMst[200003],mMdr[200003],Mmst[200003],Mmdr[200003];
int aib[200003];
int lsb (int x)
{
    return x&-x;
}
void reset ()
{
    for(int i=1;i<=200000;++i)
        aib[i]=0;
}
void upd (int pz, int val)
{
    for(int i=pz;i<=200000;i+=lsb(i))
        aib[i]+=val;
}
int query (int pz)
{
    int rz=0;
    for(int i=pz;i>0;i-=lsb(i))
        rz+=aib[i];
    return rz;
}
int main()
{
    ios_base::sync_with_stdio(false);
    long long t,a,k,x,b,i,n;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i];
    /// <= - > la st:
    for(i=1;i<=n;++i)
    {
        mMst[i]=query(v[i]);
        upd(v[i],2);
        int pz=0;
        int pas=(1<<17);
        while(pas)
        {
            if(pz+pas<=200000 && aib[pz+pas]==0)
                pz+=pas;
            pas>>=1;
        }
        upd(pz+1,-1);
    }
    reset();
    for(i=n;i>=1;--i)
    {
        mMdr[i]=query(v[i]);
        upd(v[i],2);
        int pz=0;
        int pas=(1<<17);
        while(pas)
        {
            if(pz+pas<=200000 && aib[pz+pas]==0)
                pz+=pas;
            pas>>=1;
        }
        upd(pz+1,-1);
    }
    reset();
    for(i=1;i<=n;++i)
        v[i]=n+1-v[i];
    for(i=1;i<=n;++i)
    {
        Mmst[i]=query(v[i]);
        upd(v[i],2);
        int pz=0;
        int pas=(1<<17);
        while(pas)
        {
            if(pz+pas<=200000 && aib[pz+pas]==0)
                pz+=pas;
            pas>>=1;
        }
        upd(pz+1,-1);
    }
    reset();
    for(i=n;i>=1;--i)
    {
        Mmdr[i]=query(v[i]);
        upd(v[i],2);
        int pz=0;
        int pas=(1<<17);
        while(pas)
        {
            if(pz+pas<=200000 && aib[pz+pas]==0)
                pz+=pas;
            pas>>=1;
        }
        upd(pz+1,-1);
    }
    for(i=1;i<=n;++i)
    {
        int a=mMst[i]+mMdr[i];
        int rz=a/2;
        a=Mmst[i]+Mmdr[i];
        rz=max(rz,(a+1)/2);
        cout<<rz<<' ';
    }
    return 0;
}