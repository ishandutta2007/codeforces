#include <bits/stdc++.h>

using namespace std;
vector <int> v[200005];
int jos[200005],sus[200005];
int val[200005];
void dfsj (int pz, int t)
{
    int sc=0;
    int i;
    for(i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]!=t)
        {
            dfsj(v[pz][i],pz);
            sc+=max(0,jos[v[pz][i]]);
        }
    }
    jos[pz]=val[pz]+sc;
}
void dfss (int pz, int t)
{
    int sc=0;
    int i;
    for(i=0;i<v[pz].size();++i)
        if(v[pz][i]!=t)
            sc+=max(0,jos[v[pz][i]]);
    for(i=0;i<v[pz].size();++i)
        if(v[pz][i]!=t)
            sus[v[pz][i]]=max(0,val[pz]+sus[pz]+sc-max(0,jos[v[pz][i]]));
    for(i=0;i<v[pz].size();++i)
        if(v[pz][i]!=t)
            dfss(v[pz][i],pz);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,ok=0,i,j,cnt=4,h,l,r;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>val[i];
        if(val[i]==0)
            --val[i];
    }
    for(i=1;i<n;++i)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfsj(1,-1);
    dfss(1,-1);
    for(i=1;i<=n;++i)
        cout<<jos[i]+sus[i]<<' ';
    return 0;
}