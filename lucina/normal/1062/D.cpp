#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
long long ans,n;

int main(){
    scanf("%lld",&n);
    for(long long i=2;i<=int(n/2);i++){
        ans+=(((n/i)*(n/i+1))-2);
    }
    printf("%lld\n",ans*2);
}