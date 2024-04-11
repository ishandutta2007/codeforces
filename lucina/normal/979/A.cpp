#include<stdio.h>
long long n;
int main(){
    scanf("%lld",&n);
    if(n==0){
        printf("0");
        return 0;
    }
    if(n%2){
        printf("%lld\n",n/2+1);
        return 0;
    }
    else{
        printf("%lld",n+1);
        return 0;
    }
    
    
}