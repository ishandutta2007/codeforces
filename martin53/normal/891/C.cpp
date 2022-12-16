#include<bits/stdc++.h>
using namespace std;
const int nmax=5e5+42;
int n,m;
struct edges
{
int u,v,w;
int id_original;
};
edges inp[nmax],all[nmax];
bool cmp(edges a,edges b)
{
    return a.w<b.w;
}
int parent[nmax];
int root(int node)
{
    if(parent[node]==node)return node;
    parent[node]=root(parent[node]);
    return parent[node];
}
int max_cost=0;

int group[nmax],id=0;
bool can_be[nmax];

bool cmp2(int edge_1,int edge_2)
{
    return group[edge_1]<group[edge_2];
}
int sz,test[nmax];

map< pair<int,int>, vector<int> > types;
int main()
{
scanf("%i%i",&n,&m);

for(int i=1;i<=m;i++)
{
    scanf("%i%i%i",&inp[i].u,&inp[i].v,&inp[i].w);
    inp[i].id_original=i;
    all[i]=inp[i];
}
sort(all+1,all+m+1,cmp);
/*
cout<<"---"<<endl;
for(int j=1;j<=m;j++)cout<<all[j].u<<" "<<all[j].v<<" "<<all[j].w<<endl;
*/
for(int i=1;i<=n;i++)parent[i]=i;

for(int i=1;i<=m;i++)
{
    int j=i;
    while(j<=m&&all[i].w==all[j].w)j++;
    j--;

    //cout<<"i= "<<i<<" j= "<<j<<endl;

    max_cost=all[i].w;

    types={};
    /*
    for(int i=1;i<=n;i++)
        cout<<root(i)<<" ";cout<<endl;
    */
    for(int k=i;k<=j;k++)
    {
        if(root(all[k].u)!=root(all[k].v))
        {
        can_be[all[k].id_original]=1;
        pair<int,int> work={root(all[k].u),root(all[k].v)};
        if(work.first>work.second)swap(work.first,work.second);

        //cout<<all[k].u<<" "<<all[k].v<<" with work= "<<work.first<<" "<<work.second<<endl;

        types[work].push_back(all[k].id_original);
        }
    }
    for(auto w:types)
    {
        id++;
        for(auto k:w.second)
            group[k]=id;
    }

    for(int k=i;k<=j;k++)
        parent[root(all[k].u)]=root(all[k].v);

    i=j;
}
/*
for(int j=1;j<=m;j++)cout<<group[j]<<" ";cout<<endl;
for(int j=1;j<=m;j++)cout<<can_be[j]<<" ";cout<<endl;
*/
for(int i=1;i<=n;i++)parent[i]=i;

int q;
scanf("%i",&q);

for(int i=1;i<=q;i++)
{
    scanf("%i",&sz);
    for(int j=1;j<=sz;j++)scanf("%i",&test[j]);
    bool can=1;

    for(int j=1;j<=sz;j++)
        if(can_be[test[j]]==0)
        {
            can=0;
            break;
        }

    sort(test+1,test+sz+1,cmp2);
    for(int j=2;j<=sz;j++)
        if(group[test[j-1]]==group[test[j]])can=0;

    for(int j=1;j<=sz;j++)
        if(root(inp[test[j]].u)==root(inp[test[j]].v))can=0;
        else parent[root(inp[test[j]].u)]=root(inp[test[j]].v);

    for(int j=1;j<=sz;j++)
        parent[inp[test[j]].u]=inp[test[j]].u,
        parent[inp[test[j]].v]=inp[test[j]].v;

    if(can)printf("YES\n");
    else printf("NO\n");
}

return 0;
}