#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];

int deg[nmax];

priority_queue<long long> pq,idle;

void solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=1;i<=n;i++)deg[i]=0;

    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%i%i",&u,&v);

        deg[u]++;
        deg[v]++;
    }

    pq=idle;

    for(int i=1;i<=n;i++)
        for(int j=2;j<=deg[i];j++)
            pq.push(inp[i]);

    long long outp=0;
    for(int i=1;i<=n;i++)outp+=inp[i];

    //cout<<"outp: ";

    printf("%lld",outp);

    for(int k=2;k<n;k++)
    {
        outp+=pq.top();
        pq.pop();

        printf(" %lld",outp);
    }

    printf("\n");
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