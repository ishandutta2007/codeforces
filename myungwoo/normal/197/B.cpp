#include <stdio.h>

#define abs(n) ((n)<0?-(n):(n))

int N,M,A[101],B[101];

int gcd(int a,int b){ return !b?a:gcd(b,a%b); }

int main()
{
    int i,a,b,g;
    scanf("%d%d",&N,&M);
    for (i=0;i<=N;i++) scanf("%d",A+i);
    for (i=0;i<=M;i++) scanf("%d",B+i);
    if (N > M){
        if (A[0]*B[0] > 0) puts("Infinity");
        else if (A[0]*B[0] < 0) puts("-Infinity");
    }
    else if (N < M){
        puts("0/1");
    }else{
        a = A[0], b = B[0];
        g = gcd(abs(a),abs(b));
        a /= g, b /= g;
        if (a*b < 0) printf("-");
        printf("%d/%d",abs(a),abs(b));
    }
}