#include<bits/stdc++.h>
using namespace std;
long long n,sum,x,w,c;

int main(){
    scanf("%lld",&n);
    x=n;
    while(true){
        sum+=(n>>1);
        w+=((n>>1)<<c);
        n-=(n>>1);
        if(sum==x-1)break;
        c++;
    }
    printf("%lld ",w);
}