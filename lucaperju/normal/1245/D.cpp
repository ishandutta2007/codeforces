#include <bits/stdc++.h>

using namespace std;
struct ura
{
    long long a,b,cst;
}v[4002005];
long long x[2003],y[2003],c[2003],t[2003];
long long cost (long long a, long long b)
{
    return (c[a]+c[b])*1LL*(abs(x[a]-x[b])+abs(y[a]-y[b]));
}
long long tata (long long a)
{
    if(t[a]==-1)
        return a;
    return t[a]=tata(t[a]);
}
bool cmp (ura a, ura b)
{
    return a.cst<b.cst;
}
vector <long long> sol;
vector <long long> solx;
vector <long long> soly;
int main()
{
    long long n,i,j,k=0;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>x[i]>>y[i];
    for(i=1;i<=n;++i)
    {
        long long a;
        cin>>a;
        v[++k].a=0;
        v[k].b=i;
        v[k].cst=a;
    }
    for(i=1;i<=n;++i)
        cin>>c[i];
    for(i=1;i<=n;++i)
        for(j=i+1;j<=n;++j)
        {
            v[++k].a=i;
            v[k].b=j;
            v[k].cst=cost(i,j);
        }
    sort(v+1,v+k+1,cmp);
    long long s=0;
    for(i=0;i<=n;++i)
        t[i]=-1;
    for(i=1;i<=k;++i)
    {
        if(tata(v[i].a)!=tata(v[i].b))
        {
            s+=v[i].cst;
            t[tata(v[i].a)]=tata(v[i].b);
            if(v[i].a==0)
                sol.push_back(v[i].b);
            else
            {
                solx.push_back(v[i].a);
                soly.push_back(v[i].b);
            }
        }
    }
    cout<<s<<'\n';
    cout<<sol.size()<<'\n';
    for(i=0;i<sol.size();++i)
        cout<<sol[i]<<' ';
    cout<<'\n';
    cout<<solx.size()<<'\n';
    for(i=0;i<solx.size();++i)
        cout<<solx[i]<<' '<<soly[i]<<'\n';
    return 0;
}