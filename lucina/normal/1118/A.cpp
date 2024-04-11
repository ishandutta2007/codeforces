#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
long long q,n,a,b;

int main(){
    scanf("%lld",&q);
    while(q--){
        scanf("%lld%lld%lld",&n,&a,&b);
        if(2*a<=b){
            printf("%lld\n",a*n);
        }
        else{
            printf("%lld\n",b*(n/2)+a*(n%2));
        }
    }

}