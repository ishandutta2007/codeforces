#include <cstdio>
int k[15];
long long ans;

int main () {
    scanf("%d %d %d %d", k + 2, k + 3, k + 5, k + 6);
    while (k[2] && k[5] && k[6]) {
        ans += 256;
        -- k[2];
        -- k[5];
        -- k[6];
    }
    
    while (k[3] && k[2]) {
        ans += 32;
        -- k[3];
        -- k[2];
    }
    
    printf("%lld\n", ans);
}