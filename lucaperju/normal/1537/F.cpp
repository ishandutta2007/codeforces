#include <bits/stdc++.h>
using namespace std;
long long v[200003];
int x[200003],y[200003];
vector<int>ed[200003];
int viz[200003];
long long sum[3],okt=0;
void dfs (int pz, int val)
{
    viz[pz]=val;
    sum[val]+=v[pz];
    for(int i=0;i<ed[pz].size();++i)
    {
        if(!viz[ed[pz][i]])
        {
            dfs(ed[pz][i],3-val);
        }
        else
        {
            if(viz[ed[pz][i]]==val)
                okt=1;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int m,t,n,i;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=1;i<=n;++i)
        {
            viz[i]=0;
            ed[i].clear();
            v[i]=0;
            int a;
            cin>>a;
            v[i]-=a;
        }
        for(i=1;i<=n;++i)
        {
            int a;
            cin>>a;
            v[i]+=a;
        }
        for(i=1;i<=m;++i)
        {
            cin>>x[i]>>y[i];
            ed[x[i]].push_back(y[i]);
            ed[y[i]].push_back(x[i]);
        }
        int ok=1;
        for(i=1;i<=n;++i)
        {
            if(!viz[i])
            {
                if(ed[i].size()==0)
                {
                    if(v[i]!=0)
                        ok=0;
                    continue;
                }
                sum[1]=sum[2]=0;
                okt=0;
                dfs(i,1);
                if(okt==1)
                {
                    if(max((sum[1]+sum[2]),-(sum[1]+sum[2]))%2LL==1LL)
                        ok=0;
                }
                else
                {
                    if(sum[1]!=sum[2])
                        ok=0;
                }
            }
        }
        if(ok)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}