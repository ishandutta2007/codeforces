#include <bits/stdc++.h>

using namespace std;
vector<int>v[300003];
int viz[300003];
vector<int>rz;
void dfs (int pz, int fel)
{
    if(fel==0)
    {
        viz[pz]=1;
        for(int i=0;i<v[pz].size();++i)
        {
            if(!viz[v[pz][i]])
                dfs(v[pz][i],1);
        }
    }
    else
    {
        int ok=0;
        for(int i=0;i<v[pz].size();++i)
            if(viz[v[pz][i]])
                if(viz[v[pz][i]]==2)
                    ok=1;
        if(ok==0)
        {
            viz[pz]=2;
            rz.push_back(pz);
        }
        else
        {
            viz[pz]=1;
        }
        for(int i=0;i<v[pz].size();++i)
            if(!viz[v[pz][i]])
                dfs(v[pz][i],ok);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,n,i,j,k=0,m;
    long long x1,y1,x2,y2,pas;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=1;i<=n;++i)
        {
            v[i].clear();
            viz[i]=0;
        }
        for(i=1;i<=m;++i)
        {
            int a,b;
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        rz.clear();
        dfs(1,1);
        int ok=1;
        for(i=1;i<=n;++i)
            if(viz[i]==0)
                ok=0;
        if(!ok)
            cout<<"NO\n";
        else
        {
            cout<<"Yes\n";
            cout<<rz.size()<<'\n';
            for(i=0;i<rz.size();++i)
            {
                cout<<rz[i]<<' ';
            }
            cout<<'\n';
        }
    }
    return 0;
}