#include<bits/stdc++.h>
using namespace std;

int a,b,n;
vector<int> g[100005];

void DFS(int u,int fa,int dep)
{
    if(dep&1)a++;else b++;
    for(int p : g[u])
        if(p!=fa)DFS(p,u,dep^1);
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    DFS(1,0,1);
    long long sum=1ll*a*b;
    printf("%lld\n",sum-n+1);
    return 0;
}