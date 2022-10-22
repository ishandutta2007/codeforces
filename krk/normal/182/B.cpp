#include <cstdio>
using namespace std;

int d;
int n;
int cur = 1;
int res;

int main()
{
    scanf("%d %d", &d, &n);
    while (n--) {
        int a; scanf("%d", &a);
        if (cur > 1) res += d - cur + 1;
        cur = a % d + 1;
    }
    printf("%d\n", res);
    return 0;
}