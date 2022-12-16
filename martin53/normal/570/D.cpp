#include<bits/stdc++.h>
using namespace std;
const int nmax=5e5+42;
int n,m;
vector<int> adj[nmax];
char letter[nmax];
int in[nmax];
int out[nmax];
int de[nmax];
int t=0;
vector< pair<int/*time*/,int/*index*/> > seen[nmax];
void dfs(int node,int parent,int depth)
{
    de[node]=depth;
    t++;
    seen[depth].push_back({t,node});
    in[node]=t;
    for(auto k:adj[node])
        if(k!=parent)
        dfs(k,node,depth+1);
    out[node]=t;
}
struct query
{
int v,h,index;
};
query q[nmax];
bool cmp(query a,query b)
{
    return a.h<b.h;
}
bitset<26> tree[4*nmax];
void build(int node,int level,int l,int r)
{
    if(l==r)
    {
        tree[node]=tree[node]^tree[node];
        tree[node][letter[seen[level][l].second]-'a']=1;
        return;
    }
    int av=(l+r)/2;
    build(node*2,level,l,av);
    build(node*2+1,level,av+1,r);
    tree[node]=tree[node*2]^tree[node*2+1];
}
bitset<26> quer(int node,int l,int r,int lq,int rq)
{
    if(l==lq&&r==rq)return tree[node];
    bitset<26> ret;
    ret=ret^ret;
    int av=(l+r)/2;
    if(lq<=av)ret=ret^quer(node*2,l,av,lq,min(av,rq));
    if(av<rq)ret=ret^quer(node*2+1,av+1,r,max(av+1,lq),rq);
    return ret;
}
bitset<nmax> ok;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cin>>n>>m;
int p;
for(int i=2;i<=n;i++)
{
    cin>>p;
    adj[p].push_back(i);
    adj[i].push_back(p);
}
dfs(1,0,1);
for(int i=1;i<=n;i++)cin>>letter[i];

for(int i=1;i<=m;i++)
{
    cin>>q[i].v>>q[i].h;
    q[i].index=i;
}
sort(q+1,q+m+1,cmp);

for(int i=1;i<=m;i++)
{
    int j=i,val=q[i].h;
    while(j<=m&&q[i].h==q[j].h)j++;
    j--;

    if(seen[val].size())
    {
        build(1,val,0,seen[val].size()-1);
        for(int k=i;k<=j;k++)
        {
            //cout<<q[k].v<<" "<<q[k].h<<" "<<q[k].index<<endl;
            if(de[q[k].v]>q[k].h){ok[q[k].index]=1;continue;}
            int s=lower_bound(seen[val].begin(),seen[val].end(),make_pair(in[q[k].v],-1))-seen[val].begin();
            int t=upper_bound(seen[val].begin(),seen[val].end(),make_pair(out[q[k].v],n+1))-seen[val].begin()-1;

            //cout<<"s= "<<s<<" t= "<<t<<endl;

            if(s<=t)
            {
                if(quer(1,0,seen[val].size()-1,s,t).count()<=1)ok[q[k].index]=1;
            }
            else ok[q[k].index]=1;
        }
    }
    else for(int k=i;k<=j;k++)ok[q[k].index]=1;

    i=j;
}
for(int i=1;i<=m;i++)
    cout<<(ok[i]?"Yes":"No")<<"\n";
cout<<endl;
return 0;
}