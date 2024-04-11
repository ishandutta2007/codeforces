#include <bits/stdc++.h>
using namespace std;

int n, k;

int main()
{
    scanf("%d %d", &n, &k);
    while (k--)
        if (n % 10 == 0) n /= 10;
        else n--;
    printf("%d\n", n);
    return 0;
}