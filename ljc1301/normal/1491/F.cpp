#include <bits/stdc++.h>
using namespace std;
const int maxn=2005;
bool ans[maxn];
int n;
int main()
{
    int T,i,j,res,l,r,mid;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=2;i<=n;i++)
        {
            printf("? 1 %d\n%d\n",i-1,i);
            for(j=1;j<i;j++) printf("%d ",j);
            printf("\n"),fflush(stdout),scanf("%d",&res);
            if(res!=0) break;
        }
        for(j=1;j<i;j++) ans[j]=0; ans[i]=1;
        l=1,r=i-1;
        while(l<r)
        {
            mid=(l+r)>>1;
            printf("? 1 %d\n%d\n",mid-l+1,i);
            for(j=l;j<=mid;j++) printf("%d ",j);
            printf("\n"),fflush(stdout),scanf("%d",&res);
            if(res==0) l=mid+1;
            else r=mid;
        }
        ans[l]=1;
        for(j=i+1;j<=n;j++)
            printf("? 1 1\n%d\n%d\n",i,j),fflush(stdout),scanf("%d",&res),ans[j]=(res!=0);
        for(res=0,i=1;i<=n;i++) res+=!ans[i];
        printf("! %d",res);
        for(i=1;i<=n;i++)
            if(!ans[i])
                printf(" %d",i);
        printf("\n"),fflush(stdout);
    }
    return 0;
}