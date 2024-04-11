#include <bits/stdc++.h>
using namespace std;
struct ura
{
    int a,b,c;
}v[200003];
long long n;
map<int,int>mp[200003];
int einc[200003];
int idk[200003];
vector<int>vcc;
vector<int>vcr;
vector<int>aux;
void getcomp (int a)
{
    vcc.clear();
    vcr.clear();
    aux.clear();
    vcc.push_back(a);
    int i,j;
    einc[a]=a;
    for(i=1;i<=n;++i)
        if(!einc[i])
            vcr.push_back(i);
    i=0;
    while(i<vcc.size())
    {
        for(j=0;j<vcr.size();++j)
        {
            if(mp[vcc[i]][vcr[j]]==0)
            {
                vcc.push_back(vcr[j]);
                einc[vcr[j]]=a;
            }
        }
        aux.clear();
        for(j=0;j<vcr.size();++j)
            if(!einc[vcr[j]])
                aux.push_back(vcr[j]);
        vcr.clear();
        for(j=0;j<aux.size();++j)
            vcr.push_back(aux[j]);
        ++i;
    }
}
int t[200003];
int tata (int x)
{
    if(t[x]==0 || t[x]==x)
        return x;
    else
        return t[x]=tata(t[x]);
}
bool cmp (ura a, ura b)
{
    return a.c<b.c;
}
int main()
{
    ios_base::sync_with_stdio(false);
    long long q,k,m,i,j;
    long long sx=0;
    cin>>n>>m;
    for(i=1;i<=m;++i)
    {
        cin>>v[i].a>>v[i].b>>v[i].c;
        mp[v[i].a][v[i].b]=1;
        mp[v[i].b][v[i].a]=1;
        sx=(sx^v[i].c);
    }
    int cnt=0;
    for(i=1;i<=n;++i)
    {
        if(!einc[i])
        {
            getcomp(i);
            ++cnt;
        }
    }
    int ok;
    if(cnt+(n*1LL*(n-1LL)/2LL-m)!=n)
        ok=0;
    else
        ok=1;
    long long s=0;
    for(i=1;i<=n;++i)
        t[i]=einc[i];
    sort(v+1,v+m+1,cmp);
    for(i=1;i<=m;++i)
    {
        int a=v[i].a;
        int b=v[i].b;
        if(tata(a)!=tata(b))
        {
            t[tata(a)]=tata(b);
            s+=v[i].c;
            idk[i]=1;
        }
    }
    if(!ok)
    {
        cout<<s;
        return 0;
    }
    long long rz=s+sx;
    for(i=1;i<=n;++i)
        t[i]=0;
    for(i=1;i<=m;++i)
    {
        int a=v[i].a;
        int b=v[i].b;
        if(tata(a)!=tata(b))
        {
            t[tata(a)]=tata(b);
            if(idk[i]==0)
            {
                sx=v[i].c;
                break;
            }
        }
    }
    rz=min(rz,s+sx);
    cout<<rz;
	return 0;
}