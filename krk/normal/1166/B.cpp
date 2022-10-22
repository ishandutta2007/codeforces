#include <bits/stdc++.h>
using namespace std;

const string s = "aeiou";

int n;

int main()
{
    scanf("%d", &n);
    for (int i = 5; i <= n; i++) if (n % i == 0) {
        int b = n / i;
        if (b >= 5) {
            for (int u = 0; u < i; u++)
                for (int v = 0; v < b; v++)
                    printf("%c", s[(u + v) % 5]);
            printf("\n");
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}