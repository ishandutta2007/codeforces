#include <bits/stdc++.h>

using namespace std;
const int mod=998244353;
struct ura
{
    int a,b;
}v[300005];
bool cmp1 (ura a, ura b)
{
    if(a.a<b.a)
        return true;
    if(a.a>b.a)
        return false;
    return a.b<b.b;
}
bool cmp2 (ura a, ura b)
{
    return a.b<b.b;
}
long long perm[300005];
int main()
{
    ios_base::sync_with_stdio(0);
    long long t,n,i,j,cnt=0,m,p,h,a,b,s=1,sc=1;
    cin>>n;
    p=1;
    for(i=1;i<=n;++i)
    {
        p=(p*1LL*i)%mod;
        perm[i]=p;
    }
    for(i=1;i<=n;++i)
        cin>>v[i].a>>v[i].b;
    sort(v+1,v+n+1,cmp2);
    for(i=1;i<=n;++i)
    {
        if(v[i].b!=v[i-1].b || i==1)
            cnt=1;
        else
            ++cnt;
        if(v[i].b!=v[i+1].b || i==n)
            s=(s*1LL*perm[cnt])%mod;
    }
    sort(v+1,v+n+1,cmp1);
    for(i=1;i<=n;++i)
    {
        if(v[i].a!=v[i-1].a || i==1)
            cnt=1;
        else
            ++cnt;
        if(v[i].a!=v[i+1].a || i==n)
            sc=(sc*1LL*perm[cnt])%mod;
    }
    s=(s+sc)%mod;
    for(i=2;i<=n;++i)
    {
        if(v[i].b<v[i-1].b)
        {
            cout<<(perm[n]-s+mod)%mod;
            return 0;
        }
    }
    sc=1;
    for(i=1;i<=n;++i)
    {
        if(v[i].b!=v[i-1].b || i==1 || v[i].a!=v[i-1].a)
            cnt=1;
        else
            ++cnt;
        if(v[i].b!=v[i+1].b || i==n || v[i].a!=v[i+1].a)
            sc=(sc*1LL*perm[cnt])%mod;
    }
    s=(s-sc+mod)%mod;
    cout<<(perm[n]-s+mod)%mod;
    return 0;
}