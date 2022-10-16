#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;
int main(){
    int T; scanf("%d", &T);
    while(T--){
        LL s, a, b, c;
        scanf("%lld%lld%lld%lld", &s, &a, &b, &c);
        LL buy = s / c, free = buy / a * b;
        printf("%lld\n", buy + free);
    }
    return 0;
}