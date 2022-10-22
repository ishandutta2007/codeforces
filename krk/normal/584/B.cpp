#include <cstdio>
using namespace std;

typedef long long ll;

const int mod = 1000000007;

int Pow(int a, int p)
{
    int res = 1;
    while (p--) {
        res = ll(res) * a % mod;
    }
    return res;
}

int main()
{
    int n; scanf("%d", &n);
    int res = (Pow(3, 3 * n) - Pow(7, n) + mod) % mod;
    printf("%d\n", res);
    return 0;
}