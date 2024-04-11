#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
const int mod = 1e9 + 7;
vector<int> in[maxn] , out[maxn] , topol;
bool visited[maxn];
ll a , b , color[maxn] , c;
void dfs(int v)
{
    visited[v] = 1;
    for(auto u : out[v])
        if(!visited[u])
            dfs(u);
    topol.pb(v);
}
void sfd(int v)
{
    if(color[v] != -1)
        return;
    color[v] = c;
    for(auto u : in[v])
        sfd(u);
}
int main()
{
    int n;
    scanf("%d", &n);
    fill(color , color + maxn , -1);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &a);
            if(!a || i == j)
                continue;
            out[i].pb(j);
            in[j].pb(i);
        }
    }
    for(int i = 0; i < n; i++)
        if(!visited[i])
            dfs(i);
    for(int i = n - 1; i > -1; i--)
    {
        if(color[topol[i]] == -1)
            c++ , sfd(topol[i]);
    }
    if(c == 1)
        cout << "YES";
    else
        cout << "NO";
}