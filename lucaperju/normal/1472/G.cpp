#include <bits/stdc++.h>
using namespace std;
vector<int>v[200003];
vector<int>v1[200003];
int dst[200003];
int q[200003];
int bst[200003];
int ok[200003];
void bfs ()
{
    int st=1,dr=1;
    q[1]=1;
    while(st<=dr)
    {
        int pz=q[st++];
        for(int i=0;i<v[pz].size();++i)
        {
            if(dst[v[pz][i]]>1+dst[pz])
            {
                dst[v[pz][i]]=1+dst[pz];
                q[++dr]=v[pz][i];
            }
        }
    }
}
void dfs (int pz)
{
    if(ok[pz])
        return;
    for(int i=0;i<v1[pz].size();++i)
    {
        dfs(v1[pz][i]);
        bst[pz]=min(bst[pz],bst[v1[pz][i]]);
    }
    ok[pz]=1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    long long t,n,i,j,k,m;
    long long x1,y1,x2,y2;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=1;i<=n;++i)
        {
            v[i].clear();
            v1[i].clear();
            dst[i]=99999999;
        }
        dst[1]=0;
        for(i=1;i<=m;++i)
        {
            int a,b;
            cin>>a>>b;
            v[a].push_back(b);
        }
        bfs();
        for(i=1;i<=n;++i)
        {
            ok[i]=0;
            bst[i]=dst[i];
            for(j=0;j<v[i].size();++j)
                bst[i]=min(bst[i],dst[v[i][j]]);
            for(j=0;j<v[i].size();++j)
            {
                if(dst[i]<dst[v[i][j]])
                    v1[i].push_back(v[i][j]);
            }
        }
        for(i=1;i<=n;++i)
            dfs(i);
        for(i=1;i<=n;++i)
            cout<<bst[i]<<' ';
        cout<<'\n';
    }
    return 0;
}