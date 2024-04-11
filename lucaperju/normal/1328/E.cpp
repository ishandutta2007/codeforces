#include <bits/stdc++.h>
using namespace std;
vector <int> v[200005];
int lev[200005],qc[200005],st[200005],dr[200005],tmp=0,tat[200005];
void dfs (int pz, int t)
{
    st[pz]=++tmp;
    for(int i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]!=t)
        {
            lev[v[pz][i]]=1+lev[pz];
            tat[v[pz][i]]=pz;
            dfs(v[pz][i],pz);
        }
    }
    dr[pz]=++tmp;
}
bool cmp (int a, int b)
{
    return lev[a]>lev[b];
}
int main()
{
    int t,i,j,n,m,cnt=0;
    cin>>n>>m;
    for(i=1;i<n;++i)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    lev[1]=1;
    tat[1]=1;
    dfs(1,-1);
    for(i=1;i<=m;++i)
    {
        int nc;
        cin>>nc;
        for(j=1;j<=nc;++j)
        {
            cin>>qc[j];
            qc[j]=tat[qc[j]];
        }
        sort(qc+1,qc+nc+1,cmp);
        for(j=1;j<nc;++j)
            if(st[qc[j]]<st[qc[j+1]] || dr[qc[j]]>dr[qc[j+1]])
            {
                cout<<"NO\n";
                break;
            }
        if(j!=nc)
            continue;
        cout<<"YES\n";
    }
    return 0;
}