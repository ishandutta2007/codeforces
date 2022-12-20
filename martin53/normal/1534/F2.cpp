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

vector<int> adj_back[nmax];

pair<int,int> direct[nmax];

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
                //cout<<u<<" -> "<<v<<endl;

                adj_back[v].push_back(u);
            }
        }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(sand[i][j]=='#')
            {
                int me=component[hsh(i,j)];

                direct[me].first=min(direct[me].first,j);
                direct[me].second=max(direct[me].second,j);
            }

}

pair<int,int> intervals[nmax];

pair<int,int> ask(int node)
{
    if(intervals[node]!=make_pair(0,0))return intervals[node];

    int mini=direct[node].first,maxi=direct[node].second;

    for(auto w:adj_back[node])
    {
        pair<int,int> help=ask(w);

        mini=min(mini,help.first);
        maxi=max(maxi,help.second);
    }

    intervals[node]={mini,maxi};

    return intervals[node];
}

vector< pair<int,int> > seen;

bool cmp(pair<int,int> a,pair<int,int> b)
{
    if(a.first!=b.first)return a<b;

    return a.second>b.second;
}
void compress()
{
    vector< pair<int,int> > help={};

    sort(seen.begin(),seen.end(),cmp);

    for(auto w:seen)
    {
        while(help.size()&&help.back().second>=w.second)help.pop_back();

        help.push_back(w);
    }

    seen=help;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    cin>>n>>m;

    for(int i=1;i<=n*m;i++)
        direct[i]={1e9,0};

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

    set<int> marked={};

    for(int j=1;j<=m;j++)
        if(inp[j])
        {
            int i=n;

            while(inp[j])
            {
                if(sand[i][j]=='#')inp[j]--;
                i--;
            }

            i++;

            marked.insert(component[hsh(i,j)]);
        }

    for(auto w:marked)
    {
        seen.push_back(ask(w));

        //cout<<w<<" -> "<<seen.back().first<<" "<<seen.back().second<<endl;
    }

    compress();

    //cout<<"seen: "<<endl;for(auto w:seen)cout<<w.first<<" "<<w.second<<endl;

    int outp=0,covered=0;

    for(auto w:seen)
    {
        if(w.first>covered)
        {
            outp++;

            covered=w.second;
        }
    }

    printf("%i\n",outp);
    /*
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)cout<<component[hsh(i,j)]<<" ";cout<<endl;
    }
    */

    return 0;
}