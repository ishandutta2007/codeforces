#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e2 + 20;
string s[maxn] , ans[maxn];
set<string> st;
set<int> adj[maxn];
int k;
bool visited[maxn];
bool f(int v)
{
    for(int i = v; i < v + k; i++)
    {
        for(auto x : adj[i])
            if(x >= v && x <= v + k)
                return 1;
    }
    return 0;
}
string make()
{
    string s = "AAAAA";
    for(int i = 1; i < 5; i++)
        s[i] = ('a' + (rand() % 26));
    if(st.find(s) != st.end())
    {
        return make();
    }
    st.insert(s);
    return s;
}
void dfs(int v , string s)
{
    if(visited[v])
        return;
    visited[v] = 1;
    ans[v] = s;
    for(auto u : adj[v])
        dfs(u , s);
}
int main()
{
    srand(time(NULL));
    int n;
    cin >> n >> k;
    for(int i = 0; i < n - k + 1; i++)
        cin >> s[i];
//    for(int i = 0; i < n; i++)
  //      for(int j = 0; j < n; j++)
    //        if(i != j)
      //          adj[i].insert(j);
    for(int i = 0; i < n - k + 1; i++)
    {
        if(s[i] == "NO" && !f(i))
        {
            adj[i].insert(i + k - 1);
        }
    }
    for(int i = 0; i < n; i++)
    {
        dfs(i , make());
        cout << ans[i] << " ";
    }
}