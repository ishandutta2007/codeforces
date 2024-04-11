#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 200005;

int n, x, y, hor[N], ver[N];
char s[N];

bool chk(int u)
{
    for (int i = 1; i <= n - u + 1; i++)
    {
        int l = i - 1, r = i + u - 1;
        int desx = hor[l] + hor[n] - hor[r], desy = ver[l] + ver[n] - ver[r];
        if (abs(x - desx) + abs(y - desy) <= u && abs(desx + desy + x + y + u) % 2 == 0)
            return true;
    }
    return false;
}

void BS()
{
    int l = 0, r = n, ans = -1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (chk(m))
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    printf("%d", ans);
}

int main()
{
    scanf("%d\n%s\n%d %d", &n, s + 1, &x, &y);
    for (int i = 1; i <= n; i++)
        switch (s[i])
        {
            case 'L':
                hor[i] = hor[i - 1] - 1;
                ver[i] = ver[i - 1];
                break;
            case 'R':
                hor[i] = hor[i - 1] + 1;
                ver[i] = ver[i - 1];
                break;
            case 'U':
                hor[i] = hor[i - 1];
                ver[i] = ver[i - 1] + 1;
                break;
            case 'D':
                hor[i] = hor[i - 1];
                ver[i] = ver[i - 1] - 1;
                break;
        }
    BS();
}