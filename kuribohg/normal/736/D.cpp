#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<bitset>
using namespace std;
int n,m,x[500010],y[500010];
bitset<4010> B[2010];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
        B[x[i]][y[i]]=1;
    }
    for(int i=1;i<=n;i++)
        B[i][i+n]=1;
    for(int i=1;i<=n;i++)
    {
        int o=i;
        for(int j=i;j<=n;j++)
            if(B[j][i]) o=j;
        swap(B[i],B[o]);
        for(int j=i+1;j<=n;j++)
            if(B[j][i]) B[j]^=B[i];
    }
    for(int i=n;i>=1;i--)
        for(int j=i-1;j>=1;j--)
            if(B[j][i]) B[j]^=B[i];
    for(int i=1;i<=m;i++)
    {
        if(B[y[i]][n+x[i]]) puts("NO");
        else puts("YES");
    }
    return 0;
}