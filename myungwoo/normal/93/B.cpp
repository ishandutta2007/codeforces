#include <stdio.h>

int N,W,M;
double V[51],from[51][51],each;

int main()
{
    int i,j,k;
    double left;
    scanf("%d%d%d",&N,&W,&M);
    each = double(W)*N/M;
    for (i=1;i<=N;i++){
        left = W;
        k = 0;
        for (j=1;j<=M;j++){
            if (left < 1e-8) break;
            if (each-V[j] > 1e-8){
                if (each-V[j]-left > 1e-8){
                    V[j] += left;
                    from[j][i] = left;
                    left = 0;
                    k++;
                    break;
                }
                else from[j][i] += each-V[j], left -= each-V[j], V[j] = each, k++;
            }
        }
        if (k > 2){ puts("NO"); return 0; }
    }
    puts("YES");
    for (i=1;i<=M;i++){
        k = 0;
        for (j=1;j<=N;j++) if (from[i][j] > 0){
            printf("%d %.6lf ",j,from[i][j]);
        }
        puts("");
    }
}