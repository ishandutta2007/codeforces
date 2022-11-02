#include<stdio.h>
int i,n,k;
int main(){
    scanf("%d %d",&n,&k);
    int am[n+1];
    am[0]=0;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&am[i]);
        if(am[i]<=k)
        {
            am[0]++;
        }
        else
        {
            am[0]+=2;
        }
    }
    printf("%d",am[0]);
}