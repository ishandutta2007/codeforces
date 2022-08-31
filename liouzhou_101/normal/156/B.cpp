#include<cstdio>

const int MaxN=100010;

int n,m;
int nA,A[MaxN],nB,B[MaxN],p[MaxN];
int tot,flag[MaxN];

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i)
    {
        scanf("%d",p+i);
        if (p[i]>0)
        {
            ++A[p[i]];
            ++nA;
        }
        else
        {
            ++B[-p[i]];
            ++nB;
        }
    }
    for (int i=1;i<=n;++i)
        if (A[i]+nB-B[i]==m)
        {
            ++tot;
            flag[i]=1;
        }
    if (tot==1)
    {
        for (int i=1;i<=n;++i)
        {
            if (p[i]>0)
            {
                if (flag[p[i]])
                    puts("Truth");
                else
                    puts("Lie");
            }
            else
            {
                if (flag[-p[i]])
                    puts("Lie");
                else
                    puts("Truth");
            }
        }
    }
    else
    {
        for (int i=1;i<=n;++i)
        {
            if (p[i]>0)
            {
                if (flag[p[i]])
                    puts("Not defined");
                else
                    puts("Lie");
            }
            else
            {
                if (flag[-p[i]])
                    puts("Not defined");
                else
                    puts("Truth");
            }
        }
    }
    return 0;
}