#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
stack<int> st;
vector<int> adj[maxn] , ans;
int a[maxn];
int main()
{
    int n , m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a , b;
        cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(!a[i])
            st.push(i) , ans.pb(i);
    }
    while(!st.empty())
    {
        int k = st.top();
        st.pop();
        for(auto u : adj[k])
        {
            a[u]--;
            if(!a[u])
                st.push(u) , ans.pb(u);
        }
    }
    cout << ans.size() << endl;
    for(auto u : ans)
        cout << u + 1 << " ";
}