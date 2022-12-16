#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42,dmax=50;

vector<int> adj[nmax*dmax],trav[nmax*dmax];

int n,d;

int hsh(int pos,int t)
{
    return t+(pos-1)*d;
}

bool been[nmax*dmax];

stack<int> st;

stack< pair<int,int> > iterative;

void dfs_scc(int node_)
{
    iterative.push({node_,0});

    while(iterative.size())
    {
        pair<int,int> tp=iterative.top();
        iterative.pop();

        if(tp.second==1)
        {
            st.push(tp.first);
            continue;
        }

        if(been[tp.first])continue;
        been[tp.first]=1;

        iterative.push({tp.first,1});

        for(auto k:adj[tp.first])
            if(been[k]==0)iterative.push({k,0});
    }
}

int comp[nmax*dmax],pointer=0;

void dfs_trav(int node_)
{
    iterative.push({node_,0});

    while(iterative.size())
    {
        pair<int,int> tp=iterative.top();
        iterative.pop();

        if(been[tp.first])continue;
        been[tp.first]=1;

        comp[tp.first]=pointer;
        for(auto k:trav[tp.first])
            if(been[k]==0)iterative.push({k,0});
    }
}

int SZ_comp[nmax*dmax];

int inp[nmax*dmax];

int dp[nmax*dmax];

int rec(int node)
{
    if(dp[node]!=-1)return dp[node];

    dp[node]=0;

    for(auto k:trav[node])
        dp[node]=max(dp[node],rec(k));

    dp[node]+=SZ_comp[node];
    return dp[node];
}

pair<int,int> active[nmax*dmax];

int in[nmax];

int main()
{
    int m;
    scanf("%i%i%i",&n,&m,&d);

    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%i%i",&u,&v);

        for(int t=0;t<d;t++)
        {
            adj[hsh(u,t)].push_back(hsh(v,(t+1)%d));
            trav[hsh(v,(t+1)%d)].push_back(hsh(u,t));

            //cout<<u<<" "<<v<<" "<<t<<" -> "<<hsh(u,t)<<" "<<hsh(v,(t+1)%d)<<endl;
        }
    }

    /*
    for(int i=0;i<n*d;i++)
    {
        cout<<i<<" -> ";for(auto j:adj[i])cout<<j<<" ";cout<<endl;
    }
    */

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<d;j++)
        {
            char c=getchar();
            while(c!='0'&&c!='1')c=getchar();

            inp[hsh(i,j)]=c-'0';
        }
    }

    for(int i=0;i<n*d;i++)
        if(been[i]==0)
        {
            dfs_scc(i);
        }

    memset(been,0,sizeof(been));

    for(int i=0;i<n*d;i++)
    {
        int tp=st.top();
        st.pop();

        if(been[tp]==0)
        {
            pointer++;

            dfs_trav(tp);
        }
    }

    /*
    for(int i=0;i<n*d;i++)
        cout<<i<<" -> "<<comp[i]<<endl;
    */

    for(int i=0;i<n*d;i++)
        active[i]={comp[i],i};

    sort(active,active+n*d);

    for(int i=0;i<n*d;i++)
    {
        int j=i;
        while(j<n*d&&active[i].first==active[j].first)j++;

        j--;

        int add_now=0;

        //cout<<i<<" "<<j<<" : ";

        for(int k=i;k<=j;k++)
        {
            int cur=active[k].second;

            //cout<<cur<<" "<<inp[cur]<<" "<<cur/d+1<<endl;

            if(inp[cur])
            {
                if(in[cur/d]==0)add_now++;
                in[cur/d]=1;
            }
        }

        for(int k=i;k<=j;k++)
        {
            int cur=active[k].second;

            in[cur/d]=0;
        }


        i=j;

        SZ_comp[active[i].first]=add_now;

        //cout<<active[i].first<<" -> "<<in.size()<<endl;
    }

    for(int i=0;i<n*d;i++)trav[i]={};

    for(int i=0;i<n*d;i++)
        for(auto j:adj[i])
            if(comp[i]!=comp[j])
            {
                //cout<<"trav "<<comp[i]<<" "<<comp[j]<<endl;

                trav[comp[i]].push_back(comp[j]);
            }
    memset(dp,-1,sizeof(dp));

    printf("%i\n",rec(comp[0]));
    return 0;
}