#include <iostream>
using namespace std;

int n, a, m;
double x = 1;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= 2 * n; i++)
    {
        scanf("%d", &a);
        if (a == 1)
        {
            printf("-1");
            return 0;
        }
        else
            x *= 1.0 * a / (a - 1);
    }
    printf("%.16f", (x - 1) * m);
}