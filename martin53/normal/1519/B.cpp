#include<bits/stdc++.h>
using namespace std;

const int nmax=1e2+5,kmax=1e4+5;

bitset<kmax> seen[nmax][nmax];

void dfs(int x,int y,int k)
{
    if(seen[x][y][k])return;

    seen[x][y][k]=1;

    if(x+1<nmax&&k+y<kmax)dfs(x+1,y,k+y);
    if(y+1<nmax&&k+x<kmax)dfs(x,y+1,k+x);
}
int main()
{
    dfs(1,1,0);

    int t;
    scanf("%i",&t);

    for(int i=1;i<=t;i++)
    {
        int x,y,k;

        scanf("%i%i%i",&x,&y,&k);

        if(seen[x][y][k])printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}