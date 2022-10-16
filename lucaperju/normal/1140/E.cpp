#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long v[200005],cr[200005],d[200005][2];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t,h,n,i,j,m,mn=999999999,pz,s=0,y,k=0,mx=0,cnt=1,val=0,st,dr,nr0=0,nr1=0,put=1,idk=0,mxtot=-1,pzf,sf;
    cin>>n>>k;
    for(i=1;i<=n;++i)
        cin>>v[i];
    j=0;
    for(i=1;i<=n;i+=2)
        cr[++j]=v[i];
    d[0][0]=0;
    d[0][1]=1;
    d[1][0]=k-1;
    d[1][1]=k-2;
    for(i=2;i<=n;++i)
    {
        d[i][0]=(d[i-1][1]*1LL*(k-1))%mod;
        d[i][1]=((d[i-1][1]*1LL*(k-2))%mod+d[i-1][0]%mod)%mod;
    }
    int oktot=0;
    long long vlc=1;
    if(cr[1]==-1)
    {
        for(i=1;i<=j;++i)
            if(cr[i]!=-1)
                break;
        if(i==j+1)
        {
            vlc=k;
            for(i=1;i<j;++i)
                vlc=(vlc*1LL*(k-1))%mod;
            oktot=1;
        }
        else
        {
            st=i;
            while(i>1)
            {
                vlc=(vlc*1LL*(k-1))%mod;
                --i;
            }
        }
    }
    else
        st=1;
    if(!oktot)
    {
        for(i=st+1;i<=j;++i)
        {
            if(cr[i]!=-1)
            {
                vlc=(vlc*1LL*d[i-st-1][(cr[i]!=cr[st])])%mod;
                st=i;
            }
        }
        for(i=st+1;i<=j;++i)
            vlc=(vlc*1LL*(k-1))%mod;
    }
    oktot=0; /// ----------------------------------------------
    j=0;
    for(i=2;i<=n;i+=2)
        cr[++j]=v[i];
    if(cr[1]==-1)
    {
        for(i=1;i<=j;++i)
            if(cr[i]!=-1)
                break;
        if(i==j+1)
        {
            vlc=(vlc*1LL*k)%mod;
            for(i=1;i<j;++i)
                vlc=(vlc*1LL*(k-1))%mod;
            oktot=1;
        }
        else
        {
            st=i;
            while(i>1)
            {
                vlc=(vlc*1LL*(k-1))%mod;
                --i;
            }
        }
    }
    else
        st=1;
    if(!oktot)
    {
        for(i=st+1;i<=j;++i)
        {
            if(cr[i]!=-1)
            {
                vlc=(vlc*1LL*d[i-st-1][(cr[i]!=cr[st])])%mod;
                st=i;
            }
        }
        for(i=st+1;i<=j;++i)
            vlc=(vlc*1LL*(k-1))%mod;
    }
    cout<<vlc;
    return 0;
}