#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42;

int n;
vector<int> adj[nmax];

int SZ[nmax];

set< pair<int/*size*/,int/*node*/> > children,parents,other;

void dfs_sizes(int node)
{
    SZ[node]=1;
    for(auto k:adj[node])
    {
        dfs_sizes(k);
        SZ[node]+=SZ[k];
    }
}

int output[nmax];
int root=0;

void add(int node)
{
    children.insert({SZ[node],node});
    other.erase({SZ[node],node});
    for(auto k:adj[node])
        add(k);
}
void solve(int node)
{
    if(adj[node].size()==0)
    {
        output[node]=n-1;
        children.insert({SZ[node],node});
        other.erase({SZ[node],node});
        return;
    }

    int big=0;
    for(auto k:adj[node])
        if(SZ[k]>SZ[big])big=k;

    parents.insert({SZ[node],node});
    other.erase({SZ[node],node});

    for(auto k:adj[node])
        if(k!=big)
        {
        solve(k);
        for(auto p:children)
            other.insert(p);
        children={};
        }

    solve(big);

    parents.erase({SZ[node],node});
    other.insert({SZ[node],node});

    int over=n-1;
    for(auto k:adj[node])
        over=over-SZ[k];

    /*
    cout<<"before query: "<<endl;
    cout<<"node= "<<node<<endl;
    cout<<"children: "<<endl;
    for(auto k:children)cout<<k.first<<" "<<k.second<<endl;
    cout<<"parents: "<<endl;
    for(auto k:parents)cout<<k.first<<" "<<k.second<<endl;
    cout<<"other: "<<endl;
    for(auto k:other)cout<<k.first<<" "<<k.second<<endl;
    cout<<"big= "<<big<<endl;
    cout<<"---"<<endl;
    */

    if(SZ[big]>=over)
    {
        int ok=SZ[big],not_ok=0;
        for(auto k:adj[node])
            if(k!=big)not_ok=max(not_ok,SZ[k]);
        if(over)not_ok=max(not_ok,over);
        not_ok--;

        int mini=1e9;
        if(over)mini=over;
        for(auto k:adj[node])
            if(k!=big)mini=min(mini,SZ[k]);

        //cout<<node<<" -> "<<ok<<" "<<not_ok<<" "<<mini<<" "<<over<<endl;
        while(ok-not_ok>1)
        {
            int av=(ok+not_ok)/2;
            set< pair<int/*size*/,int/*node*/> >::iterator it;
            it=children.lower_bound({SZ[big]-av,0});

            if(it!=children.end()&&(*it).first+mini<=av)ok=av;
            else not_ok=av;
        }
        output[node]=ok;
        for(auto k:adj[node])
            if(k!=big)
                add(k);

        children.insert({SZ[node],node});
        other.erase({SZ[node],node});
    }
    else//over is the problem
    {
        for(auto k:adj[node])
            if(k!=big)
                add(k);

        children.insert({SZ[node],node});
        other.erase({SZ[node],node});

        int ok=over,not_ok=0;
        for(auto k:adj[node])
            not_ok=max(not_ok,SZ[k]);
        not_ok--;

        int mini=n;
        for(auto k:adj[node])
            mini=min(mini,SZ[k]);
        //cout<<node<<" : "<<ok<<" "<<not_ok<<" "<<mini<<" "<<over<<endl;
        while(ok-not_ok>1)
        {
            int av=(ok+not_ok)/2;

            set< pair<int/*size*/,int/*node*/> >::iterator it;
            it=other.lower_bound({over-av,0});

            if(it!=other.end()&&(*it).first+mini<=av){ok=av;continue;}

            it=parents.lower_bound({over-av+SZ[node],0});

            if(it!=parents.end()&&(*it).first-SZ[node]+mini<=av)ok=av;
            else not_ok=av;
        }

        output[node]=ok;
    }

    /*
    cout<<"node= "<<node<<endl;
    cout<<"children: "<<endl;
    for(auto k:children)cout<<k.first<<" "<<k.second<<endl;
    cout<<"parents: "<<endl;
    for(auto k:parents)cout<<k.first<<" "<<k.second<<endl;
    cout<<"other: "<<endl;
    for(auto k:other)cout<<k.first<<" "<<k.second<<endl;
    cout<<"---"<<endl;
    */
}
int main()
{
    scanf("%i",&n);

    int u,v;
    for(int i=1;i<=n;i++)
    {
        scanf("%i%i",&u,&v);
        if(u)adj[u].push_back(v);
        else root=v;
    }

    dfs_sizes(root);

    for(int i=1;i<=n;i++)
        other.insert({SZ[i],i});

    solve(root);

    if(adj[root].size()==1)output[root]=n-1;

    for(int i=1;i<=n;i++)
        printf("%i\n",output[i]);
    return 0;
}