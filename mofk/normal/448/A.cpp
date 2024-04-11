#include<stdio.h>
int main(void)
{
    int a,b,c,d,e,f,n;
    scanf("%d%d%d",&a,&b,&c);
    scanf("%d%d%d",&d,&e,&f);
    scanf("%d",&n);
    if((a+b+c+4)/5+(d+e+f+9)/10<=n) printf("YES");
    else printf("NO");
}