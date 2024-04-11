#include<bits/stdc++.h>
using namespace std;
const int nmax=1e3+42,mmax=3e3+42;
struct edge
{
int to,l,r;
};
int n,m;
vector< edge > adj[nmax];
edge make_edge(int to,int l,int r)
{
    edge e;
    e.to=to;
    e.l=l;
    e.r=r;
    return e;
}
int l_s[mmax],diff[mmax];
int l_,r_;
bool used[nmax];
void dfs(int node)
{
    if(used[node])return;
    used[node]=1;
    for(auto k:adj[node])
        if(k.l<=l_&&r_<=k.r)dfs(k.to);
}
bool test(int l,int r)
{
    l_=l;
    r_=r;
    memset(used,0,sizeof(used));
    dfs(1);
    //cout<<l<<" "<<r<<" -> "<<used[n]<<endl;
    return used[n];
}
bool can(int dist)
{
    //cout<<"can "<<dist<<endl;
    for(int i=1;i<=m;i++)
        if(test(l_s[i],l_s[i]+dist-1))return 1;
    return 0;
}
int main()
{
scanf("%i%i",&n,&m);
int a,b,l,r;
for(int i=1;i<=m;i++)
{
    scanf("%i%i%i%i",&a,&b,&l,&r);
    adj[a].push_back(make_edge(b,l,r));
    adj[b].push_back(make_edge(a,l,r));
    l_s[i]=l;
    diff[i]=r-l+1;
}
sort(diff+1,diff+m+1);
int ok=0,not_ok=1e6+1;
while(not_ok-ok>1)
{
    int av=(ok+not_ok)/2;
    if(can(av))ok=av;
    else not_ok=av;
}
if(ok==0)printf("Nice work, Dima!\n");
else printf("%i\n",ok);
return 0;
}