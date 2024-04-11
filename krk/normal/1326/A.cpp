#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        if (n == 1) printf("-1\n");
        else {
            printf("2");
            for (int i = 0; i < n - 1; i++)
                printf("3");
            printf("\n");
        }
    }
    return 0;
}