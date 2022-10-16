#include <bits/stdc++.h>
using namespace std;
char v[203];
vector <int> edges[30];
int rz[30],k=0,ok=1;
int viz[30];
void dfs (int pz,int t)
{
    if(edges[pz].size()>2)
        ok=0;
    viz[pz]=1;
    rz[++k]=pz;
    for(int i=0;i<edges[pz].size();++i)
    {
        int nn=edges[pz][i];
        if(viz[nn])
        {
            if(nn!=t)
                ok=0;
        }
        else
            dfs(nn,pz);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,i,j,t;
    cin>>t;
    while(t--)
    {
        k=0;
        for(i=1;i<=27;++i)
        {
            edges[i].clear();
            viz[i]=0;
        }
        cin>>v;
        n=strlen(v);
        ok=1;
        for(i=1;i<n;++i)
        {
            for(j=0;j<edges[v[i-1]-'a'+1].size();++j)
            {
                if(edges[v[i-1]-'a'+1][j]==v[i]-'a'+1)
                    break;
            }
            if(j==edges[v[i-1]-'a'+1].size())
            edges[v[i-1]-'a'+1].push_back(v[i]-'a'+1);
            for(j=0;j<edges[v[i]-'a'+1].size();++j)
            {
                if(edges[v[i]-'a'+1][j]==v[i-1]-'a'+1)
                    break;
            }
            if(j==edges[v[i]-'a'+1].size())
            edges[v[i]-'a'+1].push_back(v[i-1]-'a'+1);
        }
        for(i=1;i<=26;++i)
        {
            if(edges[i].size()<=1 && !viz[i])
                dfs(i,-1);
        }
        for(i=1;i<=26;++i)
            if(viz[i]==0)
                ok=0;
        if(ok)
        {
            cout<<"YES\n";
            for(i=1;i<=26;++i)
                cout<<(char)('a'+rz[i]-1);
            cout<<"\n";
        }
        else
            cout<<"NO\n";
    }
    return 0;
}