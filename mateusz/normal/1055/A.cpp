#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, s, A[N], B[N];

int main() {

    scanf("%d %d", &n, &s);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
    }
    
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &B[i]);
    }
    
    if (A[1] == 0) {
        printf("NO\n");
        return 0;
    }
    
    if (A[s] == 1) {
        printf("YES\n");
        return 0;
    }
    
    if (B[s] == 0) {
        printf("NO\n");
        return 0;
    }
    
    for (int i = s + 1; i <= n; i++) {
        if (A[i] == 1 && B[i] == 1) {
            printf("YES\n");
            return 0;
        }
    }

    printf("NO\n");
    
    return 0;
}