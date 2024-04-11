#include <stdio.h>

int N;
long long A[101],ans;

int main()
{
    int i;
    scanf("%d",&N);
    for (i=1;i<=N;i++) scanf("%lld",A+i);
    for (i=1;i<=N;i++) if (A[i] > 1){
        ans += (i)*(A[i]-1)+1;
    }else ans++;
    printf("%lld",ans);
}