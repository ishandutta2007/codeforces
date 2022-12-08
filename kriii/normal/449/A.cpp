#include <stdio.h>

int N,M,K;

long long ans()
{
    K += 2;
    if (N + M < K) return -1;

    long long ans = 0;
    for (int i=1;i<=N;i=N/(N/i)+1){
        int a = i, b = N / (N / i);
        if (i >= K) break;
        if (b >= K) b = K-1;
        int c = K - b, d = K - a, j;
        if (c > M){
            if (d > M) continue;
            j = M;
        }
        else j = c;
        if (j <= M){
            long long a = (N / i);
            long long b = (M / j);
            if (ans < a * b)
                ans = a * b;
        }
    }
    return ans;
}

int main()
{
    scanf ("%d %d %d",&N,&M,&K);
    printf ("%lld\n",ans());

    return 0;
}