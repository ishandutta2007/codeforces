#include <stdio.h>

#define MAXN 1000006
#define MOD 1000000007
typedef long long lld;

int N,K,S1[MAXN],S2[MAXN];
lld D[MAXN][3][2];
char A[MAXN];

int main()
{
    int i;
    scanf("%d%d%s",&N,&K,A+1);
    for (i=1;i<=N;i++){
        S1[i] = S1[i-1]+(A[i]=='B');
        S2[i] = S2[i-1]+(A[i]=='W');
    }
    if (A[1] != 'W'){
        if (K == 1) D[1][1][0] = 1;
        else D[1][0][0] = 1;
    }
    if (A[1] != 'B') D[1][0][1] = 1;
    D[0][0][0] = D[0][0][1] = 1;
    for (i=2;i<=N;i++){
        if (A[i] != 'W'){ // PUT BLACK
            D[i][0][0] = (D[i-1][0][0]+D[i-1][0][1])%MOD;

            if (i >= K && S2[i]-S2[i-K] == 0){
                D[i][0][0] = (D[i][0][0]-D[i-K][0][1]+MOD)%MOD;
                D[i][1][0] = (D[i-K][0][1]+D[i-1][1][0]+D[i-1][1][1])%MOD;
            }else{
                D[i][1][0] = (D[i-1][1][0]+D[i-1][1][1])%MOD;
            }

            D[i][2][0] = (D[i-1][2][0]+D[i-1][2][1])%MOD;
        }
        if (A[i] != 'B'){ // PUT WHITE
            D[i][0][1] = (D[i-1][0][0]+D[i-1][0][1])%MOD;

            D[i][1][1] = (D[i-1][1][0]+D[i-1][1][1])%MOD;

            if (i >= K+K && S1[i]-S1[i-K] == 0){
                D[i][1][1] = (D[i][1][1]-D[i-K][1][0]+MOD)%MOD;
                D[i][2][1] = (D[i-K][1][0]+D[i-1][2][0]+D[i-1][2][1])%MOD;
            }else{
                D[i][2][1] = (D[i-1][2][0]+D[i-1][2][1])%MOD;
            }
        }
    }
    printf("%lld",(D[N][2][0]+D[N][2][1])%MOD);
}