#include <bits/stdc++.h>

using namespace std;

const int N = 15;

char board[N][N];

int main() {

    int n;
    scanf("%d", &n);
    if (n == 3) {
        printf("1\n");
        return 0;
    }
    if (n == 4) {
        printf("4\n");
        return 0;
    }

    printf("%I64d\n", 1 + 3 * (n - 3) + (long long)(n - 3) * (n - 4));
    return 0;
}