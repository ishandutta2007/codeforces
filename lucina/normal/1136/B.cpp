#include<stdio.h>

int main(){
    int n,k,s;
    scanf("%d%d",&n,&k);
    s+=(2*n+1);
    s+=(n-1);
    s+=(n-k>=k-1?k-1:n-k);
    printf("%d\n",s);
}