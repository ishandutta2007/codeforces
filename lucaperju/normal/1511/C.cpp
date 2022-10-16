#include <bits/stdc++.h>
using namespace std;
long long p[11];
struct ura
{
    int a,pz;
}v[55];
int vi[300005];
int pz[55];
bool cmp (ura a, ura b)
{
    return a.pz<b.pz;
}
void upd (int pz, int n)
{
    ura aux=v[pz];
    int i;
    for(i=pz;i>=2;--i)
        v[i]=v[i-1];
    v[1]=aux;
    for(i=2;i<=pz;++i)
        ++v[i].pz;
    v[1].pz=1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    long long i,t,j,n,m;
    cin>>n>>m;
    for(i=1;i<=n;++i)
    {
        cin>>vi[i];
        if(pz[vi[i]]==0)
            pz[vi[i]]=i;
    }
    j=0;
    for(i=1;i<=50;++i)
    {
        if(pz[i])
        {
            v[++j]={i,pz[i]};
        }
    }
    n=j;
    sort(v+1,v+n+1,cmp);
    while(m--)
    {
        int a;
        cin>>a;
        for(i=1;i<=n;++i)
        {
            if(v[i].a==a)
                break;
        }
        cout<<v[i].pz<<' ';
        upd(i,n);
    }
	return 0;
}