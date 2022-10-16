#include <bits/stdc++.h>

using namespace std;

/*
const long long mod = 1000000007;

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
long long fct[200005],invfct[200005],inv[200005];
long long put2[200005];
long long cmb (long long n, long long k)
{
    if(n<k || k<0 || n<0)
        return 0;
    return fct[n]*1LL*invfct[k]%mod*1LL*invfct[n-k]%mod;
}
void init ()
{
    inv[1]=fct[0]=fct[1]=invfct[0]=invfct[1]=put2[0]=1,put2[1]=2;
    for(long long i=2;i<=200000;++i)
        put2[i]=put2[i-1]*2LL%mod,inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}
*/
int a[6],b[6];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,q,i,k,m,d,j=0,n,p,z;
    //cin>>t;
    t=1;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>a[i]>>b[i];
        long double s=0;
        for(int val=1;val<=10000;++val)
        {
            for(i=1;i<=n;++i)
            {
                for(j=i+1;j<=n;++j)
                {
                    long double pc=1;
                    for(k=1;k<i;++k)
                    {
                        if(a[k]<val)
                            pc=pc*1.0*((min(b[k]+1,val)-a[k])/(b[k]+1.0-a[k]));
                        else
                            pc=0.0;
                    }
                    if(val<a[i] || b[i]<val)
                        pc=0.0;
                    else
                        pc=pc*1.0/(b[i]+1.0-a[i]);
                    for(k=i+1;k<j;++k)
                    {
                        if(a[k]<=val)
                            pc=pc*1.0*((min(b[k]+1.0,val+1.0)-a[k])/(b[k]+1.0-a[k]));
                        else
                            pc=0.0;
                    }
                    if(b[j]<=val)
                        pc=0.0;
                    else
                        pc=pc*1.0*((b[j]-max(a[j]-1,val))/(b[j]+1.0-a[j]));
                    for(k=j+1;k<=n;++k)
                    {
                        if(a[k]<=val)
                            pc=pc*1.0*((min(b[k]+1.0,val+1.0)-a[k])/(b[k]+1.0-a[k]));
                        else
                            pc=0.0;
                    }
                    s+=pc*1.0*val;
                }
            }
            ///----------------------------
            for(i=1;i<=n;++i)
            {
                for(j=i+1;j<=n;++j)
                {
                    long double pc=1;
                    for(k=1;k<i;++k)
                    {
                        if(a[k]<val)
                            pc=pc*1.0*((min(b[k]+1,val)-a[k])/(b[k]+1.0-a[k]));
                        else
                            pc=0.0;
                    }
                    if(b[i]<=val)
                        pc=0.0;
                    else
                        pc=pc*1.0*((b[i]-max(a[i]-1,val))/(b[i]+1.0-a[i]));
                    for(k=i+1;k<j;++k)
                    {
                        if(a[k]<val)
                            pc=pc*1.0*((min(b[k]+1,val)-a[k])/(b[k]+1.0-a[k]));
                        else
                            pc=0.0;
                    }
                    if(val<a[j] || b[j]<val)
                        pc=0.0;
                    else
                        pc=pc*1.0/(b[j]+1.0-a[j]);
                    for(k=j+1;k<=n;++k)
                    {
                        if(a[k]<=val)
                            pc=pc*1.0*((min(b[k]+1,val+1)-a[k])/(b[k]+1.0-a[k]));
                        else
                            pc=0.0;
                    }
                    s+=pc*1.0*val;
                }
            }
            ///-----------------------
            for(i=1;i<=n;++i)
            {
                for(j=i+1;j<=n;++j)
                {
                    long double pc=1;
                    for(k=1;k<i;++k)
                    {
                        if(a[k]<val)
                            pc=pc*1.0*((min(b[k]+1,val)-a[k])/(b[k]+1.0-a[k]));
                        else
                            pc=0.0;
                    }
                    if(val<a[i] || b[i]<val)
                        pc=0.0;
                    else
                        pc=pc*1.0/(b[i]+1.0-a[i]);
                    for(k=i+1;k<j;++k)
                    {
                        if(a[k]<val)
                            pc=pc*1.0*((min(b[k]+1,val)-a[k])/(b[k]+1.0-a[k]));
                        else
                            pc=0.0;
                    }
                    if(val<a[j] || b[j]<val)
                        pc=0.0;
                    else
                        pc=pc*1.0/(b[j]+1.0-a[j]);
                    for(k=j+1;k<=n;++k)
                    {
                        if(a[k]<=val)
                            pc=pc*1.0*((min(b[k]+1.0,val+1.0)-a[k])/(b[k]+1.0-a[k]));
                        else
                            pc=0.0;
                    }
                    s+=pc*1.0*val;
                }
            }
        }
        cout<<fixed<<setprecision(9)<<s;
    }
    return 0;
}