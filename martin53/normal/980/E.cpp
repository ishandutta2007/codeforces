#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
int k,n;
vector<int> adj[nmax];
int up[nmax][21];
bool take[nmax];
void dfs(int node,int parent)
{
    up[node][0]=parent;
    for(int j=1;j<21;j++)
        up[node][j]=up[up[node][j-1]][j-1];
    /*
    for(int j=0;j<21;j++)
        cout<<node<<" "<<j<<" -> "<<up[node][j]<<endl;
    */
    for(auto k:adj[node])
        if(k!=parent)
        dfs(k,node);
}
int main()
{
scanf("%i%i",&n,&k);
int x,y;
for(int i=1;i<n;i++)
{
    scanf("%i%i",&x,&y);
    adj[x].push_back(y);
    adj[y].push_back(x);
}
k=n-k;
k--;
take[n]=1;
dfs(n,n);

for(int i=n-1;i>=1;i--)
    if(take[i]==0)
    {
        int req=1,where=i;
        for(int j=20;j>=0;j--)
            if(take[up[where][j]]==0)
            {
                req+=(1<<j);
                where=up[where][j];
            }
            if(req<=k)
            {
                k=k-req;
                where=i;
                while(take[where]==0)
                {
                    take[where]=1;
                    where=up[where][0];
                }
            }
        //cout<<"i= "<<i<<" "<<k<<" "<<req<<endl;
    }
for(int i=1;i<=n;i++)
    if(take[i]==0)
    printf("%i ",i);

return 0;
}