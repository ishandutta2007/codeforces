#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
long long n,ans,p;
bool isprime(long long a){
bool t=true;
    for(long long i=2;i*i<=a;i++){
        if(a%i==0){
            t=false;
            break;
            }
    }
    return t;
}
int main(){
    ans=0;
    scanf("%lld",&n);
    if(isprime(n)){
        printf("%d",1);
        return 0;
    }
    if(n%2==0){
        printf("%lld",n/2);
        return 0;
    }
    for(long long j=2;j*j<=n;j++){
        if(isprime(j)&&n%j==0){
            p=j;
        break;
        }
    }
    ans++;
    n-=p;
    ans+=(n/2);
    printf("%lld",ans);

}