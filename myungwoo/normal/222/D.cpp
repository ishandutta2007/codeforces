#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAXN 100005

int N,M,A[MAXN],B[MAXN],ans;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
    int i,j,k;
    scanf("%d%d",&N,&M);
    for (i=1;i<=N;i++) scanf("%d",A+i);
    for (i=1;i<=N;i++) scanf("%d",B+i);
    sort(A+1,A+N+1);
    sort(B+1,B+N+1);
    for (i=N,k=1;i>0;i--){
        while (k <= N && A[i]+B[k] < M) k++;
        if (k <= N) k++, ans++;
    }
    printf("%d %d",1,ans);
}