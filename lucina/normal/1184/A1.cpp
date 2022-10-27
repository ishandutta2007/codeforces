#include<bits/stdc++.h>
using namespace std;
long long r,c;

int main(){
    scanf("%lld",&r);
    int a=sqrt(r);
    for(int x=1;x<=a;x++){
        c=(r-1LL*x*x-x-1);
        if(c<=0) continue;
        if(c%(2*x)==0){
            return !printf("%d %lld\n",x,c/(2*x));
        }
    }
    printf("NO");
}