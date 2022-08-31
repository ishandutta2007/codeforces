#include<cstdio>
main(){
 int a,b,c,d,e,f;
 scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
 printf("%s\n",(a+d==1&&b+e==1&&c+f==1)?"NO":"YES");
}