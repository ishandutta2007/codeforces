#include <bits/stdc++.h>

using namespace std;

// 0 1 0 1
// 2 3 2 3
// 0 1 0 1
// 2 3 2 3

const int maxn = 1005;

int ans[maxn][maxn];

int main() {
    int n; scanf("%d", &n);

    int val = 0;
    for (int i = 0; i < n; i += 2)
        for (int j = 0; j < n; j += 2) {
            ans[i][j] = val;
            ans[i][j+1] = val+1;
            ans[i+1][j] = val+2;
            ans[i+1][j+1] = val+3;
            val += 4;
        }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", ans[i][j]);
        printf("\n");
    }
}