#include <bits/stdc++.h>

using namespace std;


long long mod = 1000000007;
long long fct[400005],invfct[400005],inv[400005];
long long put2[400005];
long long lgput (long long a, long long exp)
{
    long long rz=1;
    while(exp)
        if(exp&1)
            exp^=1,rz=rz*1LL*a%mod;
        else
            exp>>=1,a=a*1LL*a%mod;
    return rz;
}
long long cmb (long long n, long long k)
{
    if(n<k || k<0 || n<0)
        return 0;
    return fct[n]*1LL*invfct[k]%mod*1LL*invfct[n-k]%mod;
}
void init ()
{
    inv[1]=fct[0]=fct[1]=invfct[0]=invfct[1]=put2[0]=1,put2[1]=2;
    for(long long i=2;i<=400000;++i)
        put2[i]=put2[i-1]*2LL%mod,inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}
int getbiti (int a)
{
    int cnt=0;
    while(a>0)
    {
        cnt+=(a&1);
        a>>=1;
    }
    return cnt;
}
long long v[20];
long long iv[20][20],pab[20][20];
long long strong[16390];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,i,j,m,q,k,n;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i];
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
            iv[i][j]=lgput(v[i]+v[j],mod-2);
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
            pab[i][j]=v[i]*1LL*iv[i][j]%mod;
    long long s=0;
    strong[1]=1;
    int maskall=(1<<n)-1;
    long long s1;
    long long vlc;
    vector<int>v1;
    vector<int>v2;
    for(int msk=1;msk<=maskall;++msk)
    {
        s1=0;
        for(int submsk=(msk-1)&msk;submsk>0;submsk=(submsk-1)&msk)
        {
            vlc=strong[submsk];
            v1.clear();
            v2.clear();
            for(i=1;i<=n;++i)
                if(submsk&(1<<(i-1)))
                    v1.push_back(i);
            for(j=1;j<=n;++j)
                if((msk&(1<<(j-1))) && !(submsk&(1<<(j-1))))
                    v2.push_back(j);
            for(i=0;i<v1.size();++i)
            for(j=0;j<v2.size();++j)
            {
                vlc=vlc*1LL*pab[v1[i]][v2[j]]%mod;
                //vlc=vlc*1LL*v[i]%mod;
                //vlc=vlc*1LL*iv[i][j]%mod;
            }
            s1=(s1+vlc);
            if(s1>mod)
                s1-=mod;
        }
        s1=(1-s1+mod);
        if(s1>mod)
            s1-=mod;
        strong[msk]=s1;
    }
    long long sc;
    for(int msk=1;msk<=maskall;++msk)
    {
        sc=getbiti(msk);
        for(i=1;i<=n;++i)
            for(j=1;j<=n;++j)
            {
                if((msk&(1<<(i-1))) && !(msk&(1<<(j-1))))
                {
                    sc=sc*1LL*v[i]%mod;
                    sc=sc*1LL*iv[i][j]%mod;
                }
            }
        sc=sc*1LL*strong[msk]%mod;
        s=(s+sc)%mod;
    }
    cout<<s;
    return 0;
}