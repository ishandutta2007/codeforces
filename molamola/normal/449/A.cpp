#include<stdio.h>

int main(){
    long long a, b, k;
    scanf("%lld%lld%lld",&a,&b,&k);
    if(a+b-2 < k)return printf("-1") & 0;
    long long ans = 0;
    for(int i=1;i*i<=a;i++){
        if(k+2-i > 0 && ans < (a/i) * (b/(k+2-i)))ans = (a/i) * (b/(k+2-i));
    }
    int c=0;
    for(int i=1;i*i<=a;i++){
        int u = (int)a/i;
        if(k+2-u > 0 && ans < i * (b/(k+2-u)))ans = i * (b/(k+2-u));
        if(k+2-u <= 0)c=1;
    }
    if(c)if(ans < a/(k+1) * b)ans = a/(k+1)*b;
    printf("%lld",ans);
    return 0;
}