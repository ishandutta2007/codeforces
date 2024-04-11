#include <bits/stdc++.h>
using namespace std;

int T;
int m;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &m);
        int p = 1;
        while (p <= m / 10) p *= 10;
        printf("%d\n", m - p);
    }
    return 0;
}