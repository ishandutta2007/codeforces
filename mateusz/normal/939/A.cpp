#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, f[N];

int main() {
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &f[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        if (i == f[f[f[i]]]) {
            printf("YES\n");
            return 0;
        }
    }
    
    printf("NO\n");
    
    return 0;
}