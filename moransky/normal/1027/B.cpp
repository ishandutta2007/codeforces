#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int n, q;
signed main(){
    scanf("%lld%lld", &n, &q);
    for(int i = 1; i <= q; i++){
        int x, y; scanf("%lld%lld", &x, &y);
        int num = 0;
        if(n % 2){
            if((x + y) % 2 == 0){
                if(x % 2) num = (x - 1) * n / 2 + y / 2 + 1;
                else num = (x - 2 + 1) * n / 2 + 1 + y / 2;
            }else{
                if(x % 2) num = n * n / 2 + 1 + (x - 1) * n / 2 + y / 2;
                else num = n * n / 2 + (x - 2 + 1) * n / 2 + 1 + y / 2 + 1;
            }
        }else{
            if((x + y) % 2 == 0){
                if(x % 2) num = (x - 1) * (n / 2) + y / 2 + 1;
                else num = (x - 1) * (n / 2) + y / 2;
            }else{
                if(x % 2) num = n * n / 2 + (x - 1) * (n / 2) + y / 2;
                else num = n * n / 2 + (x - 1) * (n / 2) + y / 2 + 1;
            }
        }
        printf("%lld\n", num);
        
    }
    return 0;
}