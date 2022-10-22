#include<cstdio>
#include<algorithm>
#define ri register int
int a[101],n;
main(){
    scanf("%d",&n);
    for(ri i=0;i<n;++i)scanf("%d",a+i);
    std::sort(a,a+n);
    n=std::unique(a,a+n)-a;
    if(n>1)printf("%d",a[1]);
    else puts("NO");
}