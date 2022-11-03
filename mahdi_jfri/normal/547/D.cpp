#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push
#define mp make_pair
const int maxn = 2e5 + 100;
stack<pair<int , int> > adj[2 * maxn];
vector<int> vertex , ans;
bool visited[2 * maxn] , check[2 * maxn] , check2[2 * maxn] , color[maxn];
int tmp = -1 , a ,b;
map<pair<int , int> , int> ind;
void dfs(int v)
{
    if(!adj[v].size())
        return;


    check2[v] = 1;


    while(!adj[v].empty())
    {

        pair<int , int> e = adj[v].top();

        adj[v].pop();

        if(!visited[e.second])
        {
            if(v <= 2e5)
                color[e.second] = 1;
            else
                color[e.second] = 0;

            visited[e.second] = 1;

            dfs(e.first);
        }
    }
}
void add(int a)
{
    if(!check[a])
        vertex.push_back(a);

    check[a] = 1;
}
int main()
{
    int n;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d%d", &a, &b);

        b += maxn;

        if(!check[a])
            vertex.push_back(a);

        if(!check[b])
            vertex.push_back(b);

        check[a] = check[b] = 1;

        adj[a].pb(mp(b , i));

        adj[b].pb(mp(a , i));
    }
    int m = n;
    for(auto v : vertex)
        if(adj[v].size() & 1)
        {
            if(tmp == -1)
                tmp = v;
            else
            {
                adj[v].pb({tmp , m});

                adj[tmp].pb({v , m});

                tmp = -1;
                m++;
            }
        }
    for(auto v : vertex)
        if(!check2[v])
            dfs(v);
    for(int i = 0; i < n; i++)
    {
        if(color[i])
            printf("r");
        else
            printf("b");
    }
}