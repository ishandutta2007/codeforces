#include<stdio.h>
int main(void)
{
    int n,m,i,j,x,y,z,t,br=0,check=0,count=0;
    char c,a[105][105];
    scanf("%d%d %c",&n,&m,&c);
    for(i=1;i<=n;i++) {
        scanf("%s",&a[i]);
        for(j=m-1;j>=0;j--) a[i][j+1]=a[i][j];
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i][j]==c)
            {
                x=i;y=j;br=1;break;
            }
        }
        if(br==1) break;
    }
    br=0;
    for(i=n;i>=1;i--)
    {
        for(j=m;j>=1;j--)
        {
            if(a[i][j]==c)
            {
                z=i;t=j;br=1;break;
            }
        }
        if(br==1) break;
    }
    if(x!=1){
    for(i=y;i<=t;i++)
    {
        for(j=y;j<i;j++) if(a[x-1][j]==a[x-1][i]) check=1;
        if(a[x-1][i]!='.'&&check==0) count+=1;
        check=0;
    }}
    if(z!=n){
    for(i=y;i<=t;i++)
    {
        for(j=y;j<i;j++) if(a[z+1][j]==a[z+1][i]) check=1;
        if(a[z+1][i]!='.'&&check==0) count+=1;
        check=0;
    }}
    if(y!=1){
    for(i=x;i<=z;i++)
    {
        for(j=x;j<i;j++) if(a[j][y-1]==a[i][y-1]) check=1;
        if(a[i][y-1]!='.'&&check==0) count+=1;
        check=0;
    }}
    if(t!=m){
    for(i=x;i<=z;i++)
    {
        for(j=x;j<i;j++) if(a[j][t+1]==a[i][t+1]) check=1;
        if(a[i][t+1]!='.'&&check==0) count+=1;
        check=0;
    }}
    printf("%d",count);
    return 0;
}