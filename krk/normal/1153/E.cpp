#include <bits/stdc++.h>
using namespace std;

const int Inf = 1000000000;

int n;

int Ask(int x1, int y1, int x2, int y2)
{
    printf("? %d %d %d %d\n", x1, y1, x2, y2); fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

int findExactY(int x)
{
    int lef = 1, rig = n - 1;
    while (lef <= rig) {
        int mid = lef + rig >> 1;
        if (Ask(x, 1, x, mid) % 2) rig = mid - 1;
        else lef = mid + 1;
    }
    return rig + 1;
}

int findExactX(int y)
{
    int lef = 1, rig = n - 1;
    while (lef <= rig) {
        int mid = lef + rig >> 1;
        if (Ask(1, y, mid, y) % 2) rig = mid - 1;
        else lef = mid + 1;
    }
    return rig + 1;
}

void Print(int x1, int y1, int x2, int y2)
{
    printf("! %d %d %d %d\n", x1, y1, x2, y2); fflush(stdout);
}

int main()
{
    scanf("%d", &n);
    int mn = Inf, mx = -Inf;
    for (int i = 1; i < n; i++)
        if (Ask(1, 1, i, n) % 2) {
            mn = min(mn, i);
            mx = max(mx, i);
        }
    if (mn != Inf) {
        int y1 = findExactY(mn);
        int y2 = findExactY(mx + 1);
        Print(mn, y1, mx + 1, y2);
        return 0;
    }
    for (int j = 1; j < n; j++)
        if (Ask(1, 1, n, j) % 2) {
            mn = min(mn, j);
            mx = max(mx, j);
        }
    int x1 = findExactX(mn);
    int x2 = findExactX(mx + 1);
    Print(x1, mn, x2, mx + 1);
    return 0;
}