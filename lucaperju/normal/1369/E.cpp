#include <bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int cnt[100005],tmp;
int rz[200005],viz[100005];
int ocp[200005];
vector <int> v[100005];
vector <int> v1[100005];
void dfs (int pz)
{
    viz[pz]=1;
    for(int i=0;i<v[pz].size();++i)
    {
        int nn=v[pz][i];
        int e=v1[pz][i];
        if(!ocp[e])
            rz[++tmp]=e,ocp[e]=1;
        if(!viz[nn])
        {
            ++cnt[nn];
            if(cnt[nn]>=0)
                dfs(nn);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int i,j,n,t,m,k;
    cin>>n>>m;
    for(i=1;i<=n;++i)
        cin>>cnt[i];
    for(i=1;i<=m;++i)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
        v1[a].push_back(i);
        v1[b].push_back(i);
        --cnt[a];
        --cnt[b];
    }
    for(i=1;i<=n;++i)
    {
        if(cnt[i]>=0 && !viz[i])
        {
            dfs(i);
        }
    }
    for(i=1;i<=n;++i)
    {
        if(!viz[i])
        {
            cout<<"DEAD";
            return 0;
        }
    }
    cout<<"ALIVE\n";
    for(i=m;i>=1;--i)
        cout<<rz[i]<<' ';
    return 0;
}