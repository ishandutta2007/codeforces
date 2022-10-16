#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
/// (p)cccccc cp cp cp cp cp ppppppp(c)
///           ^
///           i
///
/// ppppppp ccccccc
long long v[200003],n;
long long sp[200003];
long long sp2[200003];
int solve (int l, int r, long long s)
{
    long long rz=0;
    if(r<l)
    {
        return 0;
    }
    if(l==r)
    {
        if(s+v[l]>0 && l!=2)
            ++rz;
        if(s-v[l]>0 && r!=n)
            ++rz;
        return rz;
    }
    if(r!=n && s-sp[r]+sp[l-1]>0)
        ++rz;
    for(int i=l;i<r;++i)
    {
        int ci,pas=1<<17,k=0;
        while(pas)
        {
            if(i+(k+pas-1)*2LL<r)
            {
                ci=i+(k+pas-1)*2LL;
                if(s-(sp2[ci]-sp2[i]+v[i])*2LL+sp[r]-sp[i-1]>0)
                    k+=pas;
            }
            pas>>=1;
        }
        if(i==l && s+sp[r]-sp[i-1]>0)
            ++k;
        if(i==2 && l==2)
        {
            --k;
        }
        rz+=max(k,0);
        if(rz>=mod)
            rz-=mod;
        s-=v[i];
    }
    return rz;
}
int main()
{
    ios_base::sync_with_stdio(false);
    long long i,j,k,cnt,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        for(i=1;i<=n;++i)
        {
            sp[i]=v[i]+sp[i-1];
            if(i>2)
                sp2[i]=v[i]+sp2[i-2];
            else
                sp2[i]=v[i];
        }
        long long ans=0;
        for(i=2;i<=n-2;++i)
        {
            if(sp[i]>sp[n]-sp[i])
                ++ans;
        }
        ans=ans+solve(1,n,0);
        if(ans>=mod)
            ans-=mod;
        ans=ans+solve(2,n,v[1]);
        if(ans>=mod)
            ans-=mod;
        ans=ans+solve(1,n-1,-v[n]);
        if(ans>=mod)
            ans-=mod;
        ans=ans+solve(2,n-1,v[1]-v[n]);
        if(ans>=mod)
            ans-=mod;
        cout<<ans<<'\n';
    }
    return 0;
}