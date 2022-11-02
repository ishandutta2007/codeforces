#include <stdio.h>

#define MOD 1000000007
typedef long long lld;

int N,A[10],D[11][101],ans;
lld C[101][101];

int proc(int len)
{
    int i,j,k;
    for (i=0;i<11;i++) for (j=0;j<=len;j++) D[i][j] = 0;
    for (i=A[0];i<len;i++) D[1][i] = C[len-1][i];
    for (i=1;i<10;i++) for (j=0;j<=len;j++) if (D[i][j]){
        for (k=A[i];j+k<=len;k++){
            D[i+1][j+k] = (D[i+1][j+k]+D[i][j]*C[len-j][k])%MOD;
        }
    }
    return D[10][len];
}

int main()
{
    int i,j;
    scanf("%d",&N);
    C[0][0] = 1;
    for (i=1;i<=N;i++) for (j=0;j<=i;j++){
        C[i][j] = (C[i-1][j]+(j?C[i-1][j-1]:0))%MOD;
    }
    for (i=0;i<10;i++) scanf("%d",A+i);
    for (i=1;i<=N;i++){
        ans = (ans+proc(i))%MOD;
    }
    printf("%d",ans);
}