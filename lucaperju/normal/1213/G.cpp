#include <bits/stdc++.h>

using namespace std;
long long t[200005];
long long val[200005];
struct ura
{
    long long a,pz;
}q[200005];
long long tata (long long nod)
{
    if(t[nod]==0)
        return nod;
    t[nod]=tata(t[nod]);
    return t[nod];
}
long long unite (long long a, long long b)
{
    long long s=val[tata(a)]*1LL*val[tata(b)];
    val[tata(a)]+=val[tata(b)];
    val[tata(b)]=0;
    t[tata(b)]=tata(a);
    return s;
}
struct edge
{
    long long a,b,c;
}v[200005];
bool cmp (edge a, edge b)
{
    return a.c<b.c;
}
bool cmp1 (ura a, ura b)
{
    return a.a<b.a;
}
bool cmp2 (ura a, ura b)
{
    return a.pz<b.pz;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    long long n,i,j,k=0,s=0,cnt=0,m;
    cin>>n>>m;
    for(i=1;i<n;++i)
    {
        long long a,b,c;
        cin>>a>>b>>c;
        v[i].a=a;
        v[i].b=b;
        v[i].c=c;
        val[i]=1;
    }
    val[n]=1;
    for(i=1;i<=m;++i)
    {
        cin>>q[i].a;
        q[i].pz=i;
    }
    j=1;
    sort(q+1,q+m+1,cmp1);
    sort(v+1,v+n,cmp);
    for(i=1;i<=m;++i)
    {
        while(j<n && v[j].c<=q[i].a)
        {
            s+=unite(v[j].a,v[j].b);
            ++j;
        }
        q[i].a=s;
    }
    sort(q+1,q+m+1,cmp2);
    for(i=1;i<=m;++i)
        cout<<q[i].a<<' ';
    return 0;
}