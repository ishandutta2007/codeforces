#include <stdio.h>

#define MOD 1000000007ll
typedef long long lld;

int N,M;
lld P[2][2],ans,zero;

int gcd(int a,int b){ return b?gcd(b,a%b):a; }

int main()
{
    int i,j,k;
    int a,b,c,d,e,f;
    scanf("%d%d",&N,&M); N++; M++;
    for (i=0;i<2;i++) for (j=0;j<2;j++)
        P[i][j] = (i?N/2:N-N/2)*(j?M/2:M-M/2)%MOD;
    for (a=0;a<2;a++) for (b=0;b<2;b++) for (c=0;c<2;c++) for (d=0;d<2;d++) for (e=0;e<2;e++) for (f=0;f<2;f++){
        k = (c-a)*(f-b)-(e-a)*(d-b);
        if (k < 0) k = -k;
        if (!(k&1))
            ans = (ans+P[a][b]*P[c][d]%MOD*P[e][f]%MOD)%MOD;
    }
    zero = N*M;
    zero = (zero+N*M%MOD*(N*M-1)%MOD*3)%MOD;
    zero = (zero+N*M%MOD*(M-1)*(M-2)%MOD)%MOD;
    zero = (zero+M*N%MOD*(N-1)*(N-2)%MOD)%MOD;
    for (i=1;i<N;i++) for (j=1;j<M;j++){
        zero = (zero+lld(gcd(i,j)-1)*(N-i)%MOD*(M-j)%MOD*12%MOD)%MOD;
    }
    printf("%I64d",(ans-zero+MOD)%MOD);
}