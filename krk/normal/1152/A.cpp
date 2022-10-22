#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[2], b[2];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        int tmp; scanf("%d", &tmp);
        a[tmp % 2]++;
    }
    for (int i = 0; i < m; i++) {
        int tmp; scanf("%d", &tmp);
        b[tmp % 2]++;
    }
    printf("%d\n", min(a[0], b[1]) + min(a[1], b[0]));
    return 0;
}