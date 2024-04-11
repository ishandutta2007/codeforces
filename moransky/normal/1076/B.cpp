#include <iostream>
#include <cstdio>
typedef long long LL;
using namespace std;
LL n;
LL findMin(LL n){
    for(LL i = 2; i * i <= n; i++)
        if(n % i == 0) return i;
    return n;
}
int main(){
    cin >> n;
    if(n & 1 && (findMin(n) == n)) puts("1");
    else if(n & 1)  printf("%lld\n", (n - findMin(n)) / 2 + 1);
    else printf("%lld\n", n / 2);
    return 0;
}