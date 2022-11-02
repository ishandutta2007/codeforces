#include<stdio.h>
int n,m,i,j,k=0;
int main(){
    scanf("%d %d",&n,&m);
    int a[n+1];
    int b[n+1];
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
    }
    if(a[1]==0)
    {
        printf("NO");
    }
    else if(a[m]==1)
    {
        printf("YES");
    }
    else
    {
        if(b[m]==0)
        {
            printf("NO");
        }
        else
        {
            for(j=m+1;j<=n;j++)
            {
                if(a[j]==1 && b[j]==1)
                {
                    k=1;
                }
            }
            if(k==1)
            {
                printf("YES");
            }
            else
            {
                printf("NO");
            }
        }
    }
    return 0;
}