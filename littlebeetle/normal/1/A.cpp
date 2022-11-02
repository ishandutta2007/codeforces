#include<cstdio>
long long n,m,a;
int main(){
    scanf("%d%d%d",&n,&m,&a);
    printf("%I64d",((n+a-1)/a)*((m+a-1)/a));
}