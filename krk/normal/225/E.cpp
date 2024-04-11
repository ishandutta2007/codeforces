#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxn = 40;
const int mod = 1000000007;

int p[Maxn] = {2, 3, 5, 7, 13, 17, 19, 31, 61, 89, 107, 127, 521, 607, 1279, 2203, 2281, 3217,
               4253, 4423, 9689, 9941, 11213, 19937, 21701, 23209, 44497, 86243, 110503,
               132049, 216091, 756839, 859433, 1257787, 1398269, 2976221, 3021377, 6972593,
               13466917, 20996011};

int n;
int res;

int toPower(int a, int p)
{
    if (p == 0) return 1;
    int tmp = toPower(a, p / 2);
    tmp = ll(tmp) * ll(tmp) % ll(mod);
    if (p % 2) tmp = ll(tmp) * ll(a) % ll(mod);
    return tmp;
}

int main()
{
    scanf("%d", &n);
    res = toPower(2, p[n - 1] - 1) - 1;
    if (res < 0) res += mod;
    printf("%d\n", res);
    return 0;
}