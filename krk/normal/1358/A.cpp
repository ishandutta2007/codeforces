#include <bits/stdc++.h>
using namespace std;

int T;
int n, m;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        printf("%d\n", (n * m - 1) / 2 + 1);
    }
    return 0;
}