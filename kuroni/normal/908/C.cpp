#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;

const int N = 1005;

int n, r, a, x[N];
double ans[N];

int main()
{
    scanf("%d%d", &n, &r);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", x + i);
        ans[i] = r;
        for (int j = 1; j < i; j++)
            if (abs(x[i] - x[j]) > 2 * r)
                continue;
            else
                ans[i] = max(ans[i], ans[j] + sqrt(4 * r * r - abs(x[i] - x[j]) * abs(x[i] - x[j])));
        printf("%.8f ", ans[i]);
    }
}