#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAXN 100005

int N,A[MAXN],B[MAXN];

int main()
{
    int i,k=0;
    scanf("%d",&N);
    for (i=1;i<=N;i++) scanf("%d",A+i), B[i] = A[i];
    sort(B+1,B+N+1);
    for (i=1;i<=N;i++) if (A[i] != B[i]) k++;
    puts(k>2?"NO":"YES");
}