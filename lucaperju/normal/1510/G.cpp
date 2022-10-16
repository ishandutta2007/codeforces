#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
vector<int>v[103];
int d[103],mark[103];
int t[103],k;
int cnt=0;
vector<int>rz;
void dfsinit (int pz, int dc)
{
    d[pz]=dc;
    for(int i=0;i<v[pz].size();++i)
        dfsinit(v[pz][i],dc+1);
}
void dfs (int pz)
{
    int i,ok=0;
    //rz.push_back(pz);
    if(cnt==k)
    {
        for(i=0;i<v[pz].size();++i)
        {
            if(mark[v[pz][i]]==1)
            {
                ok=1;
                rz.push_back(pz);
                dfs(v[pz][i]);
            }
        }
        if(!ok)
            rz.push_back(pz);
    }
    else
    {
        for(i=0;i<v[pz].size();++i)
        {
            if(mark[v[pz][i]]==0)
            {
                rz.push_back(pz);
                mark[v[pz][i]]=2;
                ++cnt;
                dfs(v[pz][i]);
            }
            if(cnt==k)
                break;
        }
        for(i=0;i<v[pz].size();++i)
        {
            if(mark[v[pz][i]]==1)
            {
                rz.push_back(pz);
                dfs(v[pz][i]);
            }
        }
        if(mark[pz]!=1)
            rz.push_back(pz);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    int tt,i,j;
    int s=0,n;
    cin>>tt;
    while(tt--)
    {
        cin>>n>>k;
        rz.clear();
        for(i=1;i<=n;++i)
        {
            v[i].clear();
            mark[i]=0;
        }
        for(i=2;i<=n;++i)
        {
            int a;
            cin>>a;
            t[i]=a;
            v[a].push_back(i);
        }
        dfsinit(1,0);
        int pzmx=1;
        for(i=1;i<=n;++i)
        {
            if(d[i]>d[pzmx])
                pzmx=i;
        }
        cout<<2*(k-1)-min(k-1,d[pzmx])<<'\n';
        while(d[pzmx]>=k)
            pzmx=t[pzmx];
        cnt=d[pzmx]+1;
        while(pzmx)
        {
            mark[pzmx]=1;
            pzmx=t[pzmx];
        }
        dfs(1);
        for(i=0;i<rz.size();++i)
            cout<<rz[i]<<' ';
        cout<<'\n';
    }
	return 0;
}