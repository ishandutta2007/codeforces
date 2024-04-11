#include <bits/stdc++.h>
using namespace std;

int a;

int main()
{
    scanf("%d", &a);
    for (int i = 2; i <= a; i++)
        while (a % i == 0) { printf("%d", i); a /= i; }
    printf("\n");
    return 0;
}