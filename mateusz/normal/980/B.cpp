#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, k;
char hotels[5][N];

int main() {

    scanf("%d %d", &n, &k);
    
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= n; j++) {
            hotels[i][j] = '.';
        }
    }
    
    for (int i = 2; i <= 3; i++) {
        for (int j = 2; j <= n / 2; j++) {
            if (k >= 2) {
                hotels[i][j] = hotels[i][n - j + 1] = '#';
                k -= 2;
            }
        }
    }
    
    if (k > 0) {
        for (int i = 2; i <= 3; i++) {
            if (k > 0) {
                hotels[i][n / 2 + 1] = '#';
                k--;
            }
        }
    }
    
    printf("YES\n");
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%c", hotels[i][j]);
        }
        printf("\n");
    }
    
    
    return 0;
}