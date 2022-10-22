#include <cstdio>
using namespace std;

int n;
int res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        res += a + b + c >= 2;
    }
    printf("%d\n", res);
    return 0;
}