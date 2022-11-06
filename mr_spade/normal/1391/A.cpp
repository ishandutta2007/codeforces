#include<cstdio>
signed main ()
    {
    int T,n;
        register int i;
        scanf("%d",&T);
        while(T--)
        {
            scanf("%d",&n);
            for(i=1;i<=n;i++)
            printf("%d ",i);
        putchar('\n');
        }
        return 0;
    }