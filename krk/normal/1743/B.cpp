#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main()
{
    scanf("%d", &T);
    while (T--) {
        int n; scanf("%d", &n);
        printf("1");
        for (int i = 3; i <= n; i++)
            printf(" %d", i);
        printf(" 2\n");
    }
    return 0;
}