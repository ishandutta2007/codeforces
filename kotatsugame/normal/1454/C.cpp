#include<cstdio>
using namespace std;
int T,N;
int pos[2<<17],cnt[2<<17];
main()
{
    scanf("%d",&T);
    for(;T--;)
    {
        scanf("%d",&N);
        for(int i=1;i<=N;i++)cnt[i]=pos[i]=0;
        for(int i=1;i<=N;i++)
        {
            int A;scanf("%d",&A);
            if(pos[A]+1<i)cnt[A]++;
            pos[A]=i;
        }
        int ans=N;
        for(int i=1;i<=N;i++)
        {
            if(pos[i]==0)continue;
            if(pos[i]<N)cnt[i]++;
            if(ans>cnt[i])ans=cnt[i];
        }
        printf("%d\n",ans);
    }
}