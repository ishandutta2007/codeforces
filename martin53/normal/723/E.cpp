#include<bits/stdc++.h>
using namespace std;
const int nmax=2e2+5;
int n,m;
set< pair<int/*node*/,int/*index*/> > adj[nmax];
int comp[nmax];
int SZ[nmax];
map< pair<int,int>,bool > fake,emp;
void make_empty()
{
    memset(comp,0,sizeof(comp));
    for(int i=1;i<nmax;i++)adj[i].clear();
    memset(SZ,0,sizeof(SZ));
    fake=emp;
}
void dfs(int node,int c)
{
    if(comp[node])return;
    comp[node]=c;
    for(auto k:adj[node])
        dfs(k.first,c);
}

stack<int> tour,em;

void dfs_second(int node)
{
    while(SZ[node])
    {
        set< pair<int/*node*/,int/*index*/> >::iterator it=adj[node].begin();
        pair<int/*node*/,int/*index*/> k=*it;
        SZ[node]--;
        SZ[k.first]--;

        adj[node].erase({k});
        adj[k.first].erase({node,k.second});

        dfs_second(k.first);
    }

tour.push(node);
}

void solve()
{
    make_empty();

    cin>>n>>m;
    int a,b;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        adj[a].insert({b,i});
        adj[b].insert({a,i});
        SZ[a]++;
        SZ[b]++;
    }
    int c=0;
    for(int i=1;i<=n;i++)
        if(comp[i]==0)
        {
        c++;
        dfs(i,c);
        }

    int ans=n;

    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(SZ[i]%2==1&&SZ[j]%2==1&&comp[i]==comp[j])
            {
            ans=ans-2;
            m++;
            adj[i].insert({j,m});
            adj[j].insert({i,m});
            fake[{i,j}]=1;
            fake[{j,i}]=1;

            SZ[i]++;
            SZ[j]++;
            }

    cout<<ans<<endl;
    for(int i=1;i<=n;i++)
        if(SZ[i])
        {
        tour=em;
        dfs_second(i);

        int prev=tour.top();
        tour.pop();

            while(tour.size())
            {
                if(fake[{tour.top(),prev}])
                {
                fake[{tour.top(),prev}]=0;
                fake[{prev,tour.top()}]=0;
                }
                else cout<<tour.top()<<" "<<prev<<endl;
                prev=tour.top();
                tour.pop();
            }
        }
        //cout<<"---"<<endl;
}
int main()
{
int t;
cin>>t;
for(int i=1;i<=t;i++)
    solve();

return 0;
}