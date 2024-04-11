#include <cstdio>
using namespace std;

int n;
int res;

int main()
{
    scanf("%d", &n);
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) {
            res += n;
            n /= i;
            i--;
        }
    if (n > 1) res += n;
    res += 1;
    printf("%d\n", res);
    return 0;
}