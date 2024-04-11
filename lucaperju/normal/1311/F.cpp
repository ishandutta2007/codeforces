#include <bits/stdc++.h>

using namespace std;
struct ura
{
    long long v,x;
}v[200005];
map<long long,long long> mp;
long long aib[200005];
long long aib1[200005];
bool cmp1 (ura a, ura b)
{
    return a.v<b.v;
}
bool cmp2 (ura a, ura b)
{
    return a.x<b.x;
}
long long lsb (long long x)
{
    return x&-x;
}
void update (long long pz,long long val)
{
    long long i;
    for(i=pz;i<=200000;i+=lsb(i))
        aib[i]+=val;
}
long long query (long long pz)
{
    long long rz=0;
    long long i;
    for(i=pz;i>0;i-=lsb(i))
        rz+=aib[i];
    return rz;
}
void update1 (long long pz)
{
    long long i;
    for(i=pz;i<=200000;i+=lsb(i))
        aib1[i]++;
}
long long query1 (long long pz)
{
    long long i;
    long long rz=0;
    for(i=pz;i>0;i-=lsb(i))
        rz+=aib1[i];
    return rz;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long t,i,j,a,b,c,ra,rb,rc,n;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i].x;
    for(i=1;i<=n;++i)
        cin>>v[i].v;
    sort(v+1,v+n+1,cmp1);
    long long cur=0;
    v[0].v=v[1].v-1;
    for(i=1;i<=n;++i)
        if(v[i].v!=v[i-1].v)
            mp[v[i].v]=++cur;
    for(i=1;i<=n;++i)
        v[i].v=mp[v[i].v];
    sort(v+1,v+n+1,cmp2);
    long long rz=0;
    for(i=1;i<=n;++i)
    {
        rz+=v[i].x*query1(v[i].v)-query(v[i].v);
        update1(v[i].v);
        update(v[i].v,v[i].x);
    }
    cout<<rz;
    return 0;
}