#include <cstdio>
using namespace std;

const int Maxn = 100005;
const int mod = 1000000007;

int t, k;
int ways[Maxn];
int a, b;

int main()
{
    scanf("%d %d", &t, &k);
    ways[0] = 1;
    for (int i = 0; i < Maxn; i++) {
        if (i + k < Maxn) ways[i + k] = (ways[i + k] + ways[i]) % mod;
        if (i + 1 < Maxn) ways[i + 1] = (ways[i + 1] + ways[i]) % mod;
    }
    for (int i = 1; i < Maxn; i++)
        ways[i] = (ways[i] + ways[i - 1]) % mod;
    while (t--) {
        scanf("%d %d", &a, &b);
        int res = (ways[b] - ways[a - 1] + mod) % mod;
        printf("%d\n", res);
    }
    return 0;
}