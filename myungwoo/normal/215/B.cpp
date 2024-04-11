#include <stdio.h>
#include <math.h>

int N,M,K,A,B;

int main()
{
    int i,k,r1=0,p1=0,p2=1e9;
    for (scanf("%d",&N);N--;) scanf("%d",&k), r1 = r1>k?r1:k;
    for (scanf("%d",&M);M--;) scanf("%d",&k), p1 = p1>k?p1:k;
    for (scanf("%d",&K);K--;) scanf("%d",&k), p2 = p2<k?p2:k;
    scanf("%d%d",&A,&B);
    printf("%.9lf",r1*sqrt(1./(1+1.*A*p2/B/p1)));
}