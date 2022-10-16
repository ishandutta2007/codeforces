#include<stdio.h>
int main(void)
{
    int d,sum,min[35],max[35],i,summin=0,summax=0,dif,ans[35],j=1;
    scanf("%d%d",&d,&sum);
    for(i=1;i<=d;i++) scanf("%d%d",&min[i],&max[i]);
    for(i=1;i<=d;i++)
    {
        ans[i]=min[i];
        summin+=min[i];
        summax+=max[i];
    }
    if(sum<summin||sum>summax) printf("NO");
    else
    {
        dif=sum-summin;
        while(dif>=max[j]-min[j])
        {
            ans[j]=max[j];
            dif-=max[j]-min[j];
            j++;
        }
        ans[j]+=dif;
        printf("YES\n");
        for(i=1;i<=d;i++) printf("%d ",ans[i]);
    }
}