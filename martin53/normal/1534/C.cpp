#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42,mod=1e9+7;

int n,inp[2][nmax];

int parent[nmax];
int root(int node)
{
    if(parent[node]==node)return node;

    parent[node]=root(parent[node]);

    return parent[node];
}
void solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[0][i]);
    for(int i=1;i<=n;i++)scanf("%i",&inp[1][i]);

    for(int i=1;i<=n;i++)parent[i]=i;

    for(int i=1;i<=n;i++)parent[root(inp[0][i])]=root(inp[1][i]);

    //for(int i=1;i<=n;i++)cout<<i<<" -> "<<root(i)<<endl;

    int outp=1;

    for(int i=1;i<=n;i++)
        if(i==root(i))outp=outp*2%mod;

    printf("%i\n",outp);
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        solve();
    }

    return 0;
}