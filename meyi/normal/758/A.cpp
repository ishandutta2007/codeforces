#include<cstdio>
#define ri register int
int a[101],m,n,s;
main(){
    scanf("%d",&n);
    for(ri i=0;i!=n;++i)scanf("%d",a+i),m=a[i]>m?a[i]:m;
    while(n--)s+=m-a[n];
    printf("%d",s);
}