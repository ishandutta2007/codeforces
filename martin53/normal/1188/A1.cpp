#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;

int n;

int deg[nmax];

int main()
{
    scanf("%i",&n);
    int u,v;
    for(int i=1;i<n;i++)
    {
        scanf("%i%i",&u,&v);
        deg[u]++;
        deg[v]++;
    }

    for(int i=1;i<=n;i++)
        if(deg[i]==2)
        {
            printf("NO\n");
            exit(0);
        }
    printf("YES\n");
    return 0;
}