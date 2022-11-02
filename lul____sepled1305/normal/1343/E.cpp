#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int t;
const int INF = 1e9;
int dist[200005][3];

void dijkstra(vector<vector<int>> &tree, int v,int x)
{
    int i;
    using pii = pair<int,int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[v][x] = 0;
    pq.push({0,v});
    while(!pq.empty())
    {
        int depth = pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if(depth != dist[here][x])
            continue;

        for(auto edge: tree[here])
        {
            int to = edge;
            if(dist[to][x] > depth +1)
            {
                dist[to][x] = depth + 1;
                pq.push({dist[to][x],to});
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    while(t--)
    {
        int n,m,a,b,c,i,j,p,q;
        cin>>n>>m>>a>>b>>c;
        for(i=0;i<n;i++)
        {
            for(j=0;j<3;j++)
            {
                dist[i][j] = INF;
            }
        }
        vector<vector<int>> tree;
        for(i=0;i<n;i++)
        {
            vector<int> v;
            tree.pb(v);
        }
        int price[m];
        long long quick_price[m];
        long long mini = 1e18;
        for(i=0;i<m;i++)
            cin>>price[i];
        sort(price,price+m);
        quick_price[0] = price[0];
        for(i=1;i<m;i++)
            quick_price[i] = quick_price[i-1] + price[i];
        for(i=0;i<m;i++)
        {
            cin>>p>>q;
            tree[p-1].pb(q-1);
            tree[q-1].pb(p-1);
        }
        dijkstra(tree, b-1,0);
        dijkstra(tree, a-1,1);
        dijkstra(tree, c-1,2);
        for(i=0;i<n;i++)
        {
            if(dist[i][0]!=0 && dist[i][0]+dist[i][1]+dist[i][2]-1<m)
                mini = min(mini,quick_price[dist[i][0]-1] + quick_price[dist[i][0]+dist[i][1]+dist[i][2]-1]);
            else if(dist[i][0] == 0 && dist[i][0]+dist[i][1]+dist[i][2]!=0 && dist[i][0]+dist[i][1]+dist[i][2]-1<m)
                mini = min(mini,quick_price[dist[i][0]+dist[i][1]+dist[i][2]-1]);
            else if(dist[i][0] == 0 && dist[i][0]+dist[i][1]+dist[i][2]==0)
                mini = 0;
        }
        cout<<mini<<"\n";
    }
    return 0;
}