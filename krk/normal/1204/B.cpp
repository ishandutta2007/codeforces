#include <bits/stdc++.h>
using namespace std;

int n, l, r;
int sum1, sum2;

int main()
{
    scanf("%d %d %d", &n, &l, &r);
    for (int i = 0; i < l; i++)
        sum1 += (1 << i);
    sum1 += n - l;
    for (int i = 0; i < r; i++)
        sum2 += (1 << i);
    sum2 += (n - r) * (1 << r - 1);
    printf("%d %d\n", sum1, sum2);
    return 0;
}