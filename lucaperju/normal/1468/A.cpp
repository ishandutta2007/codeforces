#include <bits/stdc++.h>
using namespace std;
int aib[500005];
int v[500005];
int nxt[500005],st[500005];
int dp[500005];
vector<int>hasnxt[500005];
int lsb (int x)
{
    return x&-x;
}
void update (int pz, int val)
{
    for(int i=pz;i<=500000;i+=lsb(i))
        aib[i]=max(aib[i],val);
}
int query (int pz)
{
    int rz=0;
    for(int i=pz;i>0;i-=lsb(i))
        rz=max(rz,aib[i]);
    return rz;
}
int main()
{
    ios_base::sync_with_stdio(false);
    long long t,n,i,j,mod,m;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int k=0;
        for(i=1;i<=n;++i)
            hasnxt[i].clear();
        for(i=1;i<=n;++i)
        {
            aib[i]=0;
            dp[i]=0;
            cin>>v[i];
            while(k>0 && v[st[k]]<=v[i])
                --k;
            nxt[i]=st[k];
            hasnxt[st[k]].push_back(i);
            st[++k]=i;
        }
        int mx=0;
        for(i=1;i<=n;++i)
        {
            dp[i]=max(dp[i],1+query(v[i]));
            for(j=0;j<hasnxt[i].size();++j)
            {
                int pzc=hasnxt[i][j];
                dp[pzc]=max(dp[pzc],2+query(v[pzc]));
            }
            update(v[i],dp[i]);
            mx=max(mx,dp[i]);
        }
        cout<<mx<<'\n';
    }
    return 0;
}