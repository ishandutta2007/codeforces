#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int n, k;
int ans[N][N];
int main() {
    
    scanf("%d %d", &n, &k);
    int x = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < k; j++) {
            ans[i][j] = x;
            x++;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = k; j <= n; j++) {
            ans[i][j] = x;
            x++;
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += ans[i][k];
    }
    printf("%d\n", sum);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}