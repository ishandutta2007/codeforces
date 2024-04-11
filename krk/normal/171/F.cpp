#include <cstdio>
using namespace std;

int Rev(int x)
{
    int res = 0;
    while (x) {
        res = 10 * res + x % 10;
        x /= 10;
    }
    return res;
}

bool Prime(int x)
{
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}

int main()
{
    int n;
    scanf("%d", &n);
    int was = 0;
    int i = 2;
    while (was < n) {
        int r = Rev(i);
        if (i != r && Prime(i) && Prime(r)) was++;
        i++;
    }
    i--;
    printf("%d\n", i);
    return 0;
}