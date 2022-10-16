#include <bits/stdc++.h>
using namespace std;
long long ciur[100005];
long long primes[100005];
long long ocp[100005],n,cntt;
void scoate (long long val)
{
    cout<<"B "<<val<<'\n';
    cout.flush();
    long long a;
    cin>>a;
    for(long long i=val;i<=n;i+=val)
    {
        if(!ocp[i])
        {
            --cntt;
            ocp[i]=1;
        }
    }
}
bool scoate2 (long long val)
{
    cout<<"B "<<val<<'\n';
    cout.flush();
    long long a;
    cin>>a;
    long long cntc=0;
    for(long long i=val;i<=n;i+=val)
    {
        if(!ocp[i])
        {
            --cntt;
            ++cntc;
            ocp[i]=1;
        }
    }
    if(cntc!=a)
        return true;
    return false;
}
bool verif ()
{
    cout<<"A "<<1<<'\n';
    cout.flush();
    long long a;
    cin>>a;
    if(a!=cntt)
        return true;
    return false;
}
bool exists (long long val)
{
    cout<<"A "<<val<<'\n';
    cout.flush();
    long long a;
    cin>>a;
    if(a)
        return true;
    return false;
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,i,j,k;
    cin>>n;
    ciur[1]=ciur[0]=1;
    for(i=2;i*i<=n;++i)
    {
        if(!ciur[i])
            for(j=i*i;j<=n;j+=i)
                ciur[j]=1;
    }
    j=0;
    for(i=1;i<=n;++i)
        if(!ciur[i])
            primes[++j]=i;
    cntt=n;
    long long rz=1;
    long long dr=j;
    long long st;
    while(dr>0)
    {
        st=max(1LL,dr-99);
        for(i=dr;i>=st;--i)
            scoate(primes[i]);
        if(verif())
        {
            for(i=st;i<=dr;++i)
            {
                if(exists(primes[i]))
                    rz=rz*primes[i];
            }
            dr=st-1;
            break;
        }
        dr=st-1;
    }
    for(i=dr;i>=1;--i)
    {
        if(scoate2(primes[i]))
            rz*=primes[i];
    }
    for(i=1;i<=j;++i)
    {
        if(rz%primes[i]==0)
        {
            while(rz*primes[i]<=n && exists(rz*primes[i]))
            {
                rz*=primes[i];
            }
        }
    }
    cout<<"C "<<rz<<'\n';
    cout.flush();
    return 0;
}