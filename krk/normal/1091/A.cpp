#include <bits/stdc++.h>
using namespace std;

int y, b, r;

int main()
{
    scanf("%d %d %d", &y, &b, &r);
    int res = min(y, min(b - 1, r - 2));
    printf("%d\n", 3 * res + 3);
    return 0;
}