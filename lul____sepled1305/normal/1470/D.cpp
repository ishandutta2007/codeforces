/**
    Chtholly Nota Seniorious
**/

#include<bits/stdc++.h>
#define ll long long
using namespace std;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
int T;

void solve()
{
    int n,m,i;
    cin>>n>>m;
    bool visit[n], total = true;
    int depth[n];
    for(i=0;i<n;i++)
        visit[i] = false;
    vector<int> G[n];
    for(i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    visit[0] = true;
    depth[0] = 0;
    queue<int> qu;
    qu.push(0);
    while(!qu.empty())
    {
        int node = qu.front();
        qu.pop();
        for(auto it: G[node])
        {
            if(!visit[it])
            {
                visit[it] = true;
                qu.push(it);
                depth[it] = depth[node] + 1;
            }
        }
    }
    for(i=0;i<n;i++)
        total = total&visit[i];
    set<int> st;
    vector<pii> v;
    for(i=0;i<n;i++)
        v.push_back({depth[i],i});
    sort(v.begin(),v.end());
    vector<int> ans;
    if(total)
    {
        cout<<"YES\n";
        for(auto it: v)
        {
            int i = it.second;
            if(st.count(i) == 0)
            {
                st.insert(i);
                for(auto it: G[i])
                    st.insert(it);
                ans.push_back(i);
            }
        }
        cout<<ans.size()<<'\n';
        for(auto it: ans)
            cout<<it+1<<' ';
        cout<<"\n";
    }
    else
    {
        cout<<"NO\n";
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