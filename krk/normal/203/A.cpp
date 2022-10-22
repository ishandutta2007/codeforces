#include <cstdio>
using namespace std;

int x, t, a, b, da, db;
bool res;

int main()
{
    scanf("%d %d %d %d %d %d", &x, &t, &a, &b, &da, &db);
    res = x == 0;
    for (int k = 0; k < t && !res; k++)
        res = a - k * da == x;
    for (int v = 0; v < t && !res; v++)
        res = b - v * db == x;
    for (int k = 0; k < t && !res; k++)
        for (int v = 0; v < t && !res; v++)
            res = a - k * da + b - v * db == x;
    printf(res? "YES\n": "NO\n");
    return 0;
}