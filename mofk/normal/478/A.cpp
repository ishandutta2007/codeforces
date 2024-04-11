#include<cstdio>
int main(void)
{
int a,b,c,d,e;
scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
int ans=(a+b+c+d+e);
if(ans==0||ans%5!=0) printf("-1");
else printf("%d",ans/5);

}