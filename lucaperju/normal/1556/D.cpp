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
long long v[10003];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,i,j,m,q,k,n;
    cin>>n>>k;
    long long a12,a23,a13,o12,o23,o13;
    cout<<"and 1 2\n";
    cout.flush();
    cin>>a12;
    cout<<"and 1 3\n";
    cout.flush();
    cin>>a13;
    cout<<"and 2 3\n";
    cout.flush();
    cin>>a23;
    cout<<"or 1 2\n";
    cout.flush();
    cin>>o12;
    cout<<"or 1 3\n";
    cout.flush();
    cin>>o13;
    cout<<"or 2 3\n";
    cout.flush();
    cin>>o23;
    for(i=0;(1LL<<i)<=1000000000;++i)
    {
        long long bit=(1<<i);
        if(a12&a13&a23&bit)
        {
            v[1]|=bit;
            v[2]|=bit;
            v[3]|=bit;
            continue;
        }
        if((a12|a13|a23)&bit)
        {
            if(a12&bit)
            {
                v[1]|=bit;
                v[2]|=bit;
                continue;
            }
            if(a13&bit)
            {
                v[1]|=bit;
                v[3]|=bit;
                continue;
            }
            if(a23&bit)
            {
                v[2]|=bit;
                v[3]|=bit;
                continue;
            }
            assert(0);
        }
        if((o12|o23|o13)&bit)
        {
            if(o12&o23&bit)
                v[2]|=bit;
            else if(o12&o13&bit)
                v[1]|=bit;
            else
                v[3]|=bit;
        }
    }
    for(i=4;i<=n;++i)
    {
        cout<<"and 1 "<<i<<'\n';
        cout.flush();
        int a,o;
        cin>>a;
        cout<<"or 1 "<<i<<'\n';
        cout.flush();
        cin>>o;
        v[i]=(v[1]^a^o);
    }
    sort(v+1,v+n+1);
    cout<<"finish "<<v[k]<<'\n';
    cout.flush();
    return 0;
}