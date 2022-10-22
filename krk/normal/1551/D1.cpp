#include <bits/stdc++.h>
using namespace std;

int T;
int n, m, k;

void Print(bool val)
{
    printf("%s\n", val? "YES": "NO");
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &m, &k);
        if (n % 2 == 0 && m % 2 == 0) Print(k % 2 == 0);
        else if (n % 2 == 1) Print(k >= m / 2 && k % 2 == m / 2 % 2);
        else Print(k <= n * (m - 1) / 2 && k % 2 == n * (m - 1) / 2 % 2);
    }
    return 0;
}