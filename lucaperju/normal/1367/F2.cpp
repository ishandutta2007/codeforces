#include <bits/stdc++.h>
using namespace std;
const int N=200000;
struct uraib
{
    int a,cnt;
}aib[200005];
struct ura1
{
    int a,pz,an;
}v[200005];
bool cmp1 (ura1 a, ura1 b)
{
    return a.a<b.a;
}
bool cmp2 (ura1 a, ura1 b)
{
    return a.pz<b.pz;
}
struct ura
{
    int a,pz,b,cnt;
}v1[200005];
bool cmp (ura a, ura b)
{
    if(a.a<b.a)
        return true;
    if(a.a>b.a)
        return false;
    return a.pz>b.pz;
}
int catmm[200005];
int lsb (int x)
{
    return x&-x;
}
uraib query (int val)
{
    uraib rz={0,0};
    for(int pz=val;pz>0;pz-=lsb(pz))
    {
        if(aib[pz].a>rz.a)
            rz=aib[pz];
    }
    return rz;
}
void update (int val)
{
    for(int pz=val;pz<=N;pz+=lsb(pz))
    {
        if(aib[pz].a==val)
            ++aib[pz].cnt;
        else if(aib[pz].a<val)
            aib[pz].a=val,aib[pz].cnt=1;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t,m,k,i,j,p,mxx=0,s,q,nr1=0,nr2=0,nr3=0,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
        {
            cin>>v[i].a;
            v[i].pz=i;
        }
        for(i=0;i<=n;++i)
        {
            catmm[i]=0;
            aib[i].a=aib[i].cnt=0;
        }
        sort(v+1,v+n+1,cmp1);
        int cnt=0;
        for(i=1;i<=n;++i)
        {
            if(i==1 || v[i].a!=v[i-1].a)
                ++cnt;
            catmm[cnt]++;
            v[i].an=cnt;
        }
        for(i=1;i<=n;++i)
            catmm[i]+=catmm[i-1];
        sort(v+1,v+n+1,cmp2);
        for(i=n;i>=1;--i)
        {
            v1[i].a=v[i].an;
            v1[i].pz=i;
            uraib x;
            x=query(v[i].an-1);
            v1[i].b=x.a;
            v1[i].cnt=x.cnt;
            update(v[i].an);
        }
        sort(v1+1,v1+n+1,cmp);
        int rz=n;
        int mxc=0;
        for(i=1;i<=n;++i)
        {
            mxc=max(mxc,v1[i].cnt+catmm[v1[i].b-1]);
            rz=min(rz,n-i+mxc);
        }
        cout<<rz<<'\n';
    }
    return 0;
}