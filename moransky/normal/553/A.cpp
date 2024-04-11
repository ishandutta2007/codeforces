#include <cstdio>
#include <iostream>
using namespace std;
const int S = 1005, P = 1e9 + 7;
typedef long long LL;
int K, c[S], s[S], C[S][S];
int ans = 1;
/*
f[i][j]  i 

*/

int main() {
    scanf("%d", &K);
    for (int i = 1; i <= K; i++)
        scanf("%d", c + i), s[i] = s[i - 1] + c[i];

    C[0][0] = 1;
    for (int i = 1; i <= s[K]; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) 
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % P;
    }
    for (int i = 2; i <= K; i++) {
        ans = (LL)ans * C[s[i] - 1][c[i] - 1] % P;
    }
    printf("%d\n", ans);
    return 0;
}