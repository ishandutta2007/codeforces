#include<bits/stdc++.h>
using namespace std;
int T,ans;

int dfs(vector<int> G[], int node, bool visit[], int k,bool first)
{
    if(!visit[node])
    {
        visit[node] = true;
        int counti = 0;
        for(auto it: G[node])
        {
            if(!visit[it])
                counti += dfs(G,it,visit,k,false);
        }
        ans+=counti/k;
        if(counti!=G[node].size()-1)
            return 0;
        else if(G[node].size() % k != 1)
            return 0;
        else
        {
            return 1;
        }
    }
    return 0;
}

void solve()
{
    int n,m,i,root,k;
    ans = 0;
    cin>>n>>k;
    vector<int> G[n];
    bool all = true;
    bool visit[n];
    for(i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(i=0;i<n;i++)
        visit[i] = false;
    for(i=0;i<n;i++)
    {
        if(G[i].size()%k != 1)
        {
            all = false;
            root = i;
            break;
        }
    }
    if(all)
        cout<<(n-1)/k<<"\n";
    else if(k==1)
    {
        cout<<n-1<<"\n";
    }
    else
    {
        dfs(G,root,visit,k,true);
        cout<<ans<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>T;
    while(T--)
        solve();
    return 0;
}