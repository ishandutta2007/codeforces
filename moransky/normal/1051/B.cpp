#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;
LL l, r, tot;
int main(){
    cin >> l >> r;
    if(l == r) puts("NO");
    else{
        puts("YES");
        tot = (r - l + 1) >> 1;
        for(LL i = l, j = 0; j < tot; j++, i+=2){
            printf("%lld %lld\n", i, i + 1);
        }
    }
    
    return 0;
}