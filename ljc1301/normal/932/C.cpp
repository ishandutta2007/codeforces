#include <cstdio>
int n,a,b;
int main()
{
    int i,j,k,pre;
    scanf("%d%d%d",&n,&a,&b);
    for(i=0;i*a<=n;i++)
        if((n-i*a)%b==0)
            break;
    if(i*a>n)
    {
        printf("-1\n");
        return 0;
    }
    for(j=0;j<i;j++)
    {
        printf("%d ",(j+1)*a);
        for(k=1;k<a;k++)
            printf("%d ",j*a+k);
    }
    pre=i*a;
    i=(n-i*a)/b;
    for(j=0;j<i;j++)
    {
        printf("%d ",pre+(j+1)*b);
        for(k=1;k<b;k++)
            printf("%d ",pre+j*b+k);
    }
    printf("\n");
    return 0;
}