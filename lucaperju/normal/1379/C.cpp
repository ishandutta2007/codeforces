#include <bits/stdc++.h>
using namespace std;
struct ura
{
    long long a,b,pz;
}v[100005],v1[100005];
bool cmp1 (ura a, ura b)
{
    return a.a>b.a;
}
bool cmp2 (ura a, ura b)
{
    return a.b>b.b;
}
int ocp[100005];
int main()
{
    long long n,m,i,j,x,y,k,t,l,r;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=1;i<=m;++i)
        {
            cin>>v[i].a>>v[i].b;
            v[i].pz=i;
            v1[i].a=v[i].a;
            v1[i].b=v[i].b;
            v1[i].pz=v[i].pz;
            ocp[i]=0;
        }
        sort(v+1,v+m+1,cmp1);
        sort(v1+1,v1+m+1,cmp2);
        long long mx=0;
        long long r=n;
        int i=1;
        long long s=0;
        for(long long pzc=1;pzc<=m;++pzc)
        {
            while(i<=m && v[i].a>v1[pzc].b && r)
            {
                s+=v[i].a;
                ocp[v[i].pz]=1;
                ++i;
                --r;
            }
            long long sc=s;
            long long rc=r;
            if(ocp[v1[pzc].pz])
            {
                ++rc;
                sc-=v1[pzc].a;
            }
            if(rc)
            {
                sc+=v1[pzc].a;
                --rc;
            }
            sc+=rc*1LL*v1[pzc].b;
            mx=max(mx,sc);
        }
        cout<<mx<<'\n';
    }
    return 0;
}