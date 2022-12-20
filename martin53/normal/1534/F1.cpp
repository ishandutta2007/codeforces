#include<bits/stdc++.h>
using namespace std;

const int nmax=4e5+42;

vector<char> sand[nmax];

int inp[nmax];

int n,m,S;

vector<int> adj[nmax],trav[nmax];

bool in(int l,int r,int val)
{
    return l<=val&&val<=r;
}

int hsh(int x,int y)
{
    return (x-1)*m+y;
}
void add_edge(int x1,int y1,int x2,int y2)
{
    if(in(1,n,x1)==0||in(1,m,y1)==0||in(1,n,x2)==0||in(1,m,y2)==0)return;

    int LHS=hsh(x1,y1);
    int RHS=hsh(x2,y2);

    adj[LHS].push_back(RHS);
}

bool been[nmax];

stack<int> st;

void dfs(int node)
{
    if(been[node])return;

    been[node]=1;

    for(auto w:adj[node])
        dfs(w);

    st.push(node);
}

int component[nmax],pointer=0;

void dfs_back(int node)
{
    if(component[node])return;

    component[node]=pointer;

    for(auto w:trav[node])
        dfs_back(w);
}

int in_degree[nmax];

void scc()
{
    for(int i=1;i<=S;i++)
        if(been[i]==0)dfs(i);

    while(st.size())
    {
        int cur=st.top();

        st.pop();

        pointer++;

        dfs_back(cur);
    }

    for(int i=1;i<=S;i++)
        for(auto j:adj[i])
        {
            int u=component[i];
            int v=component[j];

            //cout<<"i= "<<i<<" j= "<<j<<" u= "<<u<<" v= "<<v<<endl;

            if(u!=v)
            {
                in_degree[v]=1;
            }
        }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    cin>>n>>m;

    S=n*m;

    for(int i=1;i<=n;i++)
    {
        sand[i].resize(m+2);
        sand[i][0]='.';
        sand[i][m+1]='.';

        for(int j=1;j<=m;j++)cin>>sand[i][j];
    }

    for(int i=1;i<=m;i++)cin>>inp[i];

    for(int j=1;j<=m;j++)
    {
        bool on=0;

        int prv=0;

        for(int i=1;i<=n;i++)
        {
            if(sand[i][j]=='#')
            {
                if(prv)
                {
                    add_edge(prv,j,i,j);

                    if(prv==i-1)add_edge(i,j,prv,j);
                }
                prv=i;
            }

            if(prv&&sand[i][j-1]=='#')add_edge(prv,j,i,j-1);
            if(prv&&sand[i][j+1]=='#')add_edge(prv,j,i,j+1);
        }
    }

    for(int i=1;i<=n*m;i++)
        for(auto j:adj[i])
            trav[j].push_back(i);

    scc();

    set<int> use={};

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(sand[i][j]=='#')
            {
                int cur=component[hsh(i,j)];

                if(in_degree[cur]==0)use.insert(cur);
            }

    cout<<use.size()<<endl;

    /*
    cout<<"use: ";for(auto w:use)cout<<w<<" ";cout<<endl;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)cout<<component[hsh(i,j)]<<" ";cout<<endl;
    }
    */

    return 0;
}