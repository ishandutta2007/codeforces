#include <bits/stdc++.h>
using namespace std;
int id[1000006],ok[1000006];
int msk;
vector<int>v[1000006];
void dfs (int pz)
{
    if(id[pz])
        msk=(msk|(1<<(id[pz]-1)));
    for(int i=0;i<v[pz].size();++i)
        dfs(v[pz][i]);
}
vector<int>masks;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,i,j,m,n,s=0;
    cin>>n>>m;
    for(i=1;i<=m;++i)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        ok[b]=1;
    }
    for(i=1;i<=n;++i)
        if(v[i].size()==0)
            id[i]=++s;
    for(i=1;i<=n;++i)
        if(!ok[i])
        {
            msk=0;
            dfs(i);
            masks.push_back(msk);
        }
    int k=1;
    for(int mask=1;mask<(1<<s)-1;++mask)
    {
        int cnt=__builtin_popcount(mask);
        for(i=0;i<masks.size();++i)
        {
            if((mask&masks[i])==masks[i])
                --cnt;
        }
        if(cnt<=0)
        {
            k=0;
            break;
        }
    }
    if(k)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}