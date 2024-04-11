#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 105;

int n, d, l;
int a[Maxn], sum;

bool Inc()
{
    for (int i = 0; i < n; i += 2)
        if (a[i] < l) { a[i]++; return true; }
    return false;
}

bool Dec()
{
    for (int i = 1; i < n; i += 2)
        if (a[i] < l) { a[i]++; return true; }
    return false;
}

int main()
{
    scanf("%d %d %d", &n, &d, &l);
    fill(a, a + n, 1);
    sum = n % 2;
    while (sum < d)
        if (Inc()) sum++;
        else break;
    while (sum > d)
        if (Dec()) sum--;
        else break;
    if (sum != d) printf("-1\n");
    else for (int i = 0; i < n; i++)
            printf("%d%c", a[i], i + 1 < n? ' ': '\n');
    return 0;
}