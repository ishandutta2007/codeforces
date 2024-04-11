#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42;

struct edge
{
    int u,v,c;
};

vector< edge > outp;

void add_edge(int u,int v,int c)
{
    edge cur;
    cur.u=u;
    cur.v=v;
    cur.c=c;
    outp.push_back(cur);
}
int n,m;

int l,r;

void build()
{
    n=22;

    for(int i=21;i>=2;i--)
    {
        add_edge(i,n,1);
    }

    for(int i=21;i>=2;i--)
        for(int j=i+1;j<n;j++)
            add_edge(i,j,1<<(21-j));
}

void solve()
{
    if(l>r)return;

    for(int i=2;i<=21;i++)
    {
        int SZ=1<<(21-i);

        if(l+SZ-1<=r)
        {
            add_edge(1,i,l-1);
            l=l+SZ;
        }

        //cout<<i<<" "<<l<<" "<<r<<" SZ= "<<SZ<<endl;
    }

    assert(l==r+1);
}

vector< pair<int,int> > adj[nmax];

map<int,int> seen;

void dfs(int node,int sz)
{
    //cout<<"dfs "<<node<<" "<<sz<<endl;

    if(node==n)
    {
        seen[sz]++;
        return;
    }

    for(auto w:adj[node])
        dfs(w.first,w.second+sz);
}
void print()
{
    printf("YES\n");
    printf("%i %i\n",n,outp.size());

    for(auto w:outp)
    {
        printf("%i %i %i\n",w.u,w.v,w.c);
        adj[w.u].push_back({w.v,w.c});
    }

    exit(0);

    dfs(1,0);

    cout<<seen.size()<<endl;

    l=1;

    for(int i=l;i<=r;i++)
    {
        if(seen[i]!=1)cout<<"wrong "<<i<<" "<<seen[i]<<endl;
    }

    for(auto w:seen)
        cout<<w.first<<" -> "<<w.second<<endl;

    exit(0);
}

int main()
{
    scanf("%i%i",&l,&r);

    build();

    if(l!=1)solve();
    else
    {
        add_edge(1,n,1);

        l++;

        solve();

        l--;
    }

    print();

    return 0;
}