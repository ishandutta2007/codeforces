
#include <bits/stdc++.h>
using namespace std;
vector<int>v[300005];
int col[300005],cntsub[300005],ans[300005],okt=0;
void dfsinit (int a, int t)
{
    if(col[a])
        cntsub[a]=1;
    for(int i=0;i<v[a].size();++i)
    {
        if(v[a][i]==t)
            continue;
        dfsinit(v[a][i],a);
        cntsub[a]=max(cntsub[a],cntsub[v[a][i]]);
    }
}
void dfsfill (int a, int t)
{
    ans[a]=1;
    for(int i=0;i<v[a].size();++i)
    {
        if(v[a][i]==t)
            continue;
        dfsfill(v[a][i],a);
    }
}
void dfs (int a, int t)
{
    int cnt=0;
    if(col[a]==1)
    {
        for(int i=0;i<v[a].size();++i)
        {
            if(col[v[a][i]])
            {
                okt=1;
                return;
            }
            if(v[a][i]==t)
                continue;
            if(!cntsub[v[a][i]])
                dfsfill(v[a][i],a);
            else
                ++cnt;
        }
        if(cnt>1)
        {
            okt=1;
            return;
        }
        if(cnt==0)
            return;
        for(int i=0;i<v[a].size();++i)
        {
            if(v[a][i]==t)
                continue;
            if(cntsub[v[a][i]])
                dfs(v[a][i],a);
        }
        return;
    }
    int idk=0;
    for(int i=0;i<v[a].size();++i)
    {
        if(col[v[a][i]])
            idk=1;
    }
    for(int i=0;i<v[a].size();++i)
    {
        if(v[a][i]==t)
            continue;
        if(!cntsub[v[a][i]])
        {
            if(idk)
                dfsfill(v[a][i],a);
        }
        else
            ++cnt;
    }
    assert(cnt);
    if(cnt>=2 && idk)
    {
        okt=1;
        return;
    }
    for(int i=0;i<v[a].size();++i)
    {
        if(v[a][i]==t)
            continue;
        if(cntsub[v[a][i]])
            dfs(v[a][i],a);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,i,j,n,m,k,root;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>col[i];
        if(col[i]==1)
            root=i;
    }
    for(i=1;i<n;++i)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfsinit(root,-1);
    dfs(root,-1);
    if(okt==1)
    {
        for(i=1;i<=n;++i)
            cout<<1<<' ';
        return 0;
    }
    for(i=1;i<=n;++i)
    {
        int okc=0;
        for(int j=0;j<v[i].size();++j)
            if(col[v[i][j]])
                okc=1;
        if(col[i]==1 || ans[i]==1 || okc==1)
            cout<<1<<' ';
        else
            cout<<0<<' ';
    }
    return 0;
}