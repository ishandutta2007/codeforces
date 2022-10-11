#include <iostream>
#include <cstdio>
#define ll I64
using namespace std;

int n, m;
long long k;

int main()
{
    scanf("%d%d%lld", &n, &m, &k);
    if (k < n)
    {
        printf("%lld 1", k + 1);
        return 0;
    }
    else
    {
        k -= n;
        int r = k / (m - 1), c = k % (m - 1);
        printf("%d %d\n", n - r, (r & 1 ? m - c : c + 2));
    }
}