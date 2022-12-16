#include<bits/stdc++.h>
using namespace std;

const int nmax=50;

int n,m;

bool edge[nmax][nmax];

int main()
{
    scanf("%i%i",&n,&m);

    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%i%i",&u,&v);

        if(u<nmax&&v<nmax)edge[u][v]=1,edge[v][u]=1;
    }

    n=min(n,nmax-1);

    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            for(int k=j+1;k<=n;k++)
                if(edge[i][j]==edge[i][k]&&edge[i][j]==edge[j][k])
                    for(int p=k+1;p<=n;p++)
                        if(edge[i][j]==edge[i][p]&&edge[i][j]==edge[j][p]&&edge[i][j]==edge[k][p])
                            for(int q=p+1;q<=n;q++)
                                if(edge[i][j]==edge[i][q]&&edge[i][j]==edge[j][q]&&edge[i][j]==edge[k][q]&&edge[i][j]==edge[p][q])
                                {
                                    printf("%i %i %i %i %i\n",i,j,k,p,q);
                                    return 0;
                                }
    printf("-1\n");

    return 0;
}