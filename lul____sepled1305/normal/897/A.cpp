#include<stdio.h>
#include <string.h>
int i,j,n,m,x,y;
char c,l;
char catholly[100];
int main(){
    scanf("%d %d",&n,&m);
    scanf("%100s",&catholly);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %c %c",&x,&y,&c,&l);
        for(j=x-1;j<=y-1;j++)
            if(catholly[j]==c)
        {
            catholly[j]=l;
        }
    }
    for(i=0;i<=n-1;i++)
    {
        printf("%c",catholly[i]);
    }
}