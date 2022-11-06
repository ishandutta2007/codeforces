#include <bits/stdc++.h>

using namespace std;
const int N = 1000005;
int n, k, p, np, x;
int main() {
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &x);
        if(x % 2)
            np++;
        else p++;
    }
    
if(n == k){
printf(np % 2? "Stannis\n": "Daenerys\n"); return 0;}
    if(2 * min(np, p) > n - k) {
        printf((n - k) % 2? "Stannis\n" : "Daenerys\n");
    } else {
        if(np <= p || (np - (n - k - p)) % 2 == 0) {
            printf("Daenerys\n");
        } else {
            printf("Stannis\n");
        }
    }
    return 0;
}