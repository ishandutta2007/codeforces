#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;
int main(){
    int T; scanf("%d", &T);
    while(T--){
        LL k, x; scanf("%lld%lld", &k, &x);
        printf("%lld\n", (k - 1) * 9 + x);
    }
    return 0;
}