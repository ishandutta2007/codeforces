#include <cstdio>
using namespace std;

const int Maxn = 105;

int n;
int B[Maxn][Maxn];
int sum;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
            if (i == j || i == n - j - 1 || i == (n - 1) / 2 || j == (n - 1) / 2) sum += B[i][j];
        }
    printf("%d\n", sum);
    return 0;
}