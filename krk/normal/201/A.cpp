#include <cstdio>
using namespace std;

int x;
int n;

bool Check(int a, int b, int c)
{
    for (int i = 0; i <= a && 4 * i <= x; i++)
        for (int j = 0; j <= b && 4 * i + 2 * j <= x; j++)
            if (x - 4 * i - 2 * j <= c) return true;
    return false;
}

bool Pos11(int d)
{
    return Check(((d - 1) * (d - 1) + 1) / 2, (d - 1) / 2 * 2, 1);
}

bool Pos12(int d)
{
    return Check((d - 1) * (d - 1) / 2, d / 2 * 2, 0);
}

bool Pos2(int d)
{
    return Check((d * d + 1) / 2, 0, 0);
}

int main()
{
    scanf("%d", &x);
    for (n = 1; ; n++)
        if (n % 2 && (Pos11((n + 1) / 2) || Pos12((n + 1) / 2)) ||
            n % 2 == 0 && Pos2(n / 2 - 1)) break;
    printf("%d\n", n);
    return 0;
}