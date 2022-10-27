#include<bits/stdc++.h>
using namespace std;
long long x,y,z;

int main(){
    scanf("%lld%lld%lld",&x,&y,&z);
    long long cc=(x/z)+(y/z);
    x%=z;y%=z;
    if(x+y>=z){
        cc++;
        printf("%lld %lld",cc,min(z-y,z-x));
    }
    else{
        printf("%lld %lld",cc,0LL);
    }
    }