#include<cstdio>
#include<cmath>
main(){
    int l,m,n;
    scanf("%d%d%d",&l,&m,&n);
    printf("%lld",(long long)(ceil(1.0*l/n)*ceil(1.0*m/n)));
}