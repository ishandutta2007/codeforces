#include <bits/stdc++.h>
using namespace std;

int k;

int main()
{
    scanf("%d", &k);
    int p = 0;
    while ((1 << p) <= k) p++;
    int both = ((1 << p) | k);
    printf("3 3\n");
    printf("%d %d %d\n", both, (1 << p), 0);
    printf("%d %d %d\n", k, both, k);
    printf("%d %d %d\n", 0, 0, k);
    return 0;
}