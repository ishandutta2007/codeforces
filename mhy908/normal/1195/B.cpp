#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n, k;
LL power[40];
int main()
{
    scanf("%lld %lld", &n, &k);
    for(LL i=0; ; i++){
        LL hap=i*(i+1)/2;
        if(k==hap-(n-i)){
            printf("%lld", n-i);
            return 0;
        }
    }
}