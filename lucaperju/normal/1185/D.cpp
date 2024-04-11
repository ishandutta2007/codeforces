#include <bits/stdc++.h>

using namespace std;
struct ura
{
    int a,pz;
}v[200005];
bool cmp (ura a, ura b)
{
    return a.a<b.a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n,i,j;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v[i].a;
        v[i].pz=i;
    }
    sort(v+1,v+n+1,cmp);
    int ok=1;
    for(i=3;i<n;++i)
        if(v[i].a-v[i-1].a!=v[i+1].a-v[i].a)
            ok=0;
    if(ok)
    {
        cout<<v[1].pz;
        return 0;
    }
    ok=1;
    for(i=2;i<n-1;++i)
        if(v[i].a-v[i-1].a!=v[i+1].a-v[i].a)
            ok=0;
    if(ok)
    {
        cout<<v[n].pz;
        return 0;
    }
    int dif=v[n].a-v[1].a;
    if(dif%(n-2)==0)
    dif/=(n-2);
    else
    {
        cout<<-1;
        return 0;
    }
    int pzprec=1,pz;
    ok=0;
    for(i=2;i<=n;++i)
    {
        while(i<n && v[i].a-v[pzprec].a!=dif)
        {
            pz=v[i].pz;
            ++i;
            ++ok;
        }
        pzprec=i;
    }
    if(ok==1)
    {
        cout<<pz;
    }
    else
    {
        cout<<-1;
    }
    return 0;
}