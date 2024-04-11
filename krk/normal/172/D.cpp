#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxn = 10000005;

int delta[Maxn];
int a, n;
ll res;

int main()
{
    for (int i = 1; i * i < Maxn; i++)
        for (int j = 1; j * i * i < Maxn; j++) delta[j * i * i] = j;
    scanf("%d %d", &a, &n);
    for (int i = a; i < a + n; i++) res += delta[i];
    printf("%I64d\n", res);
    return 0;
}