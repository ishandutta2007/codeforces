#include<stdio.h>
long long l,r;
int main(){
    scanf("%lld%lld",&l,&r);
    printf("YES\n");
    while(l<=r){
        printf("%lld %lld\n",l,l+1);
        l+=2;
    }
    
}