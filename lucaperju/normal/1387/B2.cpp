#include <bits/stdc++.h>
using namespace std;
vector<int> v[100005];
int sz[100005];
int col[100005];
void dfssize (int pz, int t)
{
    sz[pz]=1;
    for(int i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]==t)
            continue;
        dfssize(v[pz][i],pz);
        sz[pz]+=sz[v[pz][i]];
    }
}
int findcentroid (int pz, int t,int n)
{
    for(int i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]==t)
            continue;
        if(sz[v[pz][i]]>n/2)
            return findcentroid(v[pz][i],pz,n);
    }
    return pz;
}
vector<int>vc;
vector<int>vc1;
void dfsget(int pz, int t)
{
    vc.push_back(pz);
    for(int i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]==t)
            continue;
        dfsget(v[pz][i],pz);
    }
}
void dfsget1(int pz, int t)
{
    vc1.push_back(pz);
    for(int i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]==t)
            continue;
        dfsget1(v[pz][i],pz);
    }
}
void dfscol(int pz, int t, int colc)
{
    col[pz]=colc;
    for(int i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]==t)
            continue;
        dfscol(v[pz][i],pz,colc);
    }
}
int fin[100005];
struct ura
{
    int pz,col;
};
vector<ura>vc2;
bool cmp (ura a, ura b)
{
    return a.col<b.col;
}
int main()
{
    long long n,m,i,j,x,y,k,t,l,r;
    cin>>n;
    for(i=1;i<n;++i)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfssize(1,-1);
    int root=findcentroid(1,-1,n);
    dfssize(root,-1);
    int root1=0;
    long long sum=0;
    for(i=0;i<v[root].size();++i)
    {
        if(n%2==0 && sz[v[root][i]]==n/2)
            root1=v[root][i];
    }
    if(root1)
    {
        dfsget(root,root1);
        dfsget1(root1,root);
        for(i=0;i<n/2;++i)
        {
            fin[vc[i]]=vc1[i];
            fin[vc1[i]]=vc[i];
        }
    }
    else
    {
        int mx=0;
        for(i=0;i<v[root].size();++i)
        {
            dfscol(v[root][i],root,i+1);
            mx=max(mx,sz[v[root][i]]);
        }
        for(i=1;i<=n;++i)
            vc2.push_back({i,col[i]});
        sort(vc2.begin(),vc2.end(),cmp);
        for(i=0;i<vc2.size();++i)
        {
            int pzc=vc2[i].pz;
            int pzn=i-mx;
            if(pzn<0)
                pzn+=n;
            fin[pzc]=vc2[pzn].pz;
        }
    }
    for(i=1;i<=n;++i)
        if(i!=root)
            sum+=sz[i]*2LL;
    cout<<sum<<'\n';
    for(i=1;i<=n;++i)
        cout<<fin[i]<<' ';
    return 0;
}