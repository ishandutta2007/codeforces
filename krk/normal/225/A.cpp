#include <cstdio>
using namespace std;

int n, x;

int main()
{
    scanf("%d %d", &n, &x);
    int i;
    for (i = 0; i < n; i++) {
        int a, b; scanf("%d %d", &a, &b);
        if (x == a || x == 7 - a || x == b || x == 7 - b) break;
        x = 7 - x;
    }
    printf(i == n? "YES\n": "NO\n");
    return 0;
}