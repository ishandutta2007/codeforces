#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42,mod=1e9+7;
int n,m;
vector<int> love[nmax],hate[nmax];
int c;
bool been[nmax];
int comp[nmax];
void dfs(int node)
{
    if(been[node])return;
    comp[node]=c;
    been[node]=1;
    for(auto k:love[node])
        dfs(k);
}
vector<int> gr[nmax];
int colour[nmax];
void dfs_second(int node,int col)
{
    //cout<<node<<" "<<col<<endl;
    if(colour[node]!=-1&&colour[node]!=col)
    {
        cout<<0<<endl;
        exit(0);
    }
    if(colour[node]!=-1)return;
    colour[node]=col;
    for(auto k:gr[node])
        dfs_second(k,!col);
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cin>>n>>m;
int a,b;
for(int i=1;i<=m;i++)
{
    cin>>a>>b>>c;
    if(c==0){hate[a].push_back(b);hate[b].push_back(a);}
    else {love[a].push_back(b);love[b].push_back(a);}
}
c=0;
for(int i=1;i<=n;i++)
    if(been[i]==0)
    {
    c++;
    dfs(i);
    }

//for(int i=1;i<=n;i++)cout<<comp[i]<<" ";cout<<endl;

for(int i=1;i<=n;i++)
    for(auto j:hate[i])
    if(comp[i]==comp[j])
    {
    cout<<0<<endl;
    return 0;
    }
    else gr[comp[i]].push_back(comp[j]),gr[comp[j]].push_back(comp[i]);
memset(been,0,sizeof(been));
memset(colour,-1,sizeof(colour));
int ans=0;
for(int i=1;i<=c;i++)
    if(colour[i]==-1)
    {
    ans++;
    dfs_second(i,0);
    }
int outp=1;
for(int j=1;j<ans;j++)outp=(outp*2)%mod;
cout<<outp<<endl;
return 0;
}