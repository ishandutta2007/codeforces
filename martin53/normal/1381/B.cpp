#include<bits/stdc++.h>
using namespace std;
const int nmax=5000;

int n,inp[nmax];

int parent[nmax];

int root(int node)
{
    if(node==parent[node])return node;
    parent[node]=root(parent[node]);
    return parent[node];
}

int seen[nmax];

bitset<nmax> can;

void query()
{
    scanf("%i",&n);
    n=n*2;

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=1;i<=n;i++)parent[i]=i;

    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(inp[i]<inp[j])break;
            else
            {
                parent[root(j)]=root(i);
            }

    for(int i=1;i<=n;i++)seen[i]=0;

    for(int i=1;i<=n;i++)
        seen[root(i)]++;
    /*
    for(int i=1;i<=n;i++)cout<<root(i)<<" ";cout<<endl;

    for(int i=1;i<=n;i++)
        if(seen[i])cout<<seen[i]<<" ";cout<<endl;
    */
    can=can^can;

    can[0]=1;

    for(int i=1;i<=n;i++)
        if(seen[i])can=can|(can<<seen[i]);

    //for(int i=0;i<=n;i++)cout<<can[i]<<" ";cout<<endl;

    if(can[n/2])printf("YES\n");
    else printf("NO\n");
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        query();
    }
    return 0;
}