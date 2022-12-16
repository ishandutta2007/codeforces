#include<bits/stdc++.h>
using namespace std;
const int nmax=2e5+42;
struct edge
{
int to,index,flow;
bool dir;
};
vector<edge> adj[nmax];
int n,m;
int outp[nmax];
edge make_edge(int to,int index,int flow,bool dir)
{
    edge e;
    e.to=to;
    e.index=index;
    e.flow=flow;
    e.dir=dir;
    return e;
}
queue<int> q;
bool in[nmax];
int f[nmax];
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cout.tie();

cin>>n>>m;
int a,b,c;
for(int i=1;i<=m;i++)
{
    cin>>a>>b>>c;
    adj[a].push_back(make_edge(b,i,c,0));
    adj[b].push_back(make_edge(a,i,c,1));
    f[a]+=c;
    f[b]+=c;
}
for(int i=2;i<n;i++)
{
    assert(f[i]%2==0);
    f[i]=f[i]/2;
}
//cout<<"f: ";for(int i=1;i<=n;i++)cout<<f[i]<<" ";cout<<endl;
q.push(1);
in[1]=1;
while(q.size())
{
    int now=q.front();
    //cout<<"now= "<<now<<endl;
    q.pop();
    for(auto k:adj[now])
        if(in[k.to]==0)
        {
        //cout<<k.to<<" "<<k.index<<" "<<k.flow<<" "<<k.dir<<endl;
        f[k.to]=f[k.to]-k.flow;
        outp[k.index]=k.dir;
        //cout<<f[k.to]<<endl;
            if(f[k.to]==0)
            {
            q.push(k.to);
            in[k.to]=1;
            }
        }
}
for(int i=1;i<=m;i++)cout<<outp[i]<<endl;
return 0;
}