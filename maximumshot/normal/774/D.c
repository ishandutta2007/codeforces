#include <stdio.h>

int const N = 1e5 + 5;

int main() {

    int n, l, r;    
    int a[N];
    int b[N];
    int c[N];
    
    scanf("%d %d %d", &n, &l, &r);
    
    for(int i = 1;i <= n;i++) c[i] = 0;
    
    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        if(i >= l && i <= r) c[a[i]]++;
    }
    for(int i = 1;i <= n;i++) {
        scanf("%d", &b[i]);
        if(i >= l && i <= r) {
            c[b[i]]--;
        }
    }
    
    for(int i = 1;i <= n;i++) {
        if(i < l || i > r) {
            if(a[i] != b[i]) {
                printf("LIE");
                return 0;
            }
        }
    }
    
    for(int i = 1;i <= n;i++) {
        if(c[i] != 0) {
            printf("LIE");
            return 0;
        }
    }
    
    printf("TRUTH");
    
    return 0;
}