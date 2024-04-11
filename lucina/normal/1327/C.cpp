#include<cstdio>
/// switch back compiler 64 bit is rather slow than expected
int n, m, k;

int main () {
    scanf("%d %d %d", &n, &m, &k);

    printf("%d\n", n + m - 2 + n * m );

    for (int i = 1 ; i < n; ++ i) {
        putchar('U');
    }

    for (int i = 1 ; i < m ; ++ i) {
        putchar('L');
    }

    for (int i = 1 ; i <= n ; ++ i) {
        for (int j = 1 ; j < m ; ++ j) {
            putchar( (i & 1) ? 'R' : 'L');
        }
        putchar('D');
    }
}