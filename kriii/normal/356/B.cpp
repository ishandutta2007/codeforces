#include <stdio.h>

long long N,M,ANS;
char A[1000100],B[1000100];
int P,Q,G,C[1000100][26];

int gcd(int a, int b){return b ? gcd(b,a%b) : a;}

int main()
{
    int i,j;

    scanf ("%lld %lld",&N,&M);
    scanf ("%s %s",A,B);
    for (P=0;A[P];P++);
    for (Q=0;B[Q];Q++);
    G = gcd(P,Q);
    
    for (i=0;i<G;i++) for (j=i;j<P;j+=G) C[i][A[j]-'A']++;
    for (i=0;i<G;i++) for (j=i;j<Q;j+=G) ANS += C[i][B[j]-'A'];
    ANS *= N / (Q / G);
    printf ("%lld\n",N*P-ANS);

    return 0;
}