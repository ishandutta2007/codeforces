#include<stdio.h>
long long n,a,b,c;
int main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld%lld",&a,&b,&c);
        if(c%2==0)
        printf("%lld\n",(c/2)*(a-b));
        else{
            printf("%lld\n",((c-1)/2)*(a-b)+a);
        }
    }
}