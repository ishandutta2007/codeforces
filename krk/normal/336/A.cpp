#include <cstdio>
#include <algorithm>
using namespace std;

int x, y;

int main()
{
    scanf("%d %d", &x, &y); int c = abs(x) + abs(y);
    if (x < 0)
        if (y < 0) printf("%d %d %d %d\n", -c, 0, 0, -c);
        else printf("%d %d %d %d\n", -c, 0, 0, c);
    else if (y < 0) printf("%d %d %d %d\n", 0, -c, c, 0);
         else printf("%d %d %d %d\n", 0, c, c, 0);
    return 0;
}