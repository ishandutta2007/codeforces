#include <bits/stdc++.h>
using namespace std;

int T;
int n;

void Solve()
{
    for (int a = 2; a * (a + 1) * (a + 2) <= n; a++) if (n % a == 0) {
        int num = n / a;
        for (int b = a + 1; b * (b + 1) <= num; b++) if (num % b == 0) {
            int c = num / b;
            printf("YES\n");
            printf("%d %d %d\n", a, b, c);
            return;
        }
    }
    printf("NO\n");
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        Solve();
    }
    return 0;
}