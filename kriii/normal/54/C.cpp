#include <stdio.h> 
#include <math.h> 
 
int N,K; 
double P[1111],D[1111][1111],S; 
__int64 A,B; 
 
__int64 count(__int64 s) 
{ 
    __int64 p = 1, c = 0; 
 
    while (s >= p){ 
        if (s >= 2 * p) c += p; 
        else{c += s - p + 1; break;} 
        p *= 10; 
    } 
 
    return c; 
} 
 
int main() 
{ 
    int i,j; 
 
    scanf ("%d",&N); 
    for (i=1;i<=N;i++){ 
        scanf ("%I64d %I64d",&A,&B); 
        P[i] = double(count(B) - count(A-1)) / double(B - A + 1); 
    } 
    scanf ("%d",&K); K = ceil(N * (double)(double(K) / 100)); 
 
    D[0][0] = 1.0; 
    for (i=1;i<=N;i++){ 
        D[i][0] = D[i-1][0] * (1 - P[i]); 
        for (j=1;j<=i;j++) D[i][j] = D[i-1][j-1] * P[i] + D[i-1][j] * (1 - P[i]); 
    } 
 
    for (j=K;j<=N;j++) S += D[N][j]; 
    printf ("%.12lf",S); 
 
    return 0; 
}