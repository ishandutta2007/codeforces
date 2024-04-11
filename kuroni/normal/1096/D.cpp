#include <iostream>
#include <cstdio>
using namespace std;

const int N = 100005;
const long long INF = 1E18 + 7;
const char SAM[4] = {'h', 'a', 'r', 'd'};

int n, a[N];
long long f[N][4];
char s[N];

int main()
{
    scanf("%d\n%s\n", &n, s + 1);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 4; j++)
            if (s[i] == SAM[j])
                f[i][j] = min(f[i - 1][j] + a[i], (j > 0 ? f[i - 1][j - 1] : INF));
            else
                f[i][j] = f[i - 1][j];
    printf("%lld\n", min(f[n][0], min(f[n][1], min(f[n][2], f[n][3]))));
}