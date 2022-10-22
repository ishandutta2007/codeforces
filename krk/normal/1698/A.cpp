#include <bits/stdc++.h>
using namespace std;

int T;
int n;
int a;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a);
        printf("%d\n", a);
    }
    return 0;
}