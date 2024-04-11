#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
set<int> adj[maxn] , st;
int c[maxn] , t[maxn];
bool is[maxn];
void check(int v , int p = -1 , bool b = 1)
{
    if(b)
        for(auto u : adj[v])
        {
            check(u , v , 0);
        }
    else
    {
        for(auto u : adj[v])
        {
            if(u == p)
                continue;
            if(c[u] != c[v])
            {
                cout << "NO";
                exit(0);
            }
            check(u , v , 0);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        int a , b;
        cin >> a >> b;
        adj[--a].insert(--b);
        adj[b].insert(a);
        if(adj[a].size() == 1)
            st.insert(a);
        else
            st.erase(a);
        if(adj[b].size() == 1)
            st.insert(b);
        else
            st.erase(b);
    }
    for(int i = 0; i < n; i++)
        cin >> c[i];
    while(!st.empty())
    {
        int a = *st.begin();
        st.erase(st.begin());
        if(c[a] != c[*adj[a].begin()])
        {
            check(*adj[a].begin());
            cout << "YES\n" << (*(adj[a].begin())) + 1;
            exit(0);
        }
        else
        {
            adj[*adj[a].begin()].erase(a);
            if(adj[*adj[a].begin()].size() == 1)
                st.insert(*adj[a].begin());
        }
    }
    cout << "YES\n" << 1;
}