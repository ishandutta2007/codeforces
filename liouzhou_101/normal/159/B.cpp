#include<cstdio>
#include<algorithm>

using namespace std;

const int MaxN=1010;

int n,m;
int num[MaxN],tot[MaxN];
int F[MaxN][MaxN],G[MaxN][MaxN];

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i)
    {
        int c,d;
        scanf("%d%d",&c,&d);
        ++num[d];
        ++F[d][c];
    }
    for (int i=1;i<=m;++i)
    {
        int c,d;
        scanf("%d%d",&c,&d);
        ++tot[d];
        ++G[d][c];
    }
    int u=0,v=0;
    for (int i=1;i<=1000;++i)
    {
        u+=min(num[i],tot[i]);
        for (int j=1;j<=1000;++j)
            v+=min(F[i][j],G[i][j]);
    }
    printf("%d %d\n",u,v);
    return 0;
}