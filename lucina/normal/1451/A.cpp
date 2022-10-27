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
    int T;
    cin >> T;
    while (T -- )
    {
    ans=0;
    scanf("%lld",&n);
    if (n == 1) {
        printf("0\n");
        continue;
    }
    if (isprime(n)) {
        ++ ans;
        n --;
    }
    if (n == 1) {
        printf("%d\n", ans);
        continue;
    }
    if (n % 2 == 0) {
        ans ++;
        ans += (n != 2);
        printf("%d\n", ans);
        continue;
    }

    printf("%d\n", ans + 3);
 }
}