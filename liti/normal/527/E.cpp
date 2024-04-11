#include<bits/stdc++.h>

using namespace std;

const int Maxn = 100 * 1000 + 10;
int n, m, cnt;
vector<bool> mark[Maxn];
vector<int> adj[Maxn], ind[Maxn];
int ptr[Maxn];
vector<pair<int, int> > ans;

void dfsEu(int v)
{
    for(; ptr[v] < adj[v].size(); ptr[v] ++)
    {
		int i = ptr[v];
        if(! mark[v][i])
        {
            mark[v][i] = true;
            mark[adj[v][i]][ind[v][i]] = true;
            dfsEu(adj[v][i]);
            if(cnt % 2 == 0)
                ans.push_back(make_pair(adj[v][i], v));
            else
                ans.push_back(make_pair(v, adj[v][i]));
            cnt ++;
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    int u, v;
    for(int i = 0; i < m; i ++)
    {
        scanf("%d%d", &u, &v);
        u --;
        v --;
        if(u == v)
            ind[u].push_back(adj[v].size() + 1);
        else
            ind[u].push_back(adj[v].size());
        ind[v].push_back(adj[u].size());
        adj[u].push_back(v);
        adj[v].push_back(u);
        mark[v].push_back(false);
        mark[u].push_back(false);
    }
    int carry = -1, j = 0, num = 0;
    while(j < n)
    {
        if(adj[j].size() % 2 == 1)
        {
            if(carry >= 0)
            {
                ind[carry].push_back(adj[j].size());
                ind[j].push_back(adj[carry].size());
                adj[carry].push_back(j);
                adj[j].push_back(carry);
                mark[j].push_back(false);
                mark[carry].push_back(false);
                num ++;
                carry = -1;
            }
            else
                carry = j;
        }
        j ++;
    }
    if((m + num) % 2 == 1)
    {
        ind[0].push_back(adj[0].size() + 1);
        ind[0].push_back(adj[0].size());
        adj[0].push_back(0);
        adj[0].push_back(0);
        mark[0].push_back(false);
        mark[0].push_back(false);
    }
    dfsEu(0);
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i ++)
        printf("%d %d \n", ans[i].first + 1, ans[i].second + 1);
    return 0;
}