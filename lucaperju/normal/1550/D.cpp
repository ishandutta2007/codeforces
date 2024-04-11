#include <bits/stdc++.h>

using namespace std;
const int mod=1000000007;
long long a[200005],b[200005];
long long fct[200005],invfct[200005],inv[200005];
long long cmb (long long n, long long k)
{
    if(k>n || k<0 || n<0)
        return 0;
    return fct[n]*1LL*invfct[k]%mod*1LL*invfct[n-k]%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int i,t,s;
    cin>>t;
    inv[1]=1;
    for(i=2;i<=200005;++i)
        inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod;
    fct[0]=fct[1]=invfct[0]=invfct[1]=1;
    for(i=2;i<=200005;++i)
    {
        fct[i]=i*1LL*fct[i-1]%mod;
        invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
    }
    while(t--)
    {
        long long n,l,r,j;
        cin>>n>>l>>r;
        for(i=1;i<=n;++i)
        {
            a[i]=i-l;
            b[i]=r-i;
        }
        if(a[1]<b[n])
        {
            for(i=1;i<=n;++i)
            {
                swap(a[i],b[n-i+1]);
            }
        }
        for(i=1;i<=n;++i)
            if(a[i]>=b[1])
                break;
        long long rz=0;
        for(j=1;j<=n;++j)
        {
            long long cc=b[j];
            while(a[i]>cc && i>1)
                --i;
            if(cc==0)
                continue;
            long long c=n/2;
            long long s=n-c;
            if(j<n && a[j+1]<cc)
                continue;
            if(i>1 && b[i-1]<cc)
                continue;
            rz=(rz+cmb(j-i+1,c-(i-1)))%mod;
            if(c!=s)
                swap(c,s);
            else
                continue;
            if(j<n && a[j+1]<cc)
                continue;
            if(i>1 && b[i-1]<cc)
                continue;
            rz=(rz+cmb(j-i+1,c-(i-1)))%mod;
        }
        long long cc=b[n]-1;
        while(a[i]>cc && i>1)
                --i;
        while(i>1)
        {
            while(a[i]>cc && i>1)
                --i;
            if(cc==0)
                break;
            long long c=n/2;
            long long s=n-c;
            if(i>1 && b[i-1]<cc)
                continue;
            rz=(rz+cmb(n-i+1,c-(i-1)))%mod;
            if(c!=s)
                swap(c,s);
            else
                continue;
            if(i>1 && b[i-1]<cc)
                continue;
            rz=(rz+cmb(n-i+1,c-(i-1)))%mod;
            --cc;
        }
        rz=(rz+cmb(n,n/2)*1LL*max(0LL,(min(a[1],b[n])-1))%mod)%mod;
        if(n/2 != n-n/2)
            rz=(rz+cmb(n,n-n/2)*1LL*max(0LL,(min(a[1],b[n])-1))%mod)%mod;
        cout<<rz<<'\n';
    }
    return 0;
}