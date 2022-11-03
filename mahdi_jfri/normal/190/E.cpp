#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 5e5 + 20;
vector<int> adj[maxn] , cmp[maxn];
stack<int> st;
int res , q[maxn] , h , t , x[maxn];
void bfs(int src)
{
    h = t = 0;
    st.pop();
    q[h++] = src;
    while(h > t)
    {
        cmp[res].pb(q[t]);
        int v = q[t];
        t++;
        stack<int> stt;
        for(int u : adj[v])
            x[u] = v;
        while(st.size())
        {
            if(x[st.top()] == v)
                stt.push(st.top());
            else
                q[h++] = st.top();
            st.pop();
        }
        st.swap(stt);
    }
}
int main()
{

    int n , m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        int a , b;
        scanf("%d%d", &a, &b);
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    for(int i = 0; i < n; i++)
        st.push(i);
    while(!st.empty())
    {
        res++;
        bfs(st.top());
    }
    printf("%d\n", res);
    for(int i = 1; i <= res; i++)
    {
        printf("%d ", (int)cmp[i].size());
        for(int u : cmp[i])
            printf("%d ", u + 1);
        printf("\n");
    }
}