#include <stdio.h>

#define MAXN 100005
typedef long long lld;

int N; lld A[MAXN];

int main()
{
    int i; lld sum=0;
    scanf("%d",&N);
    for (i=1;i<=N;i++) scanf("%lld",A+i);
    for (i=2;i<=N;i++){
        if (A[i]+sum < A[i-1]){
            sum = A[i-1]-A[i];
        }
        A[i] += sum;
    }
    printf("%lld",sum);
}