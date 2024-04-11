#include<cstdio>
#define MAXN 100000
int n,k,a[MAXN+5],ans;
int main()
{
    int i,j;
    scanf("%d%d",&n,&k);
    for(i=1;i<=k;i++){
        scanf("%d",&a[0]);
        for(j=1;j<=a[0];j++)
            scanf("%d",&a[j]);
        j=1;
        if(a[1]==1)
            for(;a[j]+1==a[j+1];j++);
        ans+=a[0]-j;
    }
    ans=ans*2+k-1;
    printf("%d\n",ans);
}