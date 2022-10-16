#include <bits/stdc++.h>
using namespace std;
vector<int>v[100005];
int dst[100005];
void dfs(int pz, int t)
{
    for(int i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]!=t)
        {
            dst[v[pz][i]]=1+dst[pz];
            dfs(v[pz][i],pz);
        }
    }
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,t,i,j,k;
    cin>>t;
    while(t--)
    {
        int a,b,da,db;
        cin>>n>>a>>b>>da>>db;
        for(i=1;i<=n;++i)
            v[i].clear();
        for(i=1;i<n;++i)
        {
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        if(da*2>=db)
        {
            cout<<"Alice\n";
            continue;
        }
        dst[a]=0;
        dfs(a,-1);
        if(dst[b]<=da)
        {
            cout<<"Alice\n";
            continue;
        }
        int pz=1;
        for(i=1;i<=n;++i)
        {
            if(dst[i]>dst[pz])
                pz=i;
        }
        dst[pz]=0;
        dfs(pz,-1);
        int mx=0;
        for(i=1;i<=n;++i)
            if(dst[i]>mx)
                mx=dst[i];
        ++mx;
        if(mx<=1+da*2)
            cout<<"Alice\n";
        else
            cout<<"Bob\n";
    }
}