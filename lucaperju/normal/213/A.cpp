#include <bits/stdc++.h>

using namespace std;
int vl[203],cat[203],lib[4][203],ccat[203];
vector <int> v[203];
int main()
{
    long long add=1,t,h,n,i,j,mn=100003LL*100003LL,k,mx=0,rz=0,tot,m,obj,st,cnt=0,cnti=0,s=0,nri=0,a[4],b=0,c=0,a2,b2,a3,b3;
    cin>>n;
    s=n;
    a[1]=a[2]=a[3]=0;
    for(i=1;i<=n;++i)
        cin>>vl[i];
    for(i=1;i<=n;++i)
    {
        cin>>k;
        for(j=1;j<=k;++j)
        {
            int x;
            cin>>x;
            v[x].push_back(i);
        }
        cat[i]=k;
        ccat[i]=k;
    }
    int pz;
    pz=1;
    s=n;
    for(i=1;i<=n;++i)
        if(cat[i]==0)
            lib[vl[i]][++a[vl[i]]]=i;
    cnt=0;
    while(cnt<n)
    {
        for(i=1;i<=a[pz];++i)
        {
            for(j=0;j<v[lib[pz][i]].size();++j)
            {
                --ccat[v[lib[pz][i]][j]];
                if(ccat[v[lib[pz][i]][j]]==0)
                    lib[vl[v[lib[pz][i]][j]]][++a[vl[v[lib[pz][i]][j]]]]=v[lib[pz][i]][j];
            }
        }
        cnt+=a[pz];
        a[pz]=0;
        ++s;
        ++pz;
        if(pz==4)
            pz=1;
    }
    --s;
    mn=min(mn,s);
    for(i=1;i<=n;++i)
        ccat[i]=cat[i];/// ------------TANTA
    pz=2;
    s=n;
    for(i=1;i<=n;++i)
        if(cat[i]==0)
            lib[vl[i]][++a[vl[i]]]=i;
    cnt=0;
    while(cnt<n)
    {
        for(i=1;i<=a[pz];++i)
        {
            for(j=0;j<v[lib[pz][i]].size();++j)
            {
                --ccat[v[lib[pz][i]][j]];
                if(ccat[v[lib[pz][i]][j]]==0)
                    lib[vl[v[lib[pz][i]][j]]][++a[vl[v[lib[pz][i]][j]]]]=v[lib[pz][i]][j];
            }
        }
        cnt+=a[pz];
        a[pz]=0;
        ++s;
        ++pz;
        if(pz==4)
            pz=1;
    }
    --s;
    mn=min(mn,s);
    for(i=1;i<=n;++i)
        ccat[i]=cat[i]; /// -----------CAZAN
    pz=3;
    s=n;
    for(i=1;i<=n;++i)
        if(cat[i]==0)
            lib[vl[i]][++a[vl[i]]]=i;
    cnt=0;
    while(cnt<n)
    {
        for(i=1;i<=a[pz];++i)
        {
            for(j=0;j<v[lib[pz][i]].size();++j)
            {
                --ccat[v[lib[pz][i]][j]];
                if(ccat[v[lib[pz][i]][j]]==0)
                    lib[vl[v[lib[pz][i]][j]]][++a[vl[v[lib[pz][i]][j]]]]=v[lib[pz][i]][j];
            }
        }
        cnt+=a[pz];
        a[pz]=0;
        ++s;
        ++pz;
        if(pz==4)
            pz=1;
    }
    --s;
    mn=min(mn,s);
    cout<<mn;
    return 0;
}