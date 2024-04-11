#include <stdio.h>

const int mod = 1000000007;
int p[1010],cnt[1010];

int main()
{
    int N,ans=0;

    scanf ("%d",&N);
    for (int i=1;i<=N;i++) scanf ("%d",&p[i]);
    for (int i=1;i<=N;i++){
        int c = 2;
        for (int j=p[i];j<i;j++) c = (c + cnt[j]) % mod;
        cnt[i] = c;
        ans = (ans + cnt[i]) % mod;
    }
    printf ("%d\n",ans);

    return 0;
}