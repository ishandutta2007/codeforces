#include <bits/stdc++.h>
using namespace std;
vector <int>v[200005];
struct ura
{
    int sz,dst;
}v1[200005];
void dfs (int pz, int t)
{
    v1[pz].sz=1;
    for(int i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]!=t)
        {
            v1[v[pz][i]].dst=1+v1[pz].dst;
            dfs(v[pz][i],pz);
            v1[pz].sz+=v1[v[pz][i]].sz;
        }
    }
}
bool cmp(ura a, ura b)
{
  /*  if(a.dst>b.dst)
        return true;
    if(a.dst<b.dst)
        return false;*/
    return a.sz>b.sz;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long i,j,mx=0,s=0,ok,n;
    long long k=0,t,d;
    cin>>n>>k;
    for(i=1;i<n;++i)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1,-1);
    for(i=1;i<=n;++i)
    {
        v1[i].sz=v1[i].dst-v1[i].sz+1;
    }
    long long rz=0;
    sort(v1+1,v1+n+1,cmp);
    for(i=1;i<=k;++i)
        rz+=v1[i].sz;
    cout<<rz;
    return 0;
}