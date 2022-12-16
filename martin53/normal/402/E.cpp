#include<bits/stdc++.h>
using namespace std;
const int nmax=2e3+42;
int n,a[nmax][nmax];
bool been[nmax];
int order[nmax];
int pos=0;
void dfs(int node)
{
    if(been[node])return;
    been[node]=1;
    for(int i=1;i<=n;i++)
        if(a[node][i])dfs(i);

    pos++;
    order[pos]=node;
}
void dfs_back(int node)
{
    if(been[node])return;
    been[node]=1;
    for(int i=1;i<=n;i++)
        if(a[i][node])dfs_back(i);
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cin>>n;
for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
        cin>>a[i][j];

dfs(1);

if(pos!=n)
{
cout<<"NO"<<endl;
return 0;
}
memset(been,0,sizeof(been));
dfs_back(order[n]);

for(int i=1;i<=n;i++)
    if(been[i]==0)
    {
    cout<<"NO"<<endl;
    return 0;
    }

cout<<"YES"<<endl;
return 0;
}