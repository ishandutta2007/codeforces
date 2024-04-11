#include <bits/stdc++.h>
using namespace std;
long long n;
long long aib[100005];
long long v[100005];
long long lsb (long long x)
{
    return x&-x;
}
long long query (long long pz)
{
    long long rz=0;
    for(long long i=pz;i>0;i-=lsb(i))
        rz+=aib[i];
    return rz;
}
void update (long long pz, long long val)
{
    for(long long i=pz;i<=n;i+=lsb(i))
        aib[i]+=val;
}
long long solve (long long ac, long long ab, long long cd, long long bd)
{
    return max((ac+ab)/2LL,ac+ab-(ac+ab)/2LL);
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,i,j,k;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        long long a;
        cin>>a;
        v[i]=a;
        update(i,a-v[i-1]);
    }
    long long ac=0,ab=0,cd=0,bd=0;
    ac=v[1];
    bd=v[n];
    for(i=1;i<n;++i)
    {
        if(v[i+1]>v[i])
            ab+=v[i+1]-v[i];
        else
            cd+=v[i+1]-v[i];
    }
    cin>>t;
    cout<<solve(ac,ab,cd,bd)<<'\n';
    while(t--)
    {
        long long x,y,z;
        cin>>x>>y>>z;
        if(x>1)
        {
            long long v1=query(x-1);
            long long v2=query(x);
            if(v2>v1)
                ab-=(v2-v1);
            else
                cd-=(v2-v1);
            v2+=z;
            if(v2>v1)
                ab+=(v2-v1);
            else
                cd+=(v2-v1);
        }
        if(y<n)
        {
            long long v1=query(y);
            long long v2=query(y+1);
            if(v2>v1)
                ab-=(v2-v1);
            else
                cd-=(v2-v1);
            v1+=z;
            if(v2>v1)
                ab+=(v2-v1);
            else
                cd+=(v2-v1);
        }
        update(x,z);
        update(y+1,-z);
        ac=query(1);
        bd=query(n);
        cout<<solve(ac,ab,cd,bd)<<'\n';
    }
    return 0;
}