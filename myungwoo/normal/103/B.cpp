#include <stdio.h>

int N,M,cnt;
bool w[101][101],v[101];

void dfs(int n)
{
    int i;
    v[n] = 1; cnt++;
    for (i=1;i<=N;i++) if (w[n][i] && !v[i]) dfs(i);
}

int main()
{
    int i,j,k;
    scanf("%d%d",&N,&M);
    if (N != M){ puts("NO"); return 0; }
    for (i=1;i<=M;i++){
        scanf("%d%d",&j,&k);
        w[j][k] = w[k][j] = 1;
    }
    dfs(1);
    puts(cnt==N?"FHTAGN!":"NO");
}