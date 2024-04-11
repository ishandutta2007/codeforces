#include <bits/stdc++.h>
using namespace std;
vector<int>v[400005];
vector<int>vr[400005];
int hasLoop[400005],k,viz[400005],compHasLoop[400005];
int dp[400005];
int topord[400005],idk=0;
vector<int>vn[400005];
void topsort (int pz)
{
    viz[pz]=1;
    for(int i=0;i<v[pz].size();++i)
        if(!viz[v[pz][i]])
            topsort(v[pz][i]);
    topord[++idk]=pz;
}
void dfsr (int pz)
{
    viz[pz]=k;
    for(int i=0;i<vr[pz].size();++i)
        if(!viz[vr[pz][i]])
            dfsr(vr[pz][i]);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int q,m,i,j,l,r,t,n;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=1;i<=n;++i)
        {
            viz[i]=0;
            hasLoop[i]=0;
            v[i].clear();
            vr[i].clear();
            vn[i].clear();
            compHasLoop[i]=0;
            dp[i]=0;
        }
        for(i=1;i<=m;++i)
        {
            int a,b;
            cin>>a>>b;
            if(a==b)
                hasLoop[a]=1;
            else
            {
                v[a].push_back(b);
                vr[b].push_back(a);
            }
        }
        idk=0;
        for(i=1;i<=n;++i)
        {
            if(!viz[i])
                topsort(i);
        }
        for(i=1;i<=n;++i)
            viz[i]=0;
        k=0;
        for(i=n;i>=1;--i)
        {
            if(!viz[topord[i]])
            {
                ++k;
                dfsr(topord[i]);
            }
        }
        for(i=1;i<=n;++i)
        {
            while(v[i].size())
            {
                if(viz[v[i].back()]!=viz[i])
                    vn[viz[v[i].back()]].push_back(viz[i]);
                v[i].pop_back();
            }
            if(hasLoop[i])
                compHasLoop[viz[i]]+=2;
            else
                compHasLoop[viz[i]]+=1;
        }
        for(i=1;i<=k;++i)
            if(compHasLoop[i]>=2)
                compHasLoop[i]=1;
            else
                compHasLoop[i]=0;
        dp[viz[1]]=1;
        if(compHasLoop[viz[1]])
            dp[viz[1]]=-1;
        for(i=1;i<=k;++i)
        {
            for(int j=0;j<vn[i].size();++j)
            {
                if(dp[vn[i][j]]==-1)
                {
                    dp[i]=-1;
                    break;
                }
                else
                    dp[i]+=dp[vn[i][j]];
            }
            if(dp[i]>=2)
                dp[i]=2;
            if(compHasLoop[i] && dp[i])
                dp[i]=-1;
        }
        for(i=1;i<=n;++i)
            cout<<dp[viz[i]]<<' ';
        cout<<'\n';
    }
    return 0;
}