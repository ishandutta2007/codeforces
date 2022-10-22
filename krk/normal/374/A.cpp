#include <cstdio>
#include <algorithm>
using namespace std;

const int Inf = 1000000000;

int n, m, i, j, a, b;
int res = Inf;

void Test(int r, int c)
{
    int d = abs(r - i);
    if (d % a) return;
    int s1 = d / a;
    d = abs(c - j);
    if (d % b) return;
    int s2 = d / b;
    if ((s1 + s2) % 2) return;
    res = min(res, max(s1, s2));
}

bool Dead()
{
    return i - a < 1 && i + a > n || j - b < 1 && j + b > m;
}

int main()
{
    scanf("%d %d %d %d %d %d", &n, &m, &i, &j, &a, &b);
    Test(1, 1); Test(1, m); Test(n, 1); Test(n, m);
    if (res > 0 && Dead() || res == Inf) printf("Poor Inna and pony!\n");
    else printf("%d\n", res);
    return 0;
}