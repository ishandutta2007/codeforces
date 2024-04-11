#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;
using pli = pair<long long,int>;
using pii = pair<int,int>;
const int N = 2e5+10;
const long long INF = 1e18+7;
int n,m,i,j;
long long dp[N];
vector<pii> G[N];
set<pii> del;
int par[N],last[N];
bool visi[N];

void dijkstra(int s)
{
    dp[s] = 0;
    par[s] = s;
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push({0LL,s});

    while(!pq.empty())
    {
        pli top = pq.top();
        pq.pop();
        long long val = top.first;
        int node = top.second;

        if(val != dp[node])
            continue;

        for(i = 0; i< G[node].size() ;i++)
        {
            pii it = G[node][i];
            int to = it.first;
            if(dp[to] > dp[node] + it.second)
            {
                dp[to] = dp[node] + it.second;
                par[to] = node;
                pq.push({dp[to],to});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        a--,b--;
        G[a].pb({b,c});
        G[b].pb({a,c});
    }
    for(i=0;i<n;i++)
        dp[i] = INF;
    dijkstra(0);
    if(dp[n-1] == INF)
        cout<<-1;
    else
    {
        int node = n-1;
        vector<int> ans;
        while(node != 0)
        {
            ans.push_back(node);
            node = par[node];
        }
        ans.push_back(0);
        while(!ans.empty())
        {
            cout<<ans.back()+1<<' ';
            ans.pop_back();
        }
    }
    /**for(i=0;i<n;i++)
    {
        if(!del.count({i,par[i]}))
            del.insert({i,par[i]});
        if(!del.count({par[i],i}))
            del.insert({par[i],i});
    }
    queue<int> st;
    st.push(0);
    while(!st.empty())
    {
        int node = st.front();
        st.pop();
        visi[node] = true;
        for(auto it: G[node])
        {
            if(!visi[it.first] && !del.count({node,it.first}))
            {
                st.push(it.first);
                visi[it.first] = true;
                last[it.first] = node;
            }
        }
    }
    if(!visi[1])
        cout<<"impossible";
    else
    {
        long long cur = 1;
        vector<long long> ans;
        ans.pb(cur);
        while(last[cur] != cur)
        {
            cur = last[cur];
            ans.pb(cur);
        }
        cout<<ans.size()<<' ';
        while(!ans.empty())
        {
            cout<<ans.back()<<' ';
            ans.pop_back();
        }
    }**/
}