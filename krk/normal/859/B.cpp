#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main()
{
    scanf("%d", &n);
    int res = 1000000000;
    for (int i = 1; i <= n; i++) {
        int j = n / i + int(n % i > 0);
        res = min(res, 2 * (i + j));
    }
    printf("%d\n", res);
    return 0;
}