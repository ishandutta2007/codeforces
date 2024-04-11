#include<cstdio>
#include<numeric>
#include<functional>
int const nax = 501;
int f[nax][nax], n, a[nax], dp[nax];
int st[nax], top;

int max (int a, int b) {
    return a > b ? a : b;
}


int main () {
    scanf("%d", &n);
    for (int i = 1 ; i <= n ; ++ i)
        scanf("%d", a + i);


    for (int i = 1 ; i <= n ; ++ i) {
        st[top = 1] = a[i];
        f[i][0] = i;
        for (int j = i + 1 ; j <= n ; ++ j) {
            if (st[top] < a[j]) break;
            st[++ top] = a[j];
            while( top >= 2 && st[top] == st[top - 1]) {
                -- top;
                ++ st[top];
            }

            if (top == 1)
                f[i][st[top] - a[i]] = j;
        }
    }

    std::fill(dp + 1 , dp + 1 + n, -1);

    for (int i = n ; i >= 1 ; -- i)
        for (int v = 0 ; f[i][v] > 0 ; ++ v)
            dp[i] = max(dp[i], f[i][v] - i + dp[f[i][v] + 1]);


    printf("%d\n", n - dp[1]);
}