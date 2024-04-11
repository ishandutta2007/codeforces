#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        while (n > 0) {
            int i = n;
            while (i > 0 && a[i] % (i + 1) == 0) i--;
            if (i == 0) break;
            for (int j = i; j < n; j++)
                a[j] = a[j + 1];
            n--;
        }
        printf("%s\n", n == 0? "YES": "NO");
    }
    return 0;
}