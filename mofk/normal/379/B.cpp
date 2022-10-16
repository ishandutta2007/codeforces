#include<stdio.h>
int main(void)
{
    int n,a[301],i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    for(i=1;i<n;i++)
    {
        if(a[i]==0) printf("R");
        else if(a[i]==1) printf("PR");
        else
        {
            for(j=1;j<=a[i];j++) printf("PRL");
            printf("R");
        }
    }
    if(a[n]==1) printf("P");
    else if(a[n]>1)
    {
        for(k=1;k<a[n];k++) printf("PLR");
        printf("P");
    }
}