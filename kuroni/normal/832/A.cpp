#include <iostream>
#include <cstdio>
using namespace std;

long long n, k, i;

int main()
{
    scanf("%I64d%I64d", &n, &k);
    i = n / k;
    if (i & 1)
        printf("YES");
    else printf("NO");
}