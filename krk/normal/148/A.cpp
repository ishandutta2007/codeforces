#include <cstdio>
using namespace std;

int k, l, m, n, d;
int res;

int main()
{
    scanf("%d %d %d %d %d", &k, &l, &m, &n, &d);
    for (int i = 1; i <= d; i++)
        res += i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0;
    printf("%d\n", res);
    return 0;
}