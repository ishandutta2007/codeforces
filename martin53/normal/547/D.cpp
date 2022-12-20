#include<bits/stdc++.h>
using namespace std;
const int nmax=2*1e5+42;
int n;
pair<int,int> inp[nmax];
vector<int> adj[nmax];
map< pair<int,int>, int> there;
bool cmp(pair<int,int> a,pair<int,int> b)
{
    if(a.second!=b.second)return a.second<b.second;
    return a.first<b.first;
}
void connect(int a,int b)
{
    adj[a].push_back(b);
    adj[b].push_back(a);
}
int been[nmax];
void dfs(int node,int c)
{
    if(been[node]!=-1)
    {
        assert(been[node]==c);
        return;
    }
    been[node]=c;
    for(auto k:adj[node])
        dfs(k,!c);
}
int main()
{
scanf("%i",&n);
for(int i=1;i<=n;i++)
{
    scanf("%i%i",&inp[i].first,&inp[i].second);
    there[inp[i]]=i;
    been[i]=-1;
}

sort(inp+1,inp+n+1);

for(int i=1;i<=n;i++)
{
    int j=i;
    while(j<=n&&inp[i].first==inp[j].first)j++;
    for(int k=i+1;k<j;k=k+2)
        connect(there[inp[k]],there[inp[k-1]]);
    j--;
    i=j;
}

sort(inp+1,inp+n+1,cmp);

for(int i=1;i<=n;i++)
{
    int j=i;
    while(j<=n&&inp[i].second==inp[j].second)j++;
    for(int k=i+1;k<j;k=k+2)
        connect(there[inp[k]],there[inp[k-1]]);
    j--;
    i=j;
}

for(int i=1;i<=n;i++)
    if(been[i]==-1)dfs(i,0);

for(int i=1;i<=n;i++)
    if(been[i])printf("b");
    else printf("r");
return 0;
}