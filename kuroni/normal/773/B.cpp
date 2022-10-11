#include <iostream>
#include <stdio.h>
using namespace std;

int n, v[5], p[5], nom[5], i, j, tmp[5], total[5], ans;
bool correct[5];

int score(int cur, int tot)
{
    if (32 * cur <= tot)
        return 12;
    else if (16 * cur <= tot)
        return 10;
    else if (8 * cur <= tot)
        return 8;
    else if (4 * cur <= tot)
        return 6;
    else if (2 * cur <= tot)
        return 4;
    else return 2;
}

int main()
{
    fill(total, total + 4, 0);
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 5; j++)
        {
            scanf("%d", tmp + j);
            if (tmp[j] != -1)
                total[j]++;
            if (i == 0)
                v[j] = tmp[j];
            else if (i == 1)
                p[j] = tmp[j];
        }
    }
    for (i = 0; i < 5; i++)
    {
        if (p[i] == -1)
        {
            correct[i] = 0;
            if (v[i] == -1)
                nom[i] = 0;
            else nom[i] = 250 - v[i];
        }
        else
        {
            if (v[i] == -1)
            {
                correct[i] = 0;
                nom[i] = p[i] - 250;
            }
            else
            {
                nom[i] = p[i] - v[i];
                if (nom[i] < 0)
                    correct[i] = 1;
                else correct[i] = 0;
            }
        }
    }
    for (i = 0; i <= 3840; i++)
    {
        ans = 0;
        for (j = 0; j < 5; j++)
            ans += nom[j] * score(total[j] + correct[j] * i, n + i);
        if (ans > 0)
        {
            printf("%d", i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}