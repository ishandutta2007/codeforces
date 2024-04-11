#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;

int n, q, i, j, nom, a[100005], save[100005][330], p, k, step;

int main()
{
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d", a + i);
    nom = sqrt(n);
    for (i = n; i >= 1; i--)
        for (j = 1; j <= nom; j++)
        {
            if (a[i] + i + j > n)
                save[i][j] = 1;
            else save[i][j] = save[a[i] + i + j][j] + 1;
        }
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d%d", &p, &k);
        if (k <= nom)
            printf("%d\n", save[p][k]);
        else
        {
            step = 0;
            do
            {
                step++;
                p = a[p] + p + k;
            }
            while (p <= n);
            printf("%d\n", step);
        }
    }
}