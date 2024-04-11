#include <cstdio>
int a[10],b[10];
int main()
{
    int t,n,m,i,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d",&t);
        a[t]=1;
    }
    for(i=0;i<m;i++)
    {
        scanf("%d",&t);
        b[t]=1;
    }
    for(i=1;i<10;i++)
        if(a[i]&&b[i])
        {
            printf("%d\n",i);
            return 0;
        }
    for(i=1;i<10;i++)
        if(a[i] || b[i])
        {
            printf("%d",i);
            if(a[i])
            {
                for(j=1;j<10;j++)
                    if(b[j])
                    {
                        printf("%d\n",j);
                        break;
                    }
            }
            else
            {
                for(j=1;j<10;j++)
                    if(a[j])
                    {
                        printf("%d\n",j);
                        break;
                    }
            }
            return 0;
        }
    return 0;
}