#include <bits/stdc++.h>

using namespace std;

/*
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
*/
long long v[100003];
long long rmqmn[20][100003];
long long rmqmx[20][100003];
long long sp[100003];
long long lg[100003];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,i,j,m,q,k,n;
    cin>>n>>q;
    for(i=1;i<=n;++i)
        cin>>v[i];
    lg[1]=0;
    for(i=2;i<=n;++i)
        lg[i]=1+lg[i/2];
    for(i=1;i<=n;++i)
    {
        long long a;
        cin>>a;
        v[i]-=a;
        sp[i]=v[i]+sp[i-1];
        rmqmn[0][i]=rmqmx[0][i]=sp[i];
    }
    for(int put=1;put<=19;++put)
    {
        for(i=1;i<=n;++i)
        {
            rmqmn[put][i]=min(rmqmn[put-1][i],rmqmn[put-1][max(1LL,i-(1<<(put-1)))]);
            rmqmx[put][i]=max(rmqmx[put-1][i],rmqmx[put-1][max(1LL,i-(1<<(put-1)))]);
        }
    }
    while(q--)
    {
        long long a,b;
        cin>>a>>b;
        if(sp[b]-sp[a-1]!=0)
        {
            cout<<"-1\n";
            continue;
        }
        int l=(b-a+1);
        if(max(rmqmx[lg[l]][b],rmqmx[lg[l]][a+(1<<lg[l])-1])-sp[a-1]>0)
        {
            cout<<"-1\n";
            continue;
        }
        cout<<-(min(rmqmn[lg[l]][b],rmqmn[lg[l]][a+(1<<lg[l])-1])-sp[a-1])<<'\n';
    }
    return 0;
}