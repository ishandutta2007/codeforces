#include <iostream>
#include <cstdio>
using namespace std;

int n, a, b, ans = 0;

int main()
{
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 1; i <= min(n - 1, a); i++)
        ans = max(ans, min(a / i, b / (n - i)));
    printf("%d", ans);
}